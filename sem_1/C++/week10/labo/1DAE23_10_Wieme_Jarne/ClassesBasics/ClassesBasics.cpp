// Wieme Jarne 1GD23N
// ClassesBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Square.h"
#include "Time.h"
#include <iostream>

void DoSquareTests();
void TestSquare(Square* ptrSquare);
void DoTimeTests();

int main()
{
	DoSquareTests();
	DoTimeTests();
}

void DoSquareTests()
{
	Square* ptrSquare1{ new Square{25.f} };
	Square* ptrSquare2{ new Square{50.f, 25.f, 65.f} };

	/*std::cout << ptrSquare1 << '\n';
	delete ptrSquare1;
	ptrSquare1 = nullptr;
	std::cout << ptrSquare1 << '\n';

	std::cout << ptrSquare2 << '\n';
	delete ptrSquare2;
	ptrSquare2 = nullptr;
	std::cout << ptrSquare2 << '\n';*/

	ptrSquare1->Print();
	ptrSquare2->Print();

	ptrSquare1->SetSize(125.f);
	ptrSquare2->Translate(25.f, 40.f);

	ptrSquare1->Print();
	ptrSquare2->Print();

	TestSquare(ptrSquare1);

	delete ptrSquare1, ptrSquare2;
}

void TestSquare(Square* ptrSquare)
{
	ptrSquare->Translate(45, 53);
}

void DoTimeTests()
{
	Time* ptrTime1{ new Time{20} };
	Time* ptrTime2{ new Time{16, 20} };
	Time* ptrTime3{ new Time{23,16,20} };

	ptrTime1->Print();
	ptrTime2->Print();
	ptrTime3->Print();

	ptrTime1->AddHours(5);
	ptrTime2->AddMinutes(23);
	ptrTime3->AddSeconds(436);

	ptrTime1->Print();
	ptrTime2->Print();
	ptrTime3->Print();

	delete ptrTime1, ptrTime2, ptrTime3;
}