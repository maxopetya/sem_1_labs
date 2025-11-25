#include <iostream>
#include <list>


void Sort(std::list<int>& nums)
{
    nums.sort([](int a, int b){ return a > b; });
}

int main() {
    std::list<int> list2 = {1,5,4,-3};
    Sort(list2);
    std::cout << "Sort: ";
    for (int x : list2) std::cout << x << " ";
    std::cout << std::endl;
}
