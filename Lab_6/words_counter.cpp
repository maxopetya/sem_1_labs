#include "lab.h"

int wordsCounter(const std::string& str)
{
    int count = 0;
    bool inWord = false;

    for (char c : str)
    {
        if (c != ' ' && c != ',' && c != '.')
        {
            if (!inWord)
            {
                inWord = true;
                count++;
            }
        }
        else
        {
            inWord = false;
        }
    }
    return count;
}

