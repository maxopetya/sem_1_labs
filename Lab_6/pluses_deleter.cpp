#include  <vector>
#include <algorithm>
#include <iostream>

void plusesDeleter(std::vector<int>& v)
{
    v.erase(std::remove_if(v.begin(), v.end(),
                           [](int x){ return x > 0; }),
            v.end());
}

int main() {
    std::vector<int> v3 = {1,0,-8,-9,0,10,23,-7};
    plusesDeleter(v3);
    std::cout << "plusesDeleter: ";
    for (int x : v3) std::cout << x << " ";
    std::cout << std::endl;
}

