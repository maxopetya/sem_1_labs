#include <algorithm>


char* CopyString(const char* str) //копирование
{
    if (!str)
    {
        return nullptr;
    }

    size_t length = 0;
    while (str[length] != '\0')
    {
        ++length;
    }

    char* new_string = new char[length + 1];
    std::copy(str, str + length + 1, new_string);

    return new_string;
}

char* ConcatinateStrings(const char* a, const char* b) //конкатенация
{
    if (!a && !b) return nullptr;
    if (!a) return CopyString(b);
    if (!b) return CopyString(a);

    size_t len_a = 0, len_b = 0;
    while (a[len_a] != '\0') ++len_a;
    while (b[len_b] != '\0') ++len_b;

    char* result = new char[len_a + len_b + 1];

    std::copy(a, a + len_a, result);
    std::copy(b, b + len_b + 1, result + len_a);

    return result;
}