// Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    const int arraySize{ 10'000'000 };
    int* arr{ new int[arraySize] {} };

    std::vector<long long>times{};

    const int amountOfMeasurements{ 15 };
    
    for (int stepsize{ 1 }; stepsize <= 1024; stepsize *= 2)
    {
        for (int measurementIndex{}; measurementIndex < amountOfMeasurements; ++measurementIndex)
        {
            const auto start{ std::chrono::high_resolution_clock::now() };

            for (int index{}; index < arraySize; index += stepsize)
            {
                arr[index] *= 2;
            }

            const auto end{ std::chrono::high_resolution_clock::now() };
            times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
        }

        //remove hightest and lowest time
        times.erase(std::max_element(begin(times), end(times)));
        times.erase(std::min_element(begin(times), end(times)));

        //take the remaining times and take the average
        const auto averageTime{ std::accumulate(begin(times), end(times), 0.f) / static_cast<float>((amountOfMeasurements - 2)) };
        std::cout << stepsize << "; " <<  averageTime / 1000.f << " ms\n";
        
        //emty the vector
        times.clear();
    }

    delete[] arr;
}