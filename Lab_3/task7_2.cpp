#include <string>
#include <algorithm>

void longest_shortest(const std::string& s1, const std::string& s2, const std::string& s3) {
    std::string* mas = new std::string[3]{s1, s2, s3};
    std::sort(mas, mas + 3, [](const std::string& a, const std::string& b) {return a.length() < b.length();});
    std::string longest = mas[2];
    std::string shortest = mas[0];
    delete[] mas;
}