#include "pch.h"
#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
	:m_Numerator{numerator}
	,m_Denominator{denominator}
{
	//no code
}

void Fraction::Draw(const Point2f& pos, float size)
{
	for (int index{}; index < m_Numerator; ++index)
	{
		utils::SetColor(0.f, 0.5f, 1.f);
		utils::FillRect(pos.x + index * size, pos.y, size, size);
	}

	for (int index{}; index < m_Denominator; ++index)
	{
		utils::SetColor(1.f, 1.f, 1.f);
		utils::DrawRect(pos.x + index * size, pos.y, size, size);
	}
	
}

float Fraction::GetValue()
{
	return float(m_Numerator) / m_Denominator;
}