#include "pch.h"
#include "Health.h"

Health::Health( int value) 
	: m_Value{value}
{
}
int Health::GetValue( ) const
{
	return m_Value;
}

Health& Health::operator+=(const Health& rhs)
{
	m_Value += rhs.GetValue();
	return *this;
}

Health& Health::operator-=(const Health& rhs)
{
	m_Value += -rhs.GetValue();
	return *this;
}

int operator+(int lhs, const Health& rhs)
{
	lhs += rhs.GetValue();
	return lhs;
}

int operator-(int lhs, const Health& rhs)
{
	lhs -= rhs.GetValue();
	return lhs;
}

Health operator+(Health lhs, const int rhs)
{
	lhs += Health(rhs);
	return lhs;
}

Health operator-(Health lhs, const int rhs)
{
	lhs -= Health(rhs);
	return lhs;
}