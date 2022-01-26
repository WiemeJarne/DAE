// precompiled header file
#include "pch.h"

#include <iostream>
#include <string>
#include <ctime>

#include "Core.h"


//int g_Numbers[1000000]{};

int main(int argc, char* args[])
{
	// seed the pseudo random number generator
	srand(unsigned int(time(nullptr)));

	int numberOfElements{ 1000000 };
	int* pNumbers{ nullptr };
	pNumbers = new int[numberOfElements];
	for (int index{}; index < numberOfElements; ++index)
	{
		pNumbers[index] = rand();
		//std::cout << pNumbers[index] << ' ';
	}
	delete[] pNumbers;
	pNumbers = nullptr;

	char cstring[]{ "Sat" };
	std::cout << sizeof(cstring) << cstring << '\n';
	cstring[3] = 'a';
	std::cout << sizeof(cstring) << cstring << '\n';

	std::string name{ "Tesla" };
	const char* pChar{ name.c_str() };
	std::cout << pChar << '\n';
	//pChar[2] = 'q';
	std::cout << name.size() << '\n';

	// Initialize SDL and OpenGL in core.cpp
	Initialize();

	// Event loop
	Run();

	// Clean up SDL and OpenGL in core.cpp
	Cleanup();

	return 0;
}