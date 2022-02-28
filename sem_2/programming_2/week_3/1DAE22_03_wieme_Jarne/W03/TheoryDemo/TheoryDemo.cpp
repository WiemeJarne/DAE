// TheoryDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Person.h"
#include "DAEStudent.h"

int main()
{
	Person* pPerson{ new Person{"Dan", "Ackroyd"}};
	pPerson->Identify();
	delete pPerson;

	std::cout << "\n\n";

	DAEStudent* pStudent{ new DAEStudent{"Jarne", "Wieme", DAEStudent::Major::GD} };
	pStudent->Identify();
	delete pStudent;
}