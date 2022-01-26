#include "pch.h"
#include "BouncingCircle.h"
#include "utils.h"
BouncingCircle::BouncingCircle(float windowWidth, float windowHeight)
	: m_WindowWidth{windowWidth}, m_WindowHeight{windowHeight}
	, m_CircleColor{ Color4f{ rand() % 256 / 255.0f,rand() % 256 / 255.0f,rand() % 256 / 255.0f,1 } }
	, m_CirclePosition{ Point2f{ 100, 100 } }
	, m_MaxSpeed{ 500 }, m_MinSpeed{ 250 }
	, m_CircleRadius{ 50 }
{
	m_CircleSpeedX = rand() % (int(m_MaxSpeed - m_MinSpeed) + 1) - m_MinSpeed;
	m_CircleSpeedY = rand() % (int(m_MaxSpeed - m_MinSpeed) + 1) - m_MinSpeed;
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
	if (m_CirclePosition.x - m_CircleRadius <= 0 && m_CircleSpeedX < 0) m_CircleSpeedX *= -1;

	if (m_CirclePosition.x + m_CircleRadius >= m_WindowWidth && m_CircleSpeedX > 0) m_CircleSpeedX *= -1;

	if (m_CirclePosition.y - m_CircleRadius <= 0 && m_CircleSpeedY < 0) m_CircleSpeedY *= -1;

	if (m_CirclePosition.y + m_CircleRadius >= m_WindowHeight && m_CircleSpeedY > 0) m_CircleSpeedY *= -1;
}