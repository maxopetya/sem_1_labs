#include <iostream>
#include <string>

int main() {
    std::string s = "Can you can a can as a canner can can a can?";
    std::string bylo = "can";
    std::string stalo = " new_word";
    size_t pos = 0;
    while ((pos = s.find(" can", pos)) != std::string::npos) {
        s.replace(pos, 4, stalo);
        pos += 8;
    }
    std::cout << s << std::endl;
}