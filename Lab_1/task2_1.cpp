#include <iostream>

int main() {
    std::cout << "Hello world" << std::endl;
    using byte = unsigned char;
    std::pair<byte, byte> positionA;
    std::cin >> positionA.first >> positionA.second;
    // ввели позицию A
    using byte = unsigned char;
    std::pair<byte, byte> positionB;
    std::cin >> positionB.first >> positionB.second;
    // ввели позиицю Б
    bool rook, bishop;

    // условие 1 (ладья)
    if (positionA.first == positionB.first or positionA.second == positionB.second) {
        std::cout << "Rook threatening" << std::endl;
        rook = true;
    }
    else {std::cout << "Rook not threatening" << std::endl; rook = false;}

    // условие 2 (слон)
    if (abs(positionA.first - positionB.first) == abs(positionA.second - positionB.second)) {
        std::cout << "Bishop threatening" << std::endl;
        bishop = true;
    }
    else {std::cout << "Bishop not threatening" << std::endl; bishop = false;}

    // условие 3 (король)

    if (abs(positionA.first - positionB.first) <= 1 and abs(positionA.second - positionB.second) <= 1) {
        std::cout << "King threatening" << std::endl;
    }
    else {std::cout << "King not threatening" << std::endl;}


    // условие 4 (ферзь)
    if (rook or bishop) {
        std::cout << "Queen threatening" << std::endl;
    }
    else {std::cout << "Queen not threatening" << std::endl;}

    // условие 5 (пешка)
    // 5.1 (обычный ход на 1 клетку)
    if (abs(positionA.first - positionB.first) == 1 and (positionB.second - positionA.second) == 2) {
        std::cout << "Pawn can threaten by moving once" << std::endl;
    }

    // 5.2 (обычный ход на 2 клетки)
    else if (abs(positionA.first - positionB.first) == 1 and positionA.second == '2' and positionB.second == '5') {
        std::cout << "Pawn can threaten by moving twice" << std::endl;
    }

    // 5.3 (пешка бьет другую фигуру или пешку)
    else if (abs(positionA.first - positionB.first) == 2 and abs(positionA.second - positionB.second) == 2) {
        std::cout << "Pawn can threaten by capturing" << std::endl;
    }
    else {std::cout << "Pawn cant threaten" << std::endl;}
    return 0;
}