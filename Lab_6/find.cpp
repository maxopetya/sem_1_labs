#include <vector>
#include <iostream>


std::vector<int>::iterator Find(std::vector<int>::iterator first, std::vector<int>::iterator last, int el) {
    for (auto it = first; it != last; ++it) {
        if (*it == el) {
            return it;
        }
    }
    return last;
}

int main() {
    std::vector<int> v1 = {6,8,1,2,3};
    auto it = Find(v1.begin(), v1.end(), 2);
    if (it != v1.end()) std::cout << *it << std::endl;

}