#include <set>
#include <iostream>

int diffWordsCounter(const std::string& str)
{
    std::set<std::string> uniq;
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
                uniq.insert(word);
                word.clear();
            }
        }
    }
    if (!word.empty())
        uniq.insert(word);

    return uniq.size();
}

int main() {
    std::cout << "Different words: "
              << diffWordsCounter("can you can a can as a canner can can a can") << std::endl;
}
