// Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>

int main()
{
    const int arraySize{ 1'000'000'000 };
    int* arr{ new int[arraySize] {} };

    for (int stepsize{ 1 }; stepsize <= 1024; stepsize *= 2)
    {
        const auto start{ std::chrono::high_resolution_clock::now() };

        for (int index{}; index < arraySize; index += stepsize)
        {
            arr[index] *= 2;
        }
        
        const auto total{ std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count() };

        std::cout << stepsize << "; " << total << "\n";
    }
}