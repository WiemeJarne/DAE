#pragma once
#include "utils.h"

class TrafficLight
{
public:
	TrafficLight(const Point2f& pos);
	void DoHitTest(const Point2f& point) const;
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
	State m_State;
	const Point2f m_Position;
	float m_AccumulatedSec;
};

