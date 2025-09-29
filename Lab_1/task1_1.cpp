#include <iostream>

int main() {
    int x;
    std::cin >> x;
    int y;
    std::cin >> y;
    int z;
    std::cin >> z;
    if (x%2 == 1 and y%2 == 1) {
        std::cout << "True1" << std::endl;
    }
    if (x < 20 xor y < 20) {
        std::cout << "True2" << std::endl;
    }
    if (x == 0 or y == 0) {
        std::cout << "True3" << std::endl;
    }
    if (x < 0 and y < 0 and z < 0) {
        std::cout << "True4" << std::endl;
    }
    if (x%5==0 xor y%5==0 xor z%5==0) {
        std::cout << "True5" << std::endl;;
    }
    if (x > 100 or y > 100 or z > 100) {
        std::cout << "True6" << std::endl;
    }
    return 0;
}