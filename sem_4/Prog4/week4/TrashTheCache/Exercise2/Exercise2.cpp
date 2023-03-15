// Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>

struct Transform
{
    float matrix[16] = { 0 };
};

class GameObject3D
{
public:
    Transform* transform;
    int ID;
};

int main()
{
    const int arraySize{ 10'000'000 };
    GameObject3D* arr{ new GameObject3D[arraySize] {} };

    for (int stepsize{ 1 }; stepsize <= 1024; stepsize *= 2)
    {
        const auto start{ std::chrono::high_resolution_clock::now() };

        for (int index{}; index < arraySize; index += stepsize)
        {
            arr[index].ID *= 2;
        }

        const auto total{ std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count() };

        std::cout << stepsize << "; " << total << "\n";
    }
}