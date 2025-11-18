#include "lab.h"

std::vector<int>::iterator findInSorted(std::vector<int>::iterator first,
                                        std::vector<int>::iterator last, int el)
{
    auto l = first;
    auto r = last;

    while (l < r)
    {
        auto mid = l + (r - l) / 2;
        if (*mid == el)
            return mid;
        else if (*mid < el)
            l = mid + 1;
        else
            r = mid;
    }
    return last;
}

