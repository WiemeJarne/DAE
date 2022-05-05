// TheoryHandsOn.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <string>

void Print(const std::map<int, std::string>& map);

void NotMain( )
{
	std::map<int, std::string> months;

	months.insert(std::pair<int, std::string>{1, "January"});
	months.insert(std::make_pair<int, std::string>(2, "February"));

	Print(months);

	months[3] = "March";
	Print(months);

	std::cout << "Month 2 is " << months[2] << std::endl;

	std::cout << "Month 5 is " << (months[5]="May") << std::endl;
	
	Print(months);
}

void Print(const std::map<int, std::string>& map)
{
	std::cout << "Size = " << map.size() << std::endl;

	for (const std::pair<int, std::string>& pair : map)
	{
		std::cout << pair.first << ' ' << pair.second << std::endl;
	}

	std::cout << std::endl;
}