#pragma once
#include "structs.h"
class BouncingCircle
{
public: // access specifiers
	BouncingCircle(const Rectf& boundingRect);
	BouncingCircle(const Rectf& boundingRect, float radius, const Point2f& position);
	~BouncingCircle();
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
	//float m_WindowWidth, m_WindowHeight;
	Rectf m_BoundingRect;
};
