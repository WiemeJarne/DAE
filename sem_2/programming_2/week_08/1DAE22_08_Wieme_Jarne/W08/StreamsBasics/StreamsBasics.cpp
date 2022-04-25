// StreamsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

void PrintInputFromConsole( );
void ReadSentenceFromFile( );
void WriteSentenceToFile(const std::string& sentence);

int main()
{
	//PrintInputFromConsole( );

	ReadSentenceFromFile( );
}

void PrintInputFromConsole( )
{
	std::string sentence{ };
	std::string line{ };

	do
	{
		std::getline(std::cin, line);
		sentence += ' ' + line;
	} while (!(line.find('.') < 100000));

	std::cout << sentence;
}

void ReadSentenceFromFile( )
{
	std::string fileName{ "Resources/SoftwareQuotesInput.txt" };
	std::fstream inputStream{ fileName };

	if (!inputStream)
	{
		std::cout << "Error opening input file: " << fileName << ".\n";
	}
	else
	{
		std::string sentence{ };
		std::string line{ };

		do
		{
			do
			{
				std::getline(inputStream, line);
				sentence += ' ' + line;
			} while (!(line.find('.') < 100000));

			WriteSentenceToFile(sentence);
			sentence = "";

		} while (inputStream);
	}
}

void WriteSentenceToFile(const std::string& sentence)
{
	std::string fileName{ "Resources/SoftwareQuotesOutput.txt" };
	std::ofstream outputStream{ fileName };

	if (!outputStream)
	{
		std::cout << "Error opening the output file: " << fileName << ".\n";
	}
	else
	{
		outputStream << sentence << '\n';
	}
}