// week6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Exeption{};

int main()
{
    auto start{ std::chrono::high_resolution_clock::now() };

    std::vector<int> vector;
    vector.push_back(3);
    vector.push_back(4);

    try
    {
        vector.at(4) = 4;
        throw Exeption();
    }
    catch (const Exeption& exeption)
    {
        auto end{ std::chrono::high_resolution_clock::now() };
        std::cout << (end - start).count();;
    }

    /*vector[4] = 4;

    auto end{ std::chrono::high_resolution_clock::now() };
    std::cout << (end - start).count();*/
}