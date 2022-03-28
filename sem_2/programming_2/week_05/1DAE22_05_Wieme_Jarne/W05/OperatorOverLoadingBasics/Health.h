#pragma once

class Health final
{
public:
	Health( int value); 

	int GetValue( ) const;
	Health& operator+=(const Health& rhs);
	Health& operator-=(const Health & rhs);

private:
	int m_Value;
};

int operator+(int lhs, const Health& rhs);
int operator-(int lhs, const Health& rhs);
Health operator+(Health lhs, const int rhs);
Health operator-(Health lhs, const int rhs);