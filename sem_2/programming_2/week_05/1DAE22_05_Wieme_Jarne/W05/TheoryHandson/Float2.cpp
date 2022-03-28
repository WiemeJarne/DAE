#include "pch.h"
#include "Float2.h"

Float2::Float2(float x, float y)
	:m_X{ x }
	,m_Y{ y }
{
}

Float2& Float2::operator+=(const Float2& rhs)
{
	m_X += rhs.m_X;
	m_Y += rhs.m_Y;
	return *this;
}

Float2 operator+(Float2 lhs, const Float2& rhs)
{
	lhs += rhs;
	return lhs;
}

std::ostream& operator<<(std::ostream& out, const Float2& rhs)
{
	out << "( " << rhs.m_X << " , " << rhs.m_Y << " )";
	return out;
}