#include <iostream>
int main() {
    int arr[20];
    // пусть будет массив 1-20
    for (int i = 0; i < 20; i++) {
        arr[i] = i+1;
    }

    for (int i = 0; i < 3; i++) {
        int temp = arr[i];
        arr[i] = arr[20-3+i];
        arr[20-3+i] = temp;
    }
    std::cout << "Result: ";
    for (int i = 0; i < 20; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}