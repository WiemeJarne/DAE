// StreamsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

void PrintInputFromConsole( );
void ReadFile( );
void WriteFile(const std::string& str, const std::string& fileName);

int main()
{
	PrintInputFromConsole( );

	ReadFile( );
}

void PrintInputFromConsole( )
{
	std::string sentence{ };
	std::string line{ };

	while (line.find('.') > line.size())
	{
		std::getline(std::cin, line);

		if (line != "")
		{
			sentence += line + ' ';
		}
	}

	std::cout << sentence;
}

void ReadFile( )
{
	std::string fileName{ "Resources/SoftwareQuotesInput.txt" };
	std::ifstream inputStream{ fileName };

	if (!inputStream)
	{
		std::cout << "Error opening input file: " << fileName << ".\n";
		return;
	}

	std::string textFromFile{ };
	
	while (inputStream)
	{
		std::string sentence{ };
		std::string line{ };

		while ( line.find('.') > line.size( ) && inputStream)
		{
			std::getline(inputStream, line);

			if (line != "")
			{
				sentence += line + ' ';
			}
		}

		textFromFile += sentence + "\n\n";
	} 

	WriteFile(textFromFile, "Resources/SoftwareQuotesOutput.txt");
}

void WriteFile(const std::string& str, const std::string& fileName)
{
	std::ofstream outputStream{ fileName };

	if (!outputStream)
	{
		std::cout << "Error opening the output file: " << fileName << ".\n";
		return;
	}

	outputStream << str;
}