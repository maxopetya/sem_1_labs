#include <list>
#include <iostream>

void reverseNum(std::list<int>& nums)
{
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        it = nums.insert(it, -*it);
        ++it;
    }
}
int main() {
    std::list<int> list1 = {1,5,4,-3};
    reverseNum(list1);
    std::cout << "Reverse numbers: ";
    for (int x : list1) std::cout << x << " ";
    std::cout << std::endl;
}
