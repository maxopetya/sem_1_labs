#include <string>
#include <iostream>

int main() {
    std::string slovo;
    int m, n;
    std::cin >> slovo;
    std::cin >> m >> n;

    std::string result = slovo.substr(m-1, n-m+1);
    std::cout << result << std::endl;
}