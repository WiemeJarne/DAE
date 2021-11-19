// Theorie_les02demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>

void GenerateRandomNumber(); // forward function declaration

int main()
{
    /*std::cout << "Hello World!\n";
    int a{}, b{};

    std::cout << "Getal?\n";
    std::cin >> a;
    std::cout << a << '\n';

    std::cout << "Getal?\n";
    std::cin >> b;
    std::cout << b << '\n';
    
    std::cin.get();
    std::cin.get();*/

    std::string text;
    text = "DAE";
    std::cout << text << '\n';
    text = text + " world.\n";
    std::cout << text << '\n';
    int number{ 12 };
    text = text + std::to_string(number);
    std::cout << text << '\n';

    float fPi{ float(M_PI) };
    float result{ sinf(1.25f) };

    GenerateRandomNumber();
    GenerateRandomNumber();
    GenerateRandomNumber();
    GenerateRandomNumber();
}

void GenerateRandomNumber()
{
    int randNumber{};
    randNumber = rand() %10;
    std::cout << randNumber << '\n';
}