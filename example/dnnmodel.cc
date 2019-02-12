#include "tensorflow/cc/client/client_session.h"
#include "tensorflow/cc/ops/standard_ops.h"
#include "tensorflow/cc/framework/gradients.h"

using namespace tensorflow;
using namespace tensorflow::ops;


void GradientsTest(){
    tensorflow::Scope scope = tensorflow::Scope::NewRootScope();

    // Construct forward graph.
    auto x = Const(scope, {{1.0, 2.0}, {3.0, 4.0}});
    auto y = Const(scope, {{1.0, 0.0}, {0.0, 1.0}});
    auto z = MatMul(scope, x, y);
    TF_CHECK_OK(scope.status());
    CHECK_NOTNULL(z.node());


    // Call AddSymbolicGradients.
    auto dz = Const(scope, {{1.0, 1.0}, {1.0, 1.0}});
    std::vector<Output> grad_outputs;
    TF_CHECK_OK(AddSymbolicGradients(scope, {z}, {x, y}, {dz}, &grad_outputs));
    return;
}

void GradientsTest1()
{
    Scope root = Scope::NewRootScope();

    auto W = Variable(root.WithOpName("W"), {3,1}, DT_DOUBLE);

    auto x = Placeholder(root.WithOpName("x"), DT_DOUBLE);
    auto y = Placeholder(root.WithOpName("y"), DT_DOUBLE);

    auto m = MatMul(root, x, W);
    auto dd = Subtract(root, y, m);

    //compute loss
    auto loss = MatMul(root, MatMul(root, dd, dd, MatMul::TransposeA(true)), {0.5});
    double learning_rate = 0.1;


    std::vector<Output> grad_outputs;
    TF_CHECK_OK(AddSymbolicGradients(root, {loss}, {m}, &grad_outputs));
    //Compute gradients with formula
    //  auto grad_W = Subtract(root, MatMul(root, MatMul(root, x, x, MatMul::TransposeA(true)), W), MatMul(root, x, y,  MatMul::TransposeA(true)));

    auto apply_grad_W = ApplyGradientDescent(root, W, learning_rate,  grad_outputs[0]);

    //Initialize variables
    auto init_W = Assign(root, W, {{1.0},{1.0},{1.0}});

    std::vector<Tensor> outputs;
    ClientSession session(root);

    //Run variable initializers
    session.Run({init_W}, &outputs);

    for(unsigned int i=0;i<200;++i)
    {
        TF_CHECK_OK(session.Run( { {x,{{1.0,-1.0,3.0}, {1.0,2.0,1.0}, {1.0,-2.0,-2.0}, {1.0,0.0,2.0}}}, {y,{{14.0}, {15.0}, {-9.0}, {13.0}}} } , {loss, apply_grad_W}, &outputs));
        std::cout << std::string("loss: ") << outputs[0].scalar<double>() << std::endl << std::string("weights: ")<< outputs[1].matrix<double>() << std::endl;
    }
}

void dnnmode()
{
    // benchmark
    auto benchmark_w = 2.0, benchmark_b = 0.5;

    // data
    auto nof_samples = 100;
    struct Sample
    {
        float sample;
        float label;
    };
    std::vector<struct Sample> dataset;
    std::srand((unsigned)std::time(NULL));
    for (int i = 0; i < nof_samples; i++)
    {
        float sample = std::rand() / float(RAND_MAX) - 0.5;
        float label = benchmark_w * sample + benchmark_b + std::rand() / float(RAND_MAX) * 0.01;
        dataset.push_back({sample, label});
    }

    // model
    tensorflow::Scope root = tensorflow::Scope::NewRootScope();
    auto x = tensorflow::ops::Placeholder(root, tensorflow::DataType::DT_FLOAT);
    auto y = tensorflow::ops::Placeholder(root, tensorflow::DataType::DT_FLOAT);
    auto w = tensorflow::ops::Variable(root, {1, 1}, tensorflow::DataType::DT_FLOAT);
    auto assign_w = tensorflow::ops::Assign(root, w, tensorflow::ops::RandomNormal(root, {1, 1}, tensorflow::DataType::DT_FLOAT));
    auto b = tensorflow::ops::Variable(root, {1, 1}, tensorflow::DataType::DT_FLOAT);
    auto assign_b = tensorflow::ops::Assign(root, b, {{0.0f}});
    auto y_ = tensorflow::ops::Add(root, tensorflow::ops::MatMul(root, x, w), b);
    auto loss = tensorflow::ops::L2Loss(root, tensorflow::ops::Sub(root, y_, y));
    std::vector<tensorflow::Output> grad_outputs;
    TF_CHECK_OK(AddSymbolicGradients(root, {loss}, {w, b}, &grad_outputs));
    auto learn_rate = tensorflow::ops::Const(root, 0.01f, {});
    auto apply_w = tensorflow::ops::ApplyGradientDescent(root, w, learn_rate, {grad_outputs[0]});
    auto apply_b = tensorflow::ops::ApplyGradientDescent(root, b, learn_rate, {grad_outputs[1]});

    // train
    tensorflow::ClientSession sess(root);
    sess.Run({assign_w, assign_b}, nullptr);
    std::vector<tensorflow::Tensor> outputs;
    timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int epoch = 1; epoch <= 64; epoch++)
    {
        std::random_shuffle(dataset.begin(), dataset.end());
        for (int i = 0; i < nof_samples; i++)
        {
            TF_CHECK_OK(sess.Run({{x, {{dataset[i].sample}}}, {y, {{dataset[i].label}}}}, {w, b, loss, apply_w, apply_b}, &outputs));
        }
        LOG(INFO) << "epoch " << epoch << ": w=" << outputs[0].matrix<float>() << " b=" << outputs[1].matrix<float>() << " loss=" << outputs[2].scalar<float>();
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    LOG(INFO) << "elapsed time： " << t1.tv_sec - t0.tv_sec + (t1.tv_nsec - t0.tv_nsec) * 1.0 / 1000000000 << "s";

}

int main()
{
    GradientsTest1();
//    dnnmode();
    return 0;
}

