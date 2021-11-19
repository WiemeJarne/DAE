// Wieme, Jarne - 1DAE23
// Variables2Basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>

void EvenOrOd();
void RandomNumberGenarator();
void InputLetterPrintASCIIValue();
void RandomLetterGenarator();
void RoundFloatAndTypeCastFloatToInt();
void AspectRatioOfFullHD();
void PrefixAndPostfix();
void ExploreStrings();
void StringConcatenation();
void ConvertingNumbersTostrings();
void ConvertingStringsToNumber();

int main()
{
	srand(time(nullptr));

	RoundFloatAndTypeCastFloatToInt();

	RandomNumberGenarator();

	InputLetterPrintASCIIValue();

	RandomLetterGenarator();

	AspectRatioOfFullHD();

	PrefixAndPostfix();

	ExploreStrings();

	StringConcatenation();

	ConvertingNumbersTostrings();

	ConvertingStringsToNumber();
}

void EvenOrOd()
{
	std::cout << "Give a number. If the number is even '0' will be printed and if the number is odd '1' will be printed." << std::endl;

	int number{ 0 };

	std::cin >> number;

	int evenOrOdd = number % 2;

	std::cout << evenOrOdd << std::endl << std::endl;
}

void RandomNumberGenarator()
{
	// random number in interval: [0,50]
	int randomNumber = rand() % 51;
	std::cout << randomNumber << std::endl << std::endl;

	// random number in interval: [10, 80]
	randomNumber = rand() % 70 + 10;
	std::cout << randomNumber << std::endl << std::endl;

	// random number in interval: [-20, 20]
	randomNumber = rand() % 40 - 20;
	std::cout << randomNumber << std::endl << std::endl;

	// random number in interval: [-2, 2]
	randomNumber = rand() % 4 - 2;
	std::cout << randomNumber << std::endl << std::endl;

	// random number in interval: [5.00, 10.00]
	float randomNumberF = float((rand() %  500 + 500 ) / 100.f);
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	std::cout << randomNumberF << std::endl << std::endl;

	//random number in interval: [5.00, 10.00]
	randomNumberF = float( rand() % 10 - 5);
	std::cout << std::setprecision(2);
	std::cout << randomNumberF << std::endl << std::endl;
}

void InputLetterPrintASCIIValue()
{
	std::cout << "Type a Letter" << std::endl;

	char letter{};
	std::cin >> letter;

	std::cout << "ASCII value of letter " << letter << " is " << int(letter) << std::endl << std::endl;
}

void RandomLetterGenarator()
{
	int randomLetter = rand() % 25 + ('a');

	std::cout << "Random letter " << char( randomLetter ) << ". ASCII value: " << randomLetter << std::endl << std::endl;
}

void RoundFloatAndTypeCastFloatToInt()
{
	float f1 = 5.44f, f2 = 5.45f, f3 = 5.51f;

	std::cout << f1 << ", rounded: " << round(f1) << ", int cast: " << int(f1) << std::endl;
	std::cout << f2 << ", rounded: " << round(f2) << ", int cast: " << int(f2) << std::endl;
	std::cout << f3 << ", rounded: " << round(f3) << ", int cast: " << int(f3) << std::endl << std::endl;
}

void AspectRatioOfFullHD()
{
	std::cout << "The aspect ratio of full HD (1920 x 1080) is: " << 1920.f / 1080 << std::endl << std::endl;
}

void PrefixAndPostfix()
{
	int i{ 10 };
	int j{ ++i };
	std::cout << "i: " << i << ", j: " << j << std::endl;

	int k{ 10 };
	int l{ k++ };
	std::cout << "k: " << k << ", l: " << l << std::endl << std::endl;
}

void ExploreStrings()
{
	std::string string;

	std::cout << string;

	std::string stringLiteral{ "I am a string literal" };

	std::cout << stringLiteral << std::endl;

	stringLiteral = "stringLiteral";

	std::cout << stringLiteral << std::endl;

	std::cout << "Enter text without spaces ";

	std::string text{ "" };
	std::cin >> text;

	std::cout << text << std::endl << std::endl;
}

void StringConcatenation()
{
	std::string FirstWord{ "" };
	std::string SecondWord{ "" };

	std::cout << "First word? ";
	std::cin >> FirstWord;
	std::cout << std::endl;

	std::cout << "Second word? ";
	std::cin >> SecondWord;
	std::cout << std::endl;

	std::cout << FirstWord + SecondWord << std::endl << std::endl;

	std::string string1{ "stringType" };
	std::cout << string1 + "stringliteral" << std::endl;

	char char1{ 'c' };
	std::cout << char1 + string1 << std::endl;

	std::cout << 'c' + string1 << std::endl << std::endl;
}

void ConvertingNumbersTostrings()
{
	std::string numbersLog{ "" };
	int enteredNr{};

	std::cout << "Enter an integer value: " << std::endl;
	std::cin >> enteredNr;
	std::string string2 = std::to_string(enteredNr);
	numbersLog = string2 + " ";

	std::cout << "Enter an integer value: " << std::endl;
	std::cin >> enteredNr;
	string2 = std::to_string(enteredNr);
	numbersLog += string2 + " ";

	std::cout << "Enter an integer value: " << std::endl;
	std::cin >> enteredNr;
	string2 = std::to_string(enteredNr);
	numbersLog += string2;

	std::cout << "Log of entered numbers: " << numbersLog << std::endl << std::endl;
}

void ConvertingStringsToNumber()
{
	std::string string3{ "3" };
	std::string string4{ "3.1415" };

	std::cout << "One string contains " << string3 << std::endl;
	std::cout << "Other string contains " << string4 << std::endl;
	
	std::cout << "Adding string " << string3 + string4 << std::endl;

	std::cout << std::setprecision(4);
	std::cout << "Adding numbers " << std::stoi(string3) + std::stof(string4) << std::endl;
}
