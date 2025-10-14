#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::string> split(const std::string &s, char sep) {
    std::vector<std::string> result;

    if (s.empty()) {
        std::cout << "empty string" << std::endl;
        return result;
    } //возврат пустого вектора

    size_t start = 0;
    size_t end = s.find(sep);

    while (end != std::string::npos) {
        result.push_back(s.substr(start, end - start));
        start = end + 1;
        end = s.find(sep, start);
    } //добавение подстроки в конец вектора

    result.push_back(s.substr(start)); //добавление последней подстроки в конец вектора

    bool onlySep = true;
    for (const auto& part : result) {
        if (!part.empty()) {
            onlySep = false;
            break;
        }
    } //проверка на состояние только из разделителей

    if (onlySep) {
        return std::vector<std::string>();
    }

    std::cout << "result: {";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
    return result;
}

int main() {
    std::string s = "Can you can a can as a canner can can a can?";
    char sep = ' ';
    split(s, sep);
    //мяу
}