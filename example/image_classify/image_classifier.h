#include "tensorflow/cc/ops/standard_ops.h"
#include "tensorflow/cc/client/client_session.h"

namespace tf = tensorflow;
namespace tfop = tf::ops;

class ImageClassifier
{
public:
    ImageClassifier(const int &batch_size, const int &image_width, const int &image_height, 
                    const int &image_chenal, const int &nof_class);
    ~ImageClassifier();
    void train(const std::vector<std::string> &filenames, const std::vector<int> &labels, float &accuracy, float &loss);
    void test(const std::vector<std::string> &filenames, const std::vector<int> &labels, float &accuracy);

private:
    void read_batch_image(const tf::Scope &scope, tf::Output &images, tf::Output &labels);
    tf::Output accuracy(const tf::Scope &scope, const tf::Output &logits, const tf::Output &labels);
    tf::Output softmax_loss(const tf::Scope &scope, const tf::Output &logits, const tf::Output &labels);
    void gradients_op(const tf::Scope &scope, const tf::OutputList &outputs, const tf::OutputList &inputs, 
                      const float &learn_rate);
    void build_fc_model();
    void build_cnn_model();
    template <typename T>
    tf::Tensor parse_input(const std::vector<T> &input, const tf::DataType &dt);
    void run(const std::vector<std::string> &filenames, const std::vector<int> &labels, 
             const std::vector<tf::Output> &ins, std::vector<tf::Tensor> &outs);

private:
    int m_batch_size;
    int m_image_width;
    int m_image_height;
    int m_image_chenal;
    int m_nof_class;

    tfop::Placeholder *m_p_plcaeholder_filenames;
    tfop::Placeholder *m_p_placeholder_labels;
    std::vector<tf::Output> m_outputlist;
    tf::ClientSession *m_p_session;
};