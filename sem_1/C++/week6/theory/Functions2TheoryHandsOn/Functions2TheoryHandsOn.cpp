// Functions2TheoryHandsOn.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

void AddChar(std::string& text);
int& GetNumber();
const int& GetSmallest(const int& aRef, const int& bRef);
int CalcSum(int number);

int main()
{
    std::cout << "Hello World!\n";
    std::string name{ "Jarne" };
    std::cout << name << '\n';
    AddChar(name);
    std::cout << name << '\n';
    int& ref{ GetNumber() };
    std::cout << ref << '\n';

    int a{ 42 }, b{ 10 };
    std::cout << a << ' ' << b << '\n';
    const int& refab{ GetSmallest(a, b) };
    std::cout << refab << '\n';

    int result{ CalcSum(10) };
    std::cout << result << '\n';
}

void AddChar(std::string& text)
{
    text += 'o';
}

int& GetNumber()
{
    int number{ rand() };
    return number; //don't do this
}

const int& GetSmallest(const int& aRef, const int& bRef)
{
    if (aRef < bRef) return aRef;
    return bRef;
}

int CalcSum(int number)
{
    if (number == 0) return 0;
    return number + CalcSum(number - 1);
}