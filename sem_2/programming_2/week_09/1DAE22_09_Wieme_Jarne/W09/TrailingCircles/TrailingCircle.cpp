#include "pch.h"
#include <cmath>
#include "TrailingCircle.h"
#include "utils.h"


TrailingCircle::TrailingCircle( float radius, const Point2f& center )
	: m_Radius{ radius } 
	, m_Center{ center }
	, m_Color{ GetRandomColor( ) }
	, m_Velocity(GetRandomVelocity( ) )
	, m_AccumTime{ }
{
}

void TrailingCircle::Update( float elapsedSec, const Rectf& boundingRect )
{
	m_AccumTime += elapsedSec;

	if (m_AccumTime >= 0.08f)
	{
		m_AccumTime = 0.f;

		m_Trail.push_back(m_Center);

		if (m_Trail.size( ) > 10)
		{
			m_Trail.pop_front( );
		}
	}
	
	// Calculate new position
	Vector2f centerVector{ m_Center };
	centerVector += m_Velocity * elapsedSec;
	m_Center = centerVector.ToPoint2f( );

	// Handle reflection against bounding rectangle
	if ( m_Velocity.x > 0 && m_Center.x + m_Radius > boundingRect.left + boundingRect.width )
	{
		m_Velocity.x = -m_Velocity.x;
	}
	else if ( m_Velocity.x < 0 && m_Center.x - m_Radius < boundingRect.left )
	{
		m_Velocity.x = -m_Velocity.x;
	}
	if ( m_Velocity.y > 0 && m_Center.y + m_Radius > boundingRect.bottom + boundingRect.height )
	{
		m_Velocity.y = -m_Velocity.y;
	}
	else if ( m_Velocity.y < 0 && m_Center.y - m_Radius < boundingRect.bottom )
	{
		m_Velocity.y = -m_Velocity.y;
	}
}

void TrailingCircle::Draw( ) const
{
	Color4f color{ m_Color };

	double alpha{ 0.1 };
	float radius{ float(m_Radius * alpha) };

	for (Point2f point : m_Trail)
	{
		color.a = Lerp(0.f, 1.f, alpha);
		utils::SetColor(color);
		radius = float(m_Radius * alpha);
		utils::FillEllipse(point, radius, radius);

		alpha += 0.1;
	}

	utils::SetColor( m_Color );
	utils::FillEllipse( m_Center, m_Radius, m_Radius );
}

Vector2f TrailingCircle::GetRandomVelocity( )
{
	const int speedMin{ 50 };
	const int speedMax{ 100 };
	int speed{ rand( ) % ( speedMax - speedMin + 1 ) + speedMin };
	float angle{ rand( ) % 360 * float(utils::g_Pi / 360) };
	return Vector2f{ speed * cos( angle ) , speed * sin( angle ) };
}

Color4f TrailingCircle::GetRandomColor( )
{
	return Color4f{ rand( ) % 256 / 256.0f, rand( ) % 256 / 256.0f, rand( ) % 256 / 256.0f, 1.0f };
}
