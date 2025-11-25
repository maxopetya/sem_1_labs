#include <vector>
#include <iostream>

std::vector<int>::iterator findInSorted(std::vector<int>::iterator first, std::vector<int>::iterator last, int el) {
    auto l = first;
    auto r = last;

    while (l < r)
    {
        auto mid = l + (r - l) / 2;
        if (*mid == el)
            {return mid;}
        else if (*mid < el)
            {l = mid + 1;}
        else
            {r = mid;}
    }
    return last;
}

int main() {
    std::vector<int> v2 = {1,2,3,4,5};
    auto it2 = findInSorted(v2.begin(), v2.end(), 1);
    if (it2 != v2.end()) std::cout << *it2 << std::endl;
}

