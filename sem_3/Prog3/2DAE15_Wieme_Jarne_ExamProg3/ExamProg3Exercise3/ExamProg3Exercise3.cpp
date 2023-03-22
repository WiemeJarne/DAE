// ExamProg3Exercise3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>

class StringTooShortException
{};

bool testStringForRepitition(const std::string& string, int repeat1, int repeat2);

int main()
{
    std::cout << testStringForRepitition("ZeePPoo", 3, 2) << '\n';
    //std::cout << testStringForRepitition("ZeePeePoo", 3, 2) << '\n';
    //std::cout << testStringForRepitition("ZeeP", 3, 2) << '\n';
}

bool testStringForRepitition(const std::string& string, int repeat1, int repeat2)
{
    if ((string.size() - 1) < (repeat1 * repeat2))
    {
        throw StringTooShortException();
    }

    std::string stringToSearch{};
    for (int index{}; index < repeat2; ++index)
    {
        stringToSearch += ' ';
    }

    int amountOfReatingCharacterFound{};
    std::string::const_iterator beginIterator{ string.begin() };

    for (int index{}; index < repeat1; ++index)
    {
       beginIterator = std::search(beginIterator, string.end(), stringToSearch.begin(), stringToSearch.end());
       if (string.end() != beginIterator)
       {
           ++amountOfReatingCharacterFound;
       }
    }
    
    if (amountOfReatingCharacterFound >= repeat1)
    {
        return true;
    }

    return false;
}
