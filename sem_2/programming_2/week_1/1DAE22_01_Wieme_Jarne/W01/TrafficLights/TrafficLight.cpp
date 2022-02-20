#include "pch.h"
#include "TrafficLight.h"
#include "utils.h"
#include <iostream>

TrafficLight::TrafficLight(const Point2f& pos)
	:m_State{State::off}
	,m_Position{ pos }
	,m_AccumulatedSec{ 0.f }
	,m_TrafficLightRect{pos.x, pos.y, 80.f, 220.f}
	,m_Radius{30.f}
	,m_Black{0.f, 0.f, 0.f, 1.f}
	,m_Grey{204/255.f, 204 / 255.f, 204 / 255.f, 1.f}
	,m_Red{1.f, 0.f, 0.f, 1.f}
	,m_Orange{1.f, 0.5f, 0, 1.f}
	,m_Green{0.f, 1.f, 0.f, 1.f}
{
	InitEllipsef();
}

void TrafficLight::DoHitTest(const Point2f& point)
{
	if (m_State == State::off)
	{
		if (utils::IsPointInCircle(point, m_GreenLight))
		{
			m_State = State::green;
		}
		else if (utils::IsPointInCircle(point, m_OrangeLight))
		{
			m_State = State::orange;
		}
		else if (utils::IsPointInCircle(point, m_RedLight))
		{
			m_State = State::red;
		}
	}
	else if ( !utils::IsPointInCircle(point, m_GreenLight)
			  && !utils::IsPointInCircle(point, m_OrangeLight)
			  && !utils::IsPointInCircle(point, m_RedLight)
			  && utils::IsPointInRect(point, m_TrafficLightRect)) 
	{
		m_State = State::off;
		m_AccumulatedSec = 0.f;
	}
}

void TrafficLight::Update(float elpasedSec)
{
	if (m_State != State::off) m_AccumulatedSec += elpasedSec;

	if (m_State == State::green && m_AccumulatedSec >= 4.f)
	{
		m_State = State::orange;
		m_AccumulatedSec = 0.f;
	}
		
	else if (m_State == State::orange && m_AccumulatedSec >= 1.f) 
	{
		m_State = State::red;
		m_AccumulatedSec = 0.f;
	}

	else if (m_State == State::red && m_AccumulatedSec >= 4.f)
	{
		m_State = State::green;
		m_AccumulatedSec = 0.f;
	}
}

void TrafficLight::Draw() const
{
	utils::SetColor(m_Black);
	utils::FillRect(m_TrafficLightRect);

	utils::SetColor(m_Grey);
	utils::FillEllipse(m_GreenLight.center, m_Radius, m_Radius);
	utils::FillEllipse(m_OrangeLight.center, m_Radius, m_Radius);
	utils::FillEllipse(m_RedLight.center, m_Radius, m_Radius);

	if (m_State == State::green)
	{
		utils::SetColor(m_Green);
		utils::FillEllipse(m_GreenLight.center, m_Radius, m_Radius);
	}
	else if (m_State == State::orange)
	{
		utils::SetColor(m_Orange);
		utils::FillEllipse(m_OrangeLight.center, m_Radius, m_Radius);
	}
	else if (m_State == State::red)
	{
		utils::SetColor(m_Red);
		utils::FillEllipse(m_RedLight.center, m_Radius, m_Radius);
	}
}

float TrafficLight::GetWidth() const
{
	return m_TrafficLightRect.width;
}

float TrafficLight::GetHeight() const
{
	return m_TrafficLightRect.height;
}

void TrafficLight::InitEllipsef()
{
	const float spaceBetweenLamps{ 10.f };
	int lightNumber{1};

	m_GreenLight.radius = m_Radius;
	m_GreenLight.center = Point2f{ m_TrafficLightRect.left + m_TrafficLightRect.width / 2.f,
								   m_TrafficLightRect.bottom + m_Radius + spaceBetweenLamps  };
	++lightNumber;

	m_OrangeLight.radius = m_Radius;
	m_OrangeLight.center = Point2f{ m_TrafficLightRect.left + m_TrafficLightRect.width / 2.f,
									m_TrafficLightRect.bottom + 3 * m_Radius + 2 * spaceBetweenLamps };
	++lightNumber;

	m_RedLight.radius = m_Radius;
	m_RedLight.center = Point2f{ m_TrafficLightRect.left + m_TrafficLightRect.width / 2.f,
								 m_TrafficLightRect.bottom + 5 * m_Radius + 3 * spaceBetweenLamps };
	++lightNumber;
}