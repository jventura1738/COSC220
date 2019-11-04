// Justin Ventura COSC220-003
// LAB8: isPal.cpp
#include "isPal.h"

bool isPal(const std::string& str, int first, int last)
{
    if (first >= last) return true;
    if (str[first] != str[last]) return false;
    return isPal(str, first + 1, last - 1);
}
