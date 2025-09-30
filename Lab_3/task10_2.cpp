#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string sent;
    std::cin >> sent;
    int c = std::count(sent.begin(), sent.end(), 'a');
    std::cout << c << std::endl;
    float percentage = c * 100 / sent.length();
    std::cout << percentage << std::endl;
    std::cout << "The letter 'a' makes up " << percentage << "% of the sentence" << std::endl;
}