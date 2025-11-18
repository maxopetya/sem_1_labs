#include "lab.h"

void Sort(std::list<int>& nums)
{
    nums.sort([](int a, int b){ return a > b; });
}
