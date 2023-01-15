// week6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

int main()
{
    auto end{ std::chrono::high_resolution_clock::now() };

    std::vector<int> vector;
    vector.push_back(3);
    vector.push_back(4);

    auto start{ std::chrono::high_resolution_clock::now() };

    vector.at(1) = 4;
    
    end = std::chrono::high_resolution_clock::now();
    std::cout << (end - start).count() << '\n';


    start = std::chrono::high_resolution_clock::now();

    vector[1] = 4;
    
    end = std::chrono::high_resolution_clock::now();
    std::cout << (end - start).count();
}