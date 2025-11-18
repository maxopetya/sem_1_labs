#include "lab.h"

void reverseNum(std::list<int>& nums)
{
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        it = nums.insert(it, -*it);
        ++it;
    }
}
