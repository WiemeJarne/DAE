// LockFreeStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <thread>
#include "LockFreeStack.h"

void Test(LockFreeStack<int>* pLockFreeStack, int threadNr)
{
    const int amountOfNrs{ 10 };
    for (int index{}; index < amountOfNrs; ++index)
    {
        pLockFreeStack->Push(index);
        std::cout << "push from thread nr:" << threadNr << '\n';
    }

    for (int index{}; index < amountOfNrs; ++index)
    {
        std::cout << "popped form thread nr:" << threadNr << ' ' << pLockFreeStack->Pop() << '\n';
    }
}

int main()
{
    LockFreeStack<int> stack{};
    
    const int amountOfThreads{ 3 };

    std::vector<std::thread> threads{};

    for (int index{}; index < amountOfThreads; ++index)
    {
        threads.push_back(std::thread(Test, &stack, index));
    }

    for (auto& thread : threads)
    {
        thread.join();
    }

    std::cout << "TEST FINNISHED\n";
}