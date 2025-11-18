#include <iostream>
#include <vector>
#include <list>

#include "lab.h"

int main()
{
    std::vector<int> v1 = {6,8,1,2,3};
    auto it = Find(v1.begin(), v1.end(), 2);
    if (it != v1.end()) std::cout << "Find(2) = " << *it << std::endl;

    std::vector<int> v2 = {1,2,3,4,5};
    auto it2 = findInSorted(v2.begin(), v2.end(), 3);
    if (it2 != v2.end()) std::cout << "findInSorted(3) = " << *it2 << std::endl;

    std::cout << "wordsCounter: " << wordsCounter("can you can") << std::endl;

    auto m = wordsMapCounter("can you can");
    std::cout << "wordsMapCounter: can=" << m["can"] << ", you=" << m["you"] << std::endl;

    auto u = uniqueWords("Can you can");
    std::cout << "uniqueWords: ";
    for (auto& s : u) std::cout << s << " ";
    std::cout << std::endl;

    std::cout << "diffWordsCounter: "
              << diffWordsCounter("can you can a can") << std::endl;

    std::list<int> list1 = {1,5,4,-3};
    reverseNum(list1);
    std::cout << "reverseNum: ";
    for (int x : list1) std::cout << x << " ";
    std::cout << std::endl;

    std::vector<int> v3 = {1,0,-8,-9,0,10,23,-7};
    plusesDeleter(v3);
    std::cout << "plusesDeleter: ";
    for (int x : v3) std::cout << x << " ";
    std::cout << std::endl;

    std::list<int> list2 = {1,5,4,-3};
    Sort(list2);
    std::cout << "Sort: ";
    for (int x : list2) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
