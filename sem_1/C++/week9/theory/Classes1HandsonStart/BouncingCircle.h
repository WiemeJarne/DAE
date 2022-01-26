#pragma once
#include "structs.h"

class BouncingCircle
{
public:
	BouncingCircle(float windowWidth, float windowHeight);
	void DrawCircle();
	void UpdateCircle(float elapsedSec);
private:

	void CheckCollisionCircle();
	Color4f m_CircleColor;
	Point2f m_CirclePosition;
	float m_CircleSpeedX;
	float m_CircleSpeedY;
	float m_CircleRadius;
	const float m_MaxSpeed, m_MinSpeed;
	float m_WindowWidth, m_WindowHeight;
};