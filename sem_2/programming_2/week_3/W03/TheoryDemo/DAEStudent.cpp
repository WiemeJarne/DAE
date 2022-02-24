#include "pch.h"
#include "DAEStudent.h"
#include<iostream>

DAEStudent::DAEStudent(const std::string& firstName, const std::string& lastName, Major major)
	:Person{firstName, lastName}
	,m_Major{major}
{
	std::cout << "DAEStudent constructor\n";
}

DAEStudent::~DAEStudent()
{
	std::cout << "DAEStudent destructor\n";
}

void DAEStudent::Identify() const
{
	std::cout << "I am a derived student object and my name is: " + GetName() + "\n";
}

std::string DAEStudent::GetName() const
{
	std::string name{ Person::GetName() };
	name += ". My major is ";
	switch (m_Major)
	{
	case DAEStudent::Major::GD:
		name += "Game Development.";
		break;
	case DAEStudent::Major::SD:
		name += "Sound Design.";
		break;
	default:
		name += "an other major";
		break;
	}
	return name;
}