// Classes2Basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include"Time.h"
#include "Square.h"
#include <iostream>

void TestSquares( );
void CompareTimes(const Time* t1, const Time* t2);
void PrintInstancesCntr(const std::string& message);

int main( )
{
    TestSquares( );

    PrintInstancesCntr("Before creating a Time object: ");

    Time* t1{ new Time(11, 30, 20) };
    Time* t2{ new Time(7, 40, 40) };

    PrintInstancesCntr("After creating 2 Time objects: ");

    CompareTimes(t1, t1);

    CompareTimes(t1, t2);

    delete t1;
    t1 = nullptr;
    delete t2;
    t2 = nullptr;

    PrintInstancesCntr("After deleting 2 Time objects: ");
}

void TestSquares( )
{
    Square* testSqaure{ new Square(10.f) };
    testSqaure->Print();

    std::cout << std::endl;

    Square* testSquare2{ new Square(10.f, 20.f, 30.f) };
    testSquare2->Print();

    std::cout << std::endl;
}

void CompareTimes(const Time* t1, const Time* t2)
{
    t1->Print();
    t2->Print();

    if (    t1->GetHours() == t2->GetHours()
         && t1->GetMinutes() == t2->GetMinutes()
         && t1->GetSeconds() == t2->GetSeconds() )
    {
        std::cout << "They are equal\n";
    }
}

void PrintInstancesCntr(const std::string& message)
{
    std::cout << message << Time::GetNrInstaces() << std::endl;
}