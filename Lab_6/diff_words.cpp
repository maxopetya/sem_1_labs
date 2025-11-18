#include "lab.h"
#include <set>

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

