// FunctionsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

void PrintMessage(int numberOfLeadingCharacter = 0, std::string character = " ");
void CalcCosSin(float& angle, float& cosResult, float& sinResult);

float GetRand(float bottomBoundary, float topBoundary);

void TestCalcCosSin(int numberOfCalcCosSin);

int main()
{
    srand(time(nullptr));

    //PrintMessage(5, "&");
    TestCalcCosSin(10);
}

void PrintMessage(int numberOfLeadingCharacter, std::string character)
{
    std::string indentation{ std::to_string(numberOfLeadingCharacter) +  character + " indentation specified" };

    if (numberOfLeadingCharacter == 0)
    {
        std::cout << "No indentation specified\n";
    }
    else
    {
        for (int numberOfCharcacter{}; numberOfCharcacter < numberOfLeadingCharacter; ++numberOfCharcacter)
        {
            indentation = character + indentation;
        }
        std::cout << indentation << '\n';
    }

}

void CalcCosSin(float& angle, float& cosResult, float& sinResult)
{
    angle = GetRand(0, 2 * M_PI);
    cosResult = cosf(angle);
    sinResult = sinf(angle);
}

float GetRand(float bottomBoundary, float topBoundary)
{
    float randFloat{ float((rand() % int((topBoundary * 10 - 10)) + int(bottomBoundary * 10)) / 10.f) };
    return randFloat;
}

void TestCalcCosSin(int numberOfCalcCosSin)
{
    std::cout << " --Function that calculates cosine and sine-- " << '\n';
    std::cout << std::setw(10) << "Radians" << std::setw(10) << "Cos" << std::setw(10) << "Sin\n";

    float angle{};
    float cosResult{};
    float sinResult{};

    for (int loopNumber{}; loopNumber < numberOfCalcCosSin; ++loopNumber)
    {
        CalcCosSin(angle, cosResult, sinResult);
        std::cout << std::setw(10) << std::fixed << std::setprecision(2) << angle << std::setw(10) << cosResult << std::setw(10) << sinResult << '\n';
    }
}