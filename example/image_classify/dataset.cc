#include "dataset.h"
#include <dirent.h>  // opendir
#include <cstring>   // strcmp
#include <algorithm> // random_shuffle
#include <sstream>   // std::stringstream

Dataset::Dataset(const std::string &parent_dir)
{
    this->m_p_index = new int(0);
    this->m_p_vct_filename = new std::vector<std::string>();
    if (!this->load_filenames(parent_dir))
        throw "Failed to load filenames.";
}

Dataset::~Dataset()
{
    delete this->m_p_vct_filename;
    delete this->m_p_index;
}

int Dataset::size()
{
    return this->m_p_vct_filename->size();
}

void Dataset::shuffle()
{
    random_shuffle(this->m_p_vct_filename->begin(), this->m_p_vct_filename->end());
}

void Dataset::reset()
{
    this->m_p_index = new int(0);
}

bool Dataset::get_batch(const int &batch_size, std::vector<std::string> &vct_filename, std::vector<int> &vct_label)
{
    if (*this->m_p_index + batch_size > this->size())
        return false;
    vct_filename.clear();
    vct_label.clear();
    for (auto i = 0; i < batch_size; i++)
    {
        auto filename = this->m_p_vct_filename->at(*this->m_p_index + i);
        vct_filename.push_back(filename);
        auto found = filename.find_last_of("/\\");
        auto str_label = filename.substr(found - 1, 1);\
        auto label = 0;
        std::stringstream(str_label) >> label;
        vct_label.push_back(label);
    }
    *this->m_p_index += batch_size;
    return true;
}

bool Dataset::load_filenames(const std::string &parent_dir)
{
    auto p_dir = opendir(parent_dir.data());
    if (p_dir)
    {
        struct dirent *p_file = nullptr;
        while (p_file = readdir(p_dir))
        {
            if (0 == strcmp(p_file->d_name, ".") || 0 == strcmp(p_file->d_name, ".."))
                continue;
            if (p_file->d_type == DT_DIR)
                this->load_filenames(parent_dir + '/' + p_file->d_name);
            else
                this->m_p_vct_filename->push_back(parent_dir + '/' + p_file->d_name);
        }
        closedir(p_dir);
        return true;
    }
    return false;
}