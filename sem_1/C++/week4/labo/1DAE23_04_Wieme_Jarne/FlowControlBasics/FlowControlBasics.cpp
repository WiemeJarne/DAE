// FlowControlBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include "structs.h"

void CompareTwoNumbers();
void Calculateprice();
void ConvertDayNumber();
void CheckForLeapYear();
void ConvertSeconds();
void ScopedEnumerations();
void UsingTheStructPoint2f();

int main()
{
	srand(time(nullptr));
	/*CompareTwoNumbers();
	Calculateprice();
	ConvertDayNumber();
	CheckForLeapYear();
	ConvertSeconds();
	ScopedEnumerations();*/
	UsingTheStructPoint2f();

}

void CompareTwoNumbers()
{
	int number1{ rand() % 11 };
	int number2{ rand() % 11 };

	std::cout << "The first number is " << number1;
	std::cout << "\nThe second number is " << number2;

	if (number1 > number2)
	{
		std::cout << "\nThe first number is greater then the second number.";
	}

	if (number1 == number2)
	{
		std::cout << "\nThe 2 numbers are equal.";
	}

	if (number1 < number2)
	{
		std::cout << "\nThe first number is smaller then the second number.";
	}
}

void Calculateprice()
{
	int numberOfBallpoints{};
	float price{};

	std::cout << "\n\nNumber of ballpoints? ";
	std::cin >> numberOfBallpoints;

	if (numberOfBallpoints <= 19)
	{
		price = numberOfBallpoints * 4.00f;
		std::cout << "\nThe total price is " << price;
	}

	if (numberOfBallpoints >= 20 && numberOfBallpoints <= 49)
	{
		price = numberOfBallpoints * 3.50f;
		std::cout << "\nThe total price is " << price;
	}

	if (numberOfBallpoints >= 50 && numberOfBallpoints <= 100)
	{
		price = numberOfBallpoints * 3.25f;
		std::cout << "\nThe total price is " << price;
	}

	if (numberOfBallpoints >= 101)
	{
		price = numberOfBallpoints * 3.10f;
		std::cout << "\nThe total price is " << price;
	}
}

void ConvertDayNumber()
{
	int dayNumber{};

	std::cout << "\n\nDay number [1, 7]? ";
	std::cin >> dayNumber;

	if (dayNumber == 1)
	{
		std::cout << "\nStart of the week";
	}

	else if (dayNumber >= 2 && dayNumber <= 4)
	{
		std::cout << "\nMiddle of the week";
	}
	
	else if (dayNumber == 5)
	{
		std::cout << "\nNearly weekend";
	}

	else if (dayNumber == 6 || dayNumber == 7)
	{
		std::cout << "\nweekend";
	}
	else
	{
		std::cout << "\nWrong day number";
	}

	switch(dayNumber)
	{
	case 1:
		std::cout << "\nMonday";
		break;
	case 2:
		std::cout << "\nTuesday";
		break;
	case 3:
		std::cout << "\nWednesday";
		break;
	case 4:
		std::cout << "\nThursday";
		break;
	case 5:
		std::cout << "\nFriday";
		break;
	case 6:
		std::cout << "\nSaterday";
		break;
	case 7:
		std::cout << "\nSunday";
		break;
	}
}

void CheckForLeapYear()
{
	int year{};

	std::cout << "\n\nYear? ";
	std::cin >> year;

	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				std::cout << '\n' << year << ": " << 29;
			}
			else
			{
				std::cout << '\n' << year << ": " << 28;
			}
		}
		else
		{
			std::cout << '\n' << year << ": " << 29;
		}
		
	}
	else
	{
		std::cout << '\n' << year << ": " << 28;
	}
}

void ConvertSeconds()
{
	int numberOfSeconds{};
	
	std::cout << "\n\nNumbers of seconds? ";
	std::cin >> numberOfSeconds;

	std::cout << '\n' << (numberOfSeconds / 86400) << " days";
	numberOfSeconds = numberOfSeconds  % 86400;

	std::cout << '\n' << (numberOfSeconds / 3600) << " hours";
	numberOfSeconds = numberOfSeconds % 3600;

	std::cout << '\n' << (numberOfSeconds / 60) << " minutes";
	numberOfSeconds = numberOfSeconds % 60;

	std::cout << '\n' << numberOfSeconds << " seconds";
}

void ScopedEnumerations()
{
	enum class ActorState { running, flying, falling };

	int randomValue{ rand() % 4 };

	ActorState actor{ ActorState(randomValue) };

	switch (actor)
	{
	case ActorState::running:
		std::cout << "\n\nThe actor is running.";
		break;
	case ActorState::flying:
		std::cout << "\n\nThe actor is flying.";
		break;
	case ActorState::falling:
		std::cout << "\n\nThe actor is falling";
		break;
	}
}

void UsingTheStructPoint2f()
{
	Point2f p1;
	Point2f p2{};
	Point2f p3{ 26, 25 };

	std::cout << "\n\nValues after definition" << "\np2: [" << p2.x << ", " << p2.y << ']'
											   << "\np3: [" << p3.x << ", " << p3.y << ']';

	p1.x = 20;
	p1.y = 3;

	p2 = Point2f{ 30,40 };

	++p3.x;
	--p3.y;

	std::cout << "\n\nValues after changing the members" << "\np2: [" << p1.x << ", " << p1.y << ']'
														 << "\np3: [" << p2.x << ", " << p2.y << ']'
														 << "\np3: [" << p3.x << ", " << p3.y << ']';
}