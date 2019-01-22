//
// Created by mac on 2019/1/5.
//

#include "tensorflow/cc/framework/gradients.h"
#include "tensorflow/cc/client/client_session.h"
#include "tensorflow/cc/ops/standard_ops.h"
#include "tensorflow/core/framework/tensor.h"
using namespace tensorflow;
using namespace tensorflow::ops;

int SessionTest()
{
    auto root = Scope::NewRootScope();
    auto p_session = new ClientSession(root);
    delete p_session;
    return 0;
}

int ConstTest()
{
    auto root = Scope::NewRootScope();
    auto w = Const(root, 2, {});
    auto p_session = new ClientSession(root);
    std::vector<Tensor> outputs;
    p_session->Run({w}, &outputs);
    LOG(INFO) << "w = " << outputs[0].scalar<int>();
    delete p_session;
    return 0;
}


int VariableTest()
{
    auto root = Scope::NewRootScope();
    auto x = Variable(root, {}, DataType::DT_INT32);
    auto assign_x = Assign(root, x, 3); // initializer for x
    auto y = Variable(root, {2, 3}, DataType::DT_FLOAT);
    auto assign_y = Assign(root, y, RandomNormal(root, {2, 3}, DataType::DT_FLOAT)); // initializer for y
    auto p_session = new ClientSession(root);
    p_session->Run({assign_x, assign_y}, nullptr); // initialize
    std::vector<Tensor> outputs;
    p_session->Run({x, y}, &outputs);
    LOG(INFO) << "x = " << outputs[0].scalar<int>();
    LOG(INFO) << "y = " << outputs[1].matrix<float>();
    delete p_session;
    return 0;
}

int MatTest()
{
    auto root = Scope::NewRootScope();
    auto x = Variable(root, {5, 2}, DataType::DT_FLOAT);
    auto assign_x = Assign(root, x, RandomNormal(root, {5, 2}, DataType::DT_FLOAT));
    auto y = Variable(root, {2, 3}, DataType::DT_FLOAT);
    auto assign_y = Assign(root, y, RandomNormal(root, {2, 3}, DataType::DT_FLOAT));
    auto xy = MatMul(root, x, y);
    auto z = Const(root, 2.f, {5, 3});
    auto xyz = Add(root, xy, z);
    auto p_session = new ClientSession(root);
    p_session->Run({assign_x, assign_y}, nullptr);
    std::vector<Tensor> outputs;
    p_session->Run({x, y, z, xy, xyz}, &outputs);
    LOG(INFO) << "x = " << outputs[0].matrix<float>();
    LOG(INFO) << "y = " << outputs[1].matrix<float>();
    LOG(INFO) << "xy = " << outputs[3].matrix<float>();
    LOG(INFO) << "z = " << outputs[2].matrix<float>();
    LOG(INFO) << "xyz = " << outputs[4].matrix<float>();
    delete p_session;
    return 0;
}

int PlaceholderTest()
{
    auto root = Scope::NewRootScope();
    auto x = Placeholder(root, DataType::DT_INT32);
    auto w = Const(root, 1, {1, 2});
    auto wx = MatMul(root, x, w);
    auto b = Const(root, 2, {2});
    auto wx_b = Add(root, wx, b);
    auto p_session = new ClientSession(root);
    std::vector<Tensor> outputs;
    p_session->Run({{x, {{1}, {1}, {1}}}}, {wx, wx_b}, &outputs);
    LOG(INFO) << "wx = " << outputs[0].matrix<int>();
    LOG(INFO) << "wx_b = " << outputs[1].matrix<int>();
    delete p_session;
    return 0;
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

void testCode(){
    Scope root = Scope::NewRootScope();
    // Matrix A = [3 2; -1 0]
    auto A = Const(root, { {3.f, 2.f}, {-1.f, 0.f}});
    // Vector b = [3 5]
    auto b = Const(root, { {3.f, 5.f}});
    // v = Ab^T
    auto v = MatMul(root.WithOpName("v"), A, b, MatMul::TransposeB(true));
    std::vector<Tensor> outputs;
    ClientSession session(root);
    // Run and fetch v
    TF_CHECK_OK(session.Run({v}, &outputs));
    // Expect outputs[0] == [19; -3]
    std::cout<< outputs[0].matrix<float>();
}

int main()
{
    SessionTest();
    ConstTest();
    VariableTest();
    PlaceholderTest();
    GradientsTest1();
    testCode();
    return 0;
}

