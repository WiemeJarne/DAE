// LinkedListStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "LinkedListStack.h"

int main()
{
    auto linkedListStack{ std::make_unique<LinkedListStack<float>>() };

    linkedListStack->Push(3);
    linkedListStack->Push(4);

   float d = linkedListStack->Pop();
   float e = linkedListStack->Pop();

   linkedListStack->Push(2);
}