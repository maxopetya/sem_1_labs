#include <iostream>
#include <map>


std::map<std::string, int> wordsMapCounter(const std::string& str)
{
    std::map<std::string, int> result;

    std::string word;
    for (char c : str)
    {
        if (c != ' ' && c != ',' && c != '.')
        {
            word += c;
        }
        else
        {
            if (!word.empty())
            {
                result[word]++;
                word.clear();
            }
        }
    }
    if (!word.empty())
        result[word]++;

    return result;
}

int main() {
    auto m = wordsMapCounter("can you can can");
    std::cout << "wordsMapCounter: can=" << m["can"] << ", you=" << m["you"] << std::endl;
}