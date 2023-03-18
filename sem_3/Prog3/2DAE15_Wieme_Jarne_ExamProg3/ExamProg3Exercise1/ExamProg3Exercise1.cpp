// ExamProg3Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <numeric>

template <typename function, typename container>
float functionTester(function f, container c);

int main()
{
	std::vector numbers{ 2, 4, 6, 8, 10 };

	std::cout << functionTester
	(
		[&numbers](int number)
		{
			return number /= 2;
		},
		numbers
	);
}


template <typename function, typename container>
float functionTester(function f, container c)
{
	std::chrono::steady_clock::time_point start{};
	std::chrono::steady_clock::time_point stop{};
	
	std::vector<float> times{};
	
	for (int index{}; index < 10; ++index)
	{
		start = std::chrono::high_resolution_clock::now();

		std::for_each(begin(c), end(c), f);
		
		stop = std::chrono::high_resolution_clock::now();

		times.push_back(static_cast<float>((stop - start).count()));
	}
	times.erase(std::max_element(begin(times), end(times)));
	times.erase(std::min_element(begin(times), end(times)));

	return std::accumulate(begin(times), end(times), 0.f) / 8.f;
}