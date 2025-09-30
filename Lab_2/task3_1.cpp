#include <iostream>

int main() {
    int x;
    std::cin >> x;
    for (int i {1}; i < 10; i++) {
        std::cout << i << " * " << 7 << " = " << 7 * i << std::endl;
    }
    for (int i {1}; i < 10; i++) {
        std::cout << i << " * " << x << " = " << x * i << std::endl;
    }
}