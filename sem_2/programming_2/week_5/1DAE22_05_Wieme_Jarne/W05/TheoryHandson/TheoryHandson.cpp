// TheoryHandson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Float2.h"

int main()
{
    std::cout << "Hello World!\n";

    Float2 f1{ 10, 20 }, f2{ 50, 70 }, f3{};
    f3 = f1 + f2;
    f3 += f1;

    std::cout << "f1 = " << f1 << '\n';
}

