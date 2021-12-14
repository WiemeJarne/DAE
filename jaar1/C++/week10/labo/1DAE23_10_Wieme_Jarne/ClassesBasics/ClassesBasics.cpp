// Wieme Jarne 1GD23N
// ClassesBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Square.h"
#include <iostream>

void DoSquareTests();

int main()
{
	DoSquareTests();
}

void DoSquareTests()
{
	Square* ptrSquare1{ new Square{1.f} };
	Square* ptrSquare2{ new Square{0.f, 0.f, 0.f} };

	std::cout << ptrSquare1 << '\n';
	delete ptrSquare1;
	ptrSquare1 = nullptr;
	std::cout << ptrSquare1 << '\n';

	std::cout << ptrSquare2 << '\n';
	delete ptrSquare2;
	ptrSquare2 = nullptr;
	std::cout << ptrSquare2 << '\n';
}