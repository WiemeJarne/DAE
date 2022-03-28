#pragma once
#include <iostream>

class Float2
{
public:
	Float2(float x = 0, float y = 0);

	Float2& operator+=(const Float2& rhs);

	friend std::ostream& operator<<(std::ostream& out, const Float2& rhs);

private:
	float m_X, m_Y;
};

Float2 operator+(Float2 lhs, const Float2& rhs);