// TheoryTemplateDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>

template <typename T>
T Lerp(T min, T max, double alpha)
{
	return static_cast<T>((1 - alpha) * min + alpha * max);
}

int main( )
{
	for (double alpha{}; alpha <= 1; alpha += 0.1)
	{
		int result{ Lerp(15, 145, alpha) };
		std::cout << result << std::endl;
	}

	std::cout << std::endl;

	for (double alpha{}; alpha <= 1; alpha += 0.1)
	{
		double result{ Lerp(3.1415, 6.2830, alpha) };
		std::cout << result << std::endl;
	}
}