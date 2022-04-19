#include "pch.h"
#include "Ball.h"
#include "Texture.h"
#include "utils.h"

Ball::Ball(const Point2f& pos, float radius, float velocityY)
	:m_Shape{ pos, radius, radius }
	,m_VelocityY{ velocityY }
{
	int randNr{ rand() % 11 };

	if (randNr < 9)
	{
		m_Type = Type::neutral;
	}
	else if (randNr == 9)
	{
		m_Type = Type::growHand;
	}
	else
	{
		m_Type = Type::danger;
	}
}

Ball& Ball::operator=(const Ball& rhs)
{
	if (&rhs != this)
	{
		m_Shape = rhs.m_Shape;
		m_Type = rhs.m_Type;
		m_VelocityY = rhs.m_VelocityY;
	}

	return *this;
}

void Ball::Update(float elapsedSec)
{
	m_Shape.center.y -= m_VelocityY * elapsedSec;
}

void Ball::Draw( ) const
{
	switch (m_Type)
	{
	case Ball::Type::neutral:
		utils::SetColor(Color4f{ 1.f, 1.f, 1.f, 1.f });
		break;

	case Ball::Type::danger:
		utils::SetColor(Color4f{ 0.f, 0.f, 1.f, 1.f });
		break;

	case Ball::Type::growHand:
		utils::SetColor(Color4f{ 1.f, 0.f, 0.f, 1.f });
		break;
	}

	utils::FillEllipse(m_Shape);
}

bool Ball::IsOverlapping(const Circlef& hand) const
{
	Circlef ball{ m_Shape.center, m_Shape.radiusX };

	if (utils::IsOverlapping(hand, ball))
	{
		return true;
	}
	

	return false;
}

bool Ball::IsOutOfWindow() const
{
	if (m_Shape.center.y + m_Shape.radiusX < 0.f)
	{
		return true;
	}

	return false;
}

Ellipsef Ball::GetShape( ) const
{
	return m_Shape;
}

Ball::Type Ball::GetType( ) const
{
	return m_Type;
}