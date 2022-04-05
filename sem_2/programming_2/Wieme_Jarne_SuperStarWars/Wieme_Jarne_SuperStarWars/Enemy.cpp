#include "pch.h"
#include "Enemy.h"
#include "Texture.h"
#include "Level.h"
#include "Sprite.h"
#include "Bullet.h"
#include <iostream>

Enemy::Enemy(const Point2f& bottomLeftStartPoint, float scale, int health)
	:m_Shape{ bottomLeftStartPoint.x, bottomLeftStartPoint.y, 0.f, 0.f }
	,m_Velocity{ 75.f, 0.f }
	,m_Acceleration{ 0.f, -981.f }
	,m_Scale{ scale }
	,m_AccuSec{ }
	,m_Health{ health }
	,m_StartHealth{ health }
	,m_Sprite{ new Sprite{ "Resources/Enemies/Enemy1Walk.png", Sprite::animType::loop, 4, 1, 10, scale } }
	,m_RespawnDelay{ }
	,m_StartPos{ bottomLeftStartPoint }
{
	m_Shape.width = m_Sprite->GetFrameWidth( ) * m_Scale;
	m_Shape.height = m_Sprite->GetFrameHeight( ) * m_Scale;

	m_LeftBoundary = m_Shape.left - 35.f;
	m_RightBoundary = m_Shape.left + m_Shape.width + 35.f;
}

Enemy::~Enemy( )
{
	delete m_Sprite;
}

void Enemy::Update(float elapsedSec, const Level& level)
{
	if (m_Health <= 0)
	{
		m_RespawnDelay += elapsedSec;

		if (m_RespawnDelay >= 2.f)
		{
			m_RespawnDelay = 0.f;
			m_Health = m_StartHealth;
			m_Shape.left = m_StartPos.x;
			m_Shape.bottom = m_StartPos.y;
		}
	}

	if (m_Health > 0)
	{
		if (m_Shape.left < m_LeftBoundary
			|| m_Shape.left + m_Shape.width > m_RightBoundary )
		{
			m_AccuSec += elapsedSec;

			if (m_AccuSec >= 0.1f)
			{
				m_AccuSec = 0.f;
				m_Velocity.x *= -1;
			}
		}

		m_Sprite->Update(elapsedSec);

		level.HandleCollision(m_Shape, m_Velocity);

		m_Velocity.y += m_Acceleration.y * elapsedSec;

		m_Shape.left += m_Velocity.x * elapsedSec;
		m_Shape.bottom += m_Velocity.y * elapsedSec;
	}	
}

void Enemy::Draw( ) const
{
	glPushMatrix( );

		glTranslatef(m_Shape.left, m_Shape.bottom, 0.f);

		if (m_Velocity.x > 0.f)
		{
			glTranslatef(m_Shape.width, 0.f, 0.f);
			glScalef(-m_Scale, m_Scale, 1);
		}
		else
		{
			glScalef(m_Scale, m_Scale, 1);
		}

		if (m_Health > 0)
		{
			m_Sprite->Draw();
		}
		
	glPopMatrix( );
}

void Enemy::Hit( )
{
	m_Health -= 1;
}

Rectf Enemy::GetShape( ) const
{
	return m_Shape;
}

int Enemy::GetHeath() const
{
	return m_Health;
}