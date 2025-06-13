#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

std::vector<std::string> split_string(std::string s)
{
    std::vector<std::string> res;
    std::string word;
    for (char c : s)
    {
        if (c == ' ')
        {
            res.push_back(word);
            word = "";
        }
        else
            word += c;
    }
    if (s[s.size() - 1] != ' ')
        res.push_back(word);

    return res;
}

std::vector<std::string> file_to_vector(const char *filepath)
{
    std::vector<std::string> res;

    std::ifstream file(filepath, std::ios::in);
    if (!file.is_open())
        return {};

    std::string line;
    while (getline(file, line))
    {
        for(auto s : split_string(line)){
            res.push_back(s);
        }
    }

    file.close();
    return res;
}