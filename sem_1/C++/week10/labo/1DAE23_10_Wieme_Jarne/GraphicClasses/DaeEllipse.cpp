#include "pch.h"
#include "DaeEllipse.h"
#include "utils.h"
#include <iostream>

DaeEllipse::DaeEllipse(const Point2f& center, float radX, float radY, const Color4f& fillcolor)
	:m_Center{center}
	,m_RadX{radX}
	,m_RadY{radY}
	,m_FillColor{fillcolor}
	,m_IsActive{false}
{
	m_Area = GetArea();
}

void DaeEllipse::Draw()
{
	if (m_IsActive == true) m_FillColor.a = 1.f;
	else m_FillColor.a = 0.5f;

	utils::SetColor(m_FillColor);
	utils::FillEllipse(m_Center, m_RadX, m_RadY);
}

void DaeEllipse::ActivateTests(const Point2f& pos)
{
	if (powf(pos.x - m_Center.x, 2) / pow(m_RadX, 2) + powf(pos.y - m_Center.y, 2) / pow(m_RadY, 2) <= 1)
	{
		if (m_IsActive == false) std::cout << "Area of this activated ellipse is " << m_Area << '\n';
		m_IsActive = true;
	}
	else
	{
		m_IsActive = false;
	}
}

float DaeEllipse::GetArea()
{
	return float(M_PI * m_RadX * m_RadY);
}