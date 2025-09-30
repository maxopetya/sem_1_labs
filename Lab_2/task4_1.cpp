#include <iostream>

int main() {
    int x1 = 1;
    for (int i = 8; i <= 15; i++) {x1 *= i;}
    std::cout << x1 << std::endl;
    long long x2 = 1;
    int a;
    std::cin >> a;
    for (int i = a; i <= 20; i++) {x2 *= i;}
    std::cout << x2 << std::endl;
    long long x3 = 1;
    int b;
    std::cin >> b;
    for (int i = 1; i <= b; i++) {x3 *= i;}
    std::cout << x3 << std::endl;
    long long x4 = 1;
    int c;
    std::cin >> c;
    int d;
    std::cin >> d;
    for (int i = c; i <= d; i++) {x4 *= i;}
    std::cout << x4 << std::endl;
}