// Wieme, Jarne - 1DAE23
// Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>

void TestOneParFunctions(double angle);
void pythagorasTheorem(float zijdeA, float zijdeB, float hypotenuse);

int main()
{
    double angle{};

    TestOneParFunctions(angle);

    TestOneParFunctions( angle = angle + ( M_PI / 4 ));

    TestOneParFunctions( angle = angle + ( M_PI / 4 ));

    TestOneParFunctions( angle = angle + ( M_PI / 4 ));

    TestOneParFunctions( angle = angle + (M_PI / 4 ));

    std::cout << std::endl;
   
    float zijdeA{ 0 }, zijdeB{ 0 }, hypotenuse{ 0 };

    pythagorasTheorem(zijdeA, zijdeB, hypotenuse);
    }

void TestOneParFunctions(double angle)
{
    double cosA;
    cosA = cos(angle);
    std::cout << "Angle: " << angle << "\n  cos: " << cosA << std::endl;
}

void pythagorasTheorem(float zijdeA, float zijdeB, float hypotenuse)
{
    zijdeA = 3;
    zijdeB = 4;

    hypotenuse = sqrt(pow(zijdeA, 2) + pow(zijdeB, 2));

    std::cout << "In a traingle where the short sides are 3 and 4 is the hypotenuse " << hypotenuse << '.' << std::endl;
}