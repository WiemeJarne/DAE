#pragma once
#include "structs.h"
#include "utils.h"

class TrafficLight
{
public:
	TrafficLight(const Point2f& pos);
	void DoHitTest(const Point2f& point);
	void Update(float elapsedSec);
	void Draw() const;
	float GetWidth() const;
	float GetHeight() const;

private:
	enum class State
	{
		green,
		orange,
		red,
		off
	};

	Circlef m_RedLight;
	Circlef m_OrangeLight;
	Circlef m_GreenLight;
	State m_State;
	Point2f m_Position;
	float m_AccumulatedSec;
	const Rectf m_TrafficLightRect;
	const float m_Radius;
	Color4f m_Black;
	Color4f m_Grey;
	Color4f m_Red;
	Color4f m_Orange;
	Color4f m_Green;

	void InitEllipsef();
};

