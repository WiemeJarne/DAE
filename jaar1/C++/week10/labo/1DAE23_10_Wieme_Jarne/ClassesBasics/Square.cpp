#include "pch.h"
#include "Square.h"
#include <iostream>

Square::Square(float size)
	:m_Size{ size }
{

}

Square::Square(float size, float left, float bottom)
	:m_Left {left}
	,m_Bottom{bottom}
	,m_Size{ size }
{

}

Square::~Square()
{
	std::cout << "Square destructor: release the reslease the resources\n";
}

void Square::Print()
{

}

void Square::Translate(float deltaLeft, float deltaBottom)
{

}

void Square::SetSize(float newSize)
{

}

float Square::GetArea()
{

}

float Square::GetPerimeter()
{

}