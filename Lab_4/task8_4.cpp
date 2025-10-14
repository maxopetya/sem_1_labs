#include <iostream>
#include <vector>

std::string join(const std::vector<std::string>& parts, const std::string& sep) {
    std::string result;

    if (parts.empty()) {
        return result;
    } //пустая строка, если вектор пустой

    result += parts[0];

    for (size_t i = 1; i < parts.size(); ++i) {
        result += sep;
        result += parts[i];
    }
    std::cout << result << std::endl;
    return result;
}
int main() {
    std::vector<std::string> parts = {"Can", "you", "can", "a", "can", "as", "a", "canner", "can", "can", "a", "can?"};
    std::string s = " ";
    join(parts, s);
}