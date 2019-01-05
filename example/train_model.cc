//
// Created by mac on 2019/1/5.
//

#include <arpa/inet.h>
#include <string>
#include <vector>
#include <fstream>
#include "tensorflow/core/public/session.h"

using namespace std;

class DataSet {
public:
    DataSet()
    {}

    void LoadDataFromDir(const std::string& path)
    {
        const char* x_train_file = "train-images-idx3-ubyte";
        const char* y_train_file = "train-labels-idx1-ubyte";
        const char* x_test_file = "t10k-images-idx3-ubyte";
        const char* y_test_file = "t10k-labels-idx1-ubyte";
        m_x_train = ExtractImages(path + "/" + x_train_file);
        m_y_train = ExtractLabels(path + "/" + y_train_file);
        m_x_test = ExtractImages(path + "/" + x_test_file);
        m_y_test = ExtractLabels(path + "/" + y_test_file);
    }

    vector<double>& x_train()
    {
        return m_x_train;
    }

    vector<int>& y_train()
    {
        return m_y_train;
    }

    vector<double>& x_test()
    {
        return m_x_test;
    }

    vector<int>& y_test()
    {
        return m_y_test;
    }

private:
    uint32_t ReadUint32(ifstream& is)
    {
        uint32_t data = 0;
        if (is.read(reinterpret_cast<char*>(&data), 4)) {
            return ntohl(data);
        }
        throw logic_error("can't read 4 bytes");
    }

    uint8_t ReadUint8(ifstream& is)
    {
        uint8_t data = 0;
        if (is.read(reinterpret_cast<char*>(&data), 1)) {
            return data;
        }
        throw logic_error("can't read 1 byte");
    }

    vector<double> ExtractImages(const string& file)
    {
        ifstream is(file);
        if (!is) {
            throw logic_error("can't open file: " + file);
        }
        uint32_t magic = ReadUint32(is);
        if (magic != 2051) {
            throw logic_error("bad magic: " + to_string(magic));
        }
        uint32_t num = ReadUint32(is);
        uint32_t rows = ReadUint32(is);
        uint32_t cols = ReadUint32(is);
        vector<double> images;
        for (size_t i = 0; i < num*rows*cols; ++i) {
            uint8_t byte = ReadUint8(is);
            images.push_back(static_cast<double>(byte)/255.0);
        }
        return images;
    }

    vector<int> ExtractLabels(const string& file)
    {
        ifstream is(file);
        if (!is) {
            throw logic_error("can't open file: " + file);
        }
        uint32_t magic = ReadUint32(is);
        if (magic != 2049) {
            throw logic_error("bad magic: " + to_string(magic));
        }
        uint32_t num = ReadUint32(is);
        vector<int> labels;
        for (size_t i = 0; i < num; ++i) {
            uint8_t byte = ReadUint8(is);
            labels.push_back(byte);
        }
        return labels;
    }

    std::vector<double> m_x_train;
    std::vector<int> m_y_train;
    std::vector<double> m_x_test;
    std::vector<int> m_y_test;
};

using namespace tensorflow;

int main(int argc, char* argv[])
{
    try {
        string data_dir = "mnist_data";
        if (argc > 1) {
            data_dir = argv[1];
        }
        DataSet data_set;
        cout << "loading data from " << data_dir << " ... " << endl;
        data_set.LoadDataFromDir(data_dir);
        cout << "loading data ... done." << endl;

        // Initialize a tensorflow session
        Session* session;
        TF_CHECK_OK(NewSession(SessionOptions(), &session));

        // Read in the protobuf graph we exported
        // (The path seems to be relative to the cwd. Keep this in mind
        // when using `bazel run` since the cwd isn't where you call
        // `bazel run` but from inside a temp folder.)
        GraphDef graph_def;
        const char* graph_path = "mnist_graph.pb";
        if (argc > 2) {
            graph_path = argv[2];
        }
        cout << "reading graph from " << graph_path << " ... " << endl;
        TF_CHECK_OK(ReadBinaryProto(Env::Default(), graph_path, &graph_def));
        cout << "reading graph ... done." << endl;

        // Add the graph to the session
        TF_CHECK_OK(session->Create(graph_def));

        // Setup inputs and outputs:
        Tensor x_train(DataTypeToEnum<float>::v(),
                       TensorShape{static_cast<int>(data_set.x_train().size())/784, 784});
        copy_n(data_set.x_train().begin(), data_set.x_train().size(), x_train.flat<float>().data());

        Tensor y_train(DataTypeToEnum<int>::v(),
                       TensorShape{static_cast<int>(data_set.y_train().size())});
        copy_n(data_set.y_train().begin(), data_set.y_train().size(), y_train.flat<int>().data());

        std::vector<std::pair<string, tensorflow::Tensor>> inputs = {
                { "x", x_train },
                { "y_", y_train },
        };

        cout << "init global variables ... " << endl;
        TF_CHECK_OK(session->Run(inputs, { }, { "init" }, nullptr));
        cout << "init ... done." << endl;

        cout << "training ... " << endl;
        std::vector<tensorflow::Tensor> outputs;
        for (int i = 0; i < 100; ++i) {
            cout << "step " << i << endl;
            TF_CHECK_OK(session->Run(inputs, {}, { "train_step" }, nullptr));
        }
        cout << "training ... done." << endl;

        cout << "testing ... " << endl;
        Tensor x_test(DataTypeToEnum<float>::v(),
                      TensorShape{static_cast<int>(data_set.x_test().size())/784, 784});
        copy_n(data_set.x_test().begin(), data_set.x_test().size(), x_test.flat<float>().data());

        Tensor y_test(DataTypeToEnum<int>::v(),
                      TensorShape{static_cast<int>(data_set.y_test().size())});
        copy_n(data_set.y_test().begin(), data_set.y_test().size(), y_test.flat<int>().data());
        std::vector<std::pair<string, tensorflow::Tensor>> tests = {
                { "x", x_test },
                { "y_", y_test }
        };

        TF_CHECK_OK(session->Run(tests, { "accuracy" }, {}, &outputs));
        cout << "Accuracy: " << *outputs[0].scalar<float>().data() << endl;
        cout << "testing ... done." << endl;

        // Free any resources used by the session
        session->Close();
    } catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}

