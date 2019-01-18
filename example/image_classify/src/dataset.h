#include <vector>   // std::vector
#include <string>   // std::string

class Dataset
{
public:
    Dataset(const std::string &parent_dir);
    ~Dataset();
    int size();
    void shuffle();
    void reset();
    bool get_batch(const int &batch_size, std::vector<std::string> &vct_filename, std::vector<int> &vct_label);

private:
    bool load_filenames(const std::string &parent_dir);

private:
    std::vector<std::string> *m_p_vct_filename;
    int *m_p_index;
};