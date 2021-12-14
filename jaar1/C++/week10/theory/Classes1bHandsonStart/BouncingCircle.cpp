#include "pch.h"
#include "BouncingCircle.h"
#include "utils.h"
#include <iostream>

BouncingCircle::BouncingCircle(const Rectf& boundingRect)
	: BouncingCircle{ boundingRect, 50.f, Point2f{100, 100} } //constructor delegation
{	 
}

BouncingCircle::BouncingCircle(const Rectf& boundingRect, float radius, const Point2f& position)
	: m_BoundingRect{ boundingRect }
	, m_CircleColor{ Color4f{ rand() % 256 / 255.0f,rand() % 256 / 255.0f,rand() % 256 / 255.0f,1 } }
	, m_CirclePosition{ position }
	, m_MaxSpeed{ 500 }, m_MinSpeed{ 250 }
	, m_CircleRadius{ radius }
{
	m_CircleSpeedX = rand() % (int(m_MaxSpeed - m_MinSpeed) + 1) - m_MinSpeed;
	m_CircleSpeedY = rand() % (int(m_MaxSpeed - m_MinSpeed) + 1) - m_MinSpeed;
}

BouncingCircle::~BouncingCircle()
{
	std::cout << "Destructor executed\n";
}

void BouncingCircle::DrawCircle()
{
	utils::SetColor(m_CircleColor);
	utils::FillEllipse(m_CirclePosition, m_CircleRadius, m_CircleRadius);
}

void BouncingCircle::UpdateCircle(float elapsedSec)
{
	m_CirclePosition.x += m_CircleSpeedX * elapsedSec;
	m_CirclePosition.y += m_CircleSpeedY * elapsedSec;
	CheckCollisionCircle();
}

void BouncingCircle::CheckCollisionCircle()
{
	if (m_CirclePosition.x - m_CircleRadius <= m_BoundingRect.left && m_CircleSpeedX < 0) m_CircleSpeedX *= -1;

	if (m_CirclePosition.x + m_CircleRadius >= m_BoundingRect.left + m_BoundingRect.width && m_CircleSpeedX > 0) m_CircleSpeedX *= -1;

	if (m_CirclePosition.y - m_CircleRadius <= m_BoundingRect.bottom && m_CircleSpeedY < 0) m_CircleSpeedY *= -1;

	if (m_CirclePosition.y + m_CircleRadius >= m_BoundingRect.bottom + m_BoundingRect.height && m_CircleSpeedY > 0) m_CircleSpeedY *= -1;
}