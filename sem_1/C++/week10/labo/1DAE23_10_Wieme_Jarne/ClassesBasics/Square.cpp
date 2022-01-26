#include "pch.h"
#include "Square.h"
#include <iostream>

Square::Square(float size)
	:m_Size{ size }
	, m_Left{ 50 }
	, m_Bottom{ 50 }
{
	//no code
}


Square::Square(float size, float left, float bottom)
	:m_Left {left}
	, m_Bottom{ bottom }
	, m_Size{ size }
{
	//no code
}

Square::~Square()
{
	std::cout << "Square destructor: release the reslease the resources\n";
}

void Square::Print()
{
	std::cout << "Left: " << m_Left << ", bottom: " << m_Bottom << '\n';
	std::cout << "Size: " << m_Size << "\n";
	std::cout << "Perimeter: " << GetPerimeter() << '\n';
	std::cout << "Area: " << GetArea() << "\n";
}

void Square::Translate(float deltaLeft, float deltaBottom)
{
	m_Left += deltaLeft;
	m_Bottom += deltaBottom;
}

void Square::SetSize(float newSize)
{
	m_Size = newSize;
}

float Square::GetArea()
{
	return powf(m_Size, 2);
}

float Square::GetPerimeter()
{
	return m_Size * 4;
}