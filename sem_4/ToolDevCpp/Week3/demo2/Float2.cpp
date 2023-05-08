#include "Float2.h"

Float2::Float2(float x, float y)
	: m_x{ x }
	, m_y{ y }
{}

float Float2::GetX()
{
	return m_x;
}

float Float2::GetY()
{
	return m_y;
}