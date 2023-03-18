// Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <numeric>

struct Transform
{
    float matrix[16] = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1 };
};

class GameObject3D
{
public:
    Transform transform{};
    int ID{};
};

class GameObject3DAlt
{
public:
    Transform* transform{};
    int ID{};
};

int main()
{
    const int arraySize{ 10'000'000 };
    GameObject3D* gameObject3DArr{ new GameObject3D[arraySize] {} };
    GameObject3DAlt* gameObject3DAltArr{ new GameObject3DAlt[arraySize] {} };

    std::vector<long long>GameObject3DTimes{};
    std::vector<long long>GameObject3DAltTimes{};

    const int amountOfMeasurements{ 15 };

    for (int stepsize{ 1 }; stepsize <= 1024; stepsize *= 2)
    {
        for (int measurementIndex{}; measurementIndex < amountOfMeasurements; ++measurementIndex)
        {
            //time for GameObject3DArr
            auto start{ std::chrono::high_resolution_clock::now() };

            for (int index{}; index < arraySize; index += stepsize)
            {
                gameObject3DArr[index].ID *= 2;
            }

            auto end{ std::chrono::high_resolution_clock::now() };
            GameObject3DTimes.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());

            //time for GameObject3DAltArr
            start = std::chrono::high_resolution_clock::now();

            for (int index{}; index < arraySize; index += stepsize)
            {
                gameObject3DAltArr[index].ID *= 2;
            }

            end = std::chrono::high_resolution_clock::now();
            GameObject3DAltTimes.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
        }

        //remove hightest and lowest time from both vectors
        GameObject3DTimes.erase(std::max_element(begin(GameObject3DTimes), end(GameObject3DTimes)));
        GameObject3DTimes.erase(std::min_element(begin(GameObject3DTimes), end(GameObject3DTimes)));

        GameObject3DAltTimes.erase(std::max_element(begin(GameObject3DAltTimes), end(GameObject3DAltTimes)));
        GameObject3DAltTimes.erase(std::min_element(begin(GameObject3DAltTimes), end(GameObject3DAltTimes)));

        //take the remaining times and take the average from both vectors
        std::cout << "step size " << stepsize << ":\n";
        auto averageTime{ std::accumulate(begin(GameObject3DTimes), end(GameObject3DTimes), 0.f) / static_cast<float>((amountOfMeasurements - 2)) };
        std::cout << "GameObject3D" << "; " << averageTime / 1000.f << " ms\n";

        averageTime = std::accumulate(begin(GameObject3DAltTimes), end(GameObject3DAltTimes), 0.f) / static_cast<float>((amountOfMeasurements - 2));
        std::cout << "GameObject3DAlt" << "; " << averageTime / 1000.f << " ms\n";

        std::cout << '\n';

        //emty the vectors
        GameObject3DTimes.clear();
        GameObject3DAltTimes.clear();
    }

    delete[] gameObject3DArr;
    delete[] gameObject3DAltArr;
}