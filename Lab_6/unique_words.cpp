#include <vector>
#include <set>
#include <iostream>
#include <algorithm>


std::string toLowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

std::vector<std::string> uniqueWords(const std::string& str)
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
                uniq.insert(toLowerCase(word));
                word.clear();
            }
        }
    }
    if (!word.empty())
        uniq.insert(toLowerCase(word));

    return std::vector<std::string>(uniq.begin(), uniq.end());
}

int main() {
    auto u = uniqueWords("Can you can can a A");
    std::cout << "uniqueWords: ";
    for (auto& s : u) std::cout << s << " ";
    std::cout << std::endl;
}
