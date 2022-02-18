#include "pch.h"
#include "TrafficLight.h"

TrafficLight::TrafficLight(const Point2f& pos)
	:
{

}

void TrafficLight::DoHitTest(const Point2f& point) const
{

}

void TrafficLight::Update(float elapsedSec)
{
	m_AccumulatedSec += elapsedSec;
	if (m_State == State::off)
	{

	}
	else if (m_AccumulatedSec >= 1
		&& m_State == State::orange)
	{
		m_AccumulatedSec = 0.f;
		m_State = State::red;
	}
	else if (m_AccumulatedSec >= 4
		&& m_State == State::red)
	{
		m_AccumulatedSec = 0.f;
		m_State = State::green;
	}
	else if (m_AccumulatedSec >= 4
		&& m_State == State::green)
	{
		m_AccumulatedSec = 0.f;
		m_State = State::orange;
	}
}

void TrafficLight::Draw() const
{
	
}

float TrafficLight::GetWidth() const
{

}

float TrafficLight::GetHeight() const
{

}