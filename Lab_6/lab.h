#pragma once

#include <vector>
#include <list>
#include <string>
#include <map>

// 1. Find
std::vector<int>::iterator Find(std::vector<int>::iterator first, std::vector<int>::iterator last, int el);

// 2. findInSorted
std::vector<int>::iterator findInSorted(std::vector<int>::iterator first, std::vector<int>::iterator last, int el);

// 3. wordsCounter
int wordsCounter(const std::string& str);

// 4. wordsMapCounter
std::map<std::string, int> wordsMapCounter(const std::string& str);

// 5. uniqueWords
std::vector<std::string> uniqueWords(const std::string& str);

// 6. diffWordsCounter
int diffWordsCounter(const std::string& str);

// 7. reverseNum
void reverseNum(std::list<int>& nums);

// 8. plusesDeleter
void plusesDeleter(std::vector<int>& v);

// 9. Sort
void Sort(std::list<int>& nums);
