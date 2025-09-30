#include <vector>
#include <iostream>

void sort(std::vector<float>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - i - 1; j++) {
            if (v[j] < v[j+1]) {
                std::swap(v[j], v[j+1]);
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
}
int main() {
    std::vector<float> v = {1.1, 0.67, 5.0, 2.0, -3.0, 2.2};
    sort(v);
}