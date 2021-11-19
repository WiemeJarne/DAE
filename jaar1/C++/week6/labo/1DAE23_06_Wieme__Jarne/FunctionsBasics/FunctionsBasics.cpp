// FunctionsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "structs.h"
#include <iostream>
#include <chrono>
#include <string>
#include <cmath>

void TestMultiply();
void Print();
void Print(int value, char delimeter);
void Print(char value, char delimeter);
void Print(float value, char delimeter);
void PrintNumbers(int start, int end);
void TestPrintNumbers();
void TestCalcElapsedTime();
void CalcElapsedTime(int start, int end);
void PrintMessage(int numberOfLeadingSpaces = 0);
void TestPrintMessage();
void TestIsEven();
void IsEven(int number);
void IsLeapYear();
void TestLeapYear();
void GetRand(int bottomBoundary, int topBoundary);
void GetRand(float bottomBoundary, float topBoundary);
void TestGetIntRand();
void TestGetFloatRand();
void TestGetDistance();

int Sum(int getal1, int getal2);
int Multiply(int number1, int number2);
int Modulo(int number, int divisor);
float GetDistance(Point2f point1, Point2f point2);
float GetDistance(float point1x, float point1y, float point2x, float point2y);

int main()
{
    srand(time(nullptr));

    /*Sum(50, 30);
    Sum(40, 20);
    Sum(70, 100);

    Print();

    TestMultiply();

    TestPrintNumbers();

    TestCalcElapsedTime();

    TestPrintMessage();

    TestIsEven();

    TestLeapYear();

    TestGetIntRand();

    TestGetFloatRand();*/

    TestGetDistance();
}

int Sum(int getal1, int getal2)
{
    int result = getal1 + getal2;

    return result;
}

void Print(int value, char delimeter)
{
    std::cout << value << delimeter;
}

void Print(char value, char delimeter)
{
    std::cout << value << delimeter;
}

void Print(float value, char delimeter)
{
    std::cout << value << delimeter;
}

void Print()
{
    Print('a', ',');
    Print(20, ',');
    Print(20.f, ',');
}

int Multiply(int number1, int number2)
{
    int product{ number1 * number2 };
    return product;
}

void TestMultiply()
{
    std::cout << "Function that calculates the product of 2 integers\n Give 2 numbers to multiply.";
    
    int number1{};
    int number2{};
    int number3{};
    int number4{};

    std::cin >> number1 >> number2;
    std::cout << number1 << " * " << number2 << " = " << Multiply(number1, number2) << "\nGive 4 numbers to multiply.";

    std::cin >> number1 >> number2 >> number3 >> number4;
    std::cout << number1 << " * " << number2 << " * " << number3 << " * " << number4 << " = " << Multiply(Multiply(number1, number2), Multiply(number3, number4));
}

int Modulo(int number, int divisor)
{
    int result{ number - ( ( number / divisor ) * divisor ) };
    return result;
}

void PrintNumbers(int start, int end)
{
    std::cout << "Interval [" << start << ", " << end << "]\n";

    while (start <= end)
    {
        std::cout << start << ' ';
        ++start;
    }

    std::cout << '\n';
}

void TestPrintNumbers()
{
    std::cout << "Function that prints the integers in a given interval\n";

    PrintNumbers(10, 20);
    PrintNumbers(90, 115);
}

void CalcElapsedTime(int start, int end)
{
    std::chrono::steady_clock::time_point startTime{ std::chrono::steady_clock::now() };

    PrintNumbers(start, end);

    std::chrono::steady_clock::time_point endTime{ std::chrono::steady_clock::now() };
    std::chrono::duration<float, std::milli> elapsedTime{ endTime - startTime };

    std::cout << "This print task took " << elapsedTime.count() << " milliseconds\n";
}

void TestCalcElapsedTime()
{
    std::cout << "Function that counts the time of a printing task.\n";

    CalcElapsedTime(0, 30);
    CalcElapsedTime(0, 400);
}

void PrintMessage(int numberOfLeadingSpaces)
{
    std::string indentation{ std::to_string(numberOfLeadingSpaces) + " spaces indentation specified" };

    if (numberOfLeadingSpaces == 0)
    {
        std::cout << "No indentation specified\n";
    }
    else
    {
        for (int numberOfspaces{}; numberOfspaces < numberOfLeadingSpaces; ++numberOfspaces)
        {
            indentation = " " + indentation;
        }
        std::cout << indentation << '\n';
    }
   
}

void TestPrintMessage()
{
    std::cout << "Function that prints an indented message\n";
    
    PrintMessage();
    PrintMessage(2);
    PrintMessage(4);
}

void IsEven(int number)
{
    if (number % 2 == 0)
    {
        std::cout << number << " is even\n";
    }
    else
    {
        std::cout << number << "is odd\n";
    }
}

void TestIsEven()
{
    IsEven(41);
    IsEven(18467);
    IsEven(6334);
    IsEven(26500);
    IsEven(19169);
}

void IsLeapYear()
{
    int year{};
    std::cout << "Year? ";
    std::cin >> year;

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                std::cout << year << " has 29 days in February";
            }
            else
            {
                std::cout << year << " has 28 days in February";
            }
        }
        else
        {
            std::cout << year << " has 29 days in February";
        }
    }
    else
    {
        std::cout << year << " has 28 days in February";
    }
}

void TestLeapYear()
{
    IsLeapYear();
}

void GetRand(int bottomBoundary, int topBoundary)
{
    int randInt{ rand() % int(topBoundary + 1) + bottomBoundary };
    std::cout << "In [" << bottomBoundary << ", " << topBoundary << "] " << randInt << '\n';
}

void GetRand(float bottomBoundary, float topBoundary)
{
    float randFloat{ float((rand() % int((topBoundary * 10 - 10)) + int(bottomBoundary * 10)) / 10.f) };
    std::cout << "In [" << bottomBoundary << ", " << topBoundary << "] " << randFloat << '\n';
}

void TestGetIntRand()
{
    GetRand(2, 54);
    GetRand(67, 365);
}

void TestGetFloatRand()
{
    GetRand(2.f, 54.f);
    GetRand(67.f, 365.f);
}

float GetDistance(Point2f point1, Point2f point2)
{
    return sqrtf(float(pow((point2.x - point1.x), 2) + pow((point2.y - point1.y), 2)));
}
float GetDistance(float point1x, float point1y, float point2x, float point2y)
{
    return sqrt(float(pow((point2x - point1x), 2) + pow((point2y - point1y), 2)));
}

void TestGetDistance()
{
    std::cout << "Function that calculates between 2 points\n";

    Point2f point1(0.41f, 184.67f);
    Point2f point2(63.34f, 265.00f);

    std::cout << "Distance between [0.41, 184.67] and [63.34, 265.00]\nCalling one version: "
              << GetDistance(point1, point2) << "\nCalling the other version: "
              << GetDistance(0.41f, 184.67f, 63.34f, 265.00f);

    point1 = Point2f(191.69f, 157.24f);
    point2 = Point2f(114.78f, 293.58f);

    std::cout << "\n\nDistance between [191.69, 157.24] and [114.78, 293.58]\nCalling one version: "
              << GetDistance(point1, point2) << "\nCalling the other version: "
              << GetDistance(191.69f, 157.24f, 114.78f, 293.58f);
}