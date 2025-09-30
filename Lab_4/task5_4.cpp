#include <vector>
#include <iostream>

bool remove_first_negative_element(std::vector<int>& vec, int& removed_element) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] < 0) {
            removed_element = vec[i];
            std::cout << "removed_element = " << removed_element << std::endl;
            return true;
        }
        }
    removed_element = 0;
    std::cout << "removed_element = " << removed_element << std::endl;
    return false;
    }

int main() {
    int removed_element = 5;
    std::vector<int> vec {1, 2, 2, 3, 4, 55, 6, 7, 8, 9, 10, 5};
    remove_first_negative_element(vec, removed_element);
}