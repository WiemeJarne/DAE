// TheoryHandsOnweek7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct Point2f
{
    float x, y;
};

void PrintArrayValues(int* pPointer, int size);
void DoubleValue(int* pPointer);

int main()
{
    int number1{}, number2{}, number3{}, number4{}, number5{}, number6{};

    const int size{ 6 };

    int numbers[size]{ 43,64,34,345,5 };

    std::cout << "sizeof numbers: " << sizeof(numbers) << '\n';

    PrintArrayValues(numbers, size);

    std::cout << number1 << '\n';
    std::cout << number2 << '\n';
    std::cout << number3 << '\n';
    std::cout << number4 << '\n';
    std::cout << number5 << '\n';
    std::cout << number6 << '\n';

    //int numbers[6]{};
    //int numbers[6]{ 10,20,30,40,50,60 };
    for (int i{}; i < 6; ++i)
    {
        std::cout << numbers[i] << '\n';
    }

    int score{ 42 };
    DoubleValue(&score);

    Point2f points[size];
    for (int i{}; i < size; ++i)
    {
        points[i].x = float(rand());
        points[i].y = float(rand());
        //points[i] = Point2f{ float(rand()), float(rand()) }; zelfde als vorige 2 lijnen tesamen
    }

}

void DoubleValue(int* pPointer)
{
    std::cout << pPointer << '\t' << *pPointer << '\n';
    *pPointer *= 2;
    std::cout << *pPointer << '\n';
}

void PrintArrayValues(int* pPointer, int size)
{
    std::cout << "sizeof pPointer: " << sizeof(pPointer) << '\n';

    for (int i{}; i < size; ++i)
    {
        std::cout << pPointer[i] << ' ';
    }
    
}

