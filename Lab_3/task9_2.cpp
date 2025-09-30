#include <string>
#include <iostream>

int main() {
    std::string slovo;
    std::cin >> slovo;
    int count = slovo.length();
    char character = '*';
    std::string result1(count, character);
    std::string result2(count, character);
    std::cout << result1 << slovo << result2 << std::endl;
}