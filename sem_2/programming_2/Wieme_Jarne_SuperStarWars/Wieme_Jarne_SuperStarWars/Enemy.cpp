#include "pch.h"
#include "Enemy.h"
#include "Texture.h"
#include "Level.h"
#include "Sprite.h"
#include <iostream>

Enemy::Enemy(const Point2f& bottomLeftStartPoint)
	:m_Shape{ bottomLeftStartPoint.x, bottomLeftStartPoint.y, 0.f, 0.f }
	,m_Velocity{ 75.f, 0.f }
	,m_Acceleration{ 0.f, -981.f }
	,m_Delay{}
{
	m_Sprite = new Sprite{ "Resources/Enemies/Enemy1Walk.png", Sprite::animType::loop, 4, 1, 10 };

	m_Shape.width = m_Sprite->GetFrameWidth( );
	m_Shape.height = m_Sprite->GetFrameHeight( );

	m_LeftBoundary = m_Shape.left - 25.f;
	m_RightBoundary = m_Shape.left + m_Shape.width + 25.f;
}

Enemy::~Enemy( )
{
	delete m_Sprite;
}

void Enemy::Update(float elapsedSec, const Level& level)
{
	m_Delay += elapsedSec;

	if ( (m_Shape.left < m_LeftBoundary
		  || m_Shape.left + m_Shape.width > m_RightBoundary)
		 && m_Delay > 0.1f								    )
	{
		m_Delay = 0.f;
		m_Velocity.x *= -1;
	}

	m_Sprite->Update(elapsedSec);

	level.HandleCollision(m_Shape, m_Velocity);

	m_Velocity.y += m_Acceleration.y * elapsedSec;

	m_Shape.left += m_Velocity.x * elapsedSec;
	m_Shape.bottom += m_Velocity.y * elapsedSec;
}

void Enemy::Draw( ) const
{
	const float scale{ 1.4f };

	glPushMatrix( );
		glTranslatef(m_Shape.left, m_Shape.bottom, 0.f);
		
		if (m_Velocity.x > 0.f)
		{
			glScalef(-scale, scale, 1);
			glTranslatef(-m_Shape.width, 0.f, 0.f);
		}
		else
		{
			glScalef(scale, scale, 1);
		}

		m_Sprite->Draw(Point2f{ m_Shape.left, m_Shape.bottom });
	glPopMatrix( );
}