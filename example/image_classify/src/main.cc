#include "dataset.h"
#include "image_classifier.h"

int main()
{
    const auto train_dir = "./data/train";
    const auto test_dir = "./data/test";
    const auto batch_size = 64;
    const auto image_width = 28;
    const auto image_height = 28;
    const auto image_chenal = 1;
    const auto nof_class = 10;
    const auto nof_epoch = 20;

    ImageClassifier *p_image_classifier = new ImageClassifier(batch_size, image_width, image_height, image_chenal,
                                                              nof_class);
    // train
    Dataset *p_dataset = new Dataset(train_dir);
    for (auto epoch = 1; epoch <= nof_epoch; epoch++)
    {
        p_dataset->shuffle();
        std::vector<std::string> filenames;
        std::vector<int> labels;
        for (auto step = 1; p_dataset->get_batch(batch_size, filenames, labels); step++)
        {
            auto accuracy = 0.f, loss = 0.f;
            p_image_classifier->train(filenames, labels, accuracy, loss);
            if (step % 100 == 0)
                std::cout << "Epoch=" << epoch << " Step=" << step << " Accuracy=" << accuracy
                          << " Loss=" << loss << std::endl;
        }
        p_dataset->reset();
    }
    delete p_dataset;
    
    // test
    p_dataset = new Dataset(test_dir);
    p_dataset->shuffle();
    auto sum_acc = 0.f, count_acc = 0.f;
    std::vector<std::string> filenames;
    std::vector<int> labels;
    while (p_dataset->get_batch(batch_size, filenames, labels))
    {
        auto accuracy = 0.f;
        p_image_classifier->test(filenames, labels, accuracy);
        sum_acc += accuracy;
        count_acc++;
    }
    std::cout << "Test accuracy: " << sum_acc / count_acc << std::endl;
    delete p_dataset;
    return 0;
}