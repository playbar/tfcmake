//
// Created by mac on 2019/1/5.
//

#include "tensorflow/cc/framework/gradients.h"
#include "tensorflow/cc/client/client_session.h"
#include "tensorflow/cc/ops/standard_ops.h"
#include "tensorflow/core/framework/tensor.h"
using namespace tensorflow;
using namespace tensorflow::ops;

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

int main() {
    GradientsTest1();
    testCode();
    return 0;
}

