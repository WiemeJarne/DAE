// Classes2Basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include"Time.h"
#include "Square.h"
#include "Container.h"
#include <iostream>

void TestSquares( );
void CompareTimes(const Time* t1, const Time* t2);
void PrintInstancesCntr(const std::string& message);
void TestContainer();
void PrintContainer(const Container* pContainer);

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

	TestContainer();
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

void TestContainer()
{
	std::cout << "\n-- Container tests --\n";
	// Define a Container object
	const int cap{ 5 };
	std::cout << "Create container with capacity of " << cap << " elements\n";
	Container* pContainer{ new Container{cap} };
	PrintContainer(pContainer);

	// Add some values to the container
	int actNr{ 0 };
	std::cout << "\nPush back of " << (cap - 1) << " elements\n";
	for (int idx{ 1 }; idx < cap; ++idx)
	{
		pContainer->PushBack(rand() % 21);
		++actNr;
	}
	PrintContainer(pContainer);

	std::cout << "\nChange the value of the elements (using Set)\n";
	for (int idx{ 0 }; idx < actNr; ++idx)
	{
		pContainer->Set(idx, rand() % 21);
	}
	PrintContainer(pContainer);

	std::cout << "\nPush back another " << (cap - 1) << " elements\n";
	for (int i{ 1 }; i < cap; ++i)
	{
		pContainer->PushBack(rand() % 21);
		++actNr;
	}
	PrintContainer(pContainer);
	delete pContainer;
}

void PrintContainer(const Container* pContainer)
{
	std::cout << "-- Print container --\n";
	std::cout << "   Capacity: " << pContainer->Capacity() << std::endl;
	std::cout << "   Size: " << pContainer->Size() << std::endl;
	std::cout << "   Get the elements (using Get and Size)\n   ";
	for (int idx{ 0 }; idx < pContainer->Size(); ++idx)
	{
		std::cout << pContainer->Get(idx) << " ";
	}
	std::cout << std::endl;
}