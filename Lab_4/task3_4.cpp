#include <vector>
#include <iostream>

int argmax(const std::vector<float>& v) {
    if (v.size() == 0) {
        return 0;
    }
    else {
        int max_i = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > v[max_i]) {
                max_i = i;
            }
        }
        std::cout << max_i << std::endl;
        return max_i;
    }

}

int main() {
    std::vector<float> v = {1.1, 1.5, 0.7, 152, 23};
    argmax(v);
}