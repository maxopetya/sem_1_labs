#include <string>
#include <iostream>

std::string rep(std::string str, const std::string& old, const std::string& new_string) {
    size_t pos = 0;
    while ((pos = str.find(old, pos)) != std::string::npos) {
        str.replace(pos, old.length(), new_string);
        pos += new_string.length();
    }
    std::cout << str << std::endl;
    return str;
}

int main() {
    rep("Can you can a can as a caner can can a can?", "can", "xxx");
}