#include "pch.h"
#include "Enemy.h"
#include "Level.h"
#include "Avatar.h"
#include "Sprite.h"

Enemy::Enemy(const Point2f& bottomLeftStartPoint, float scale, int health, const Vector2f& velocity, const Vector2f& acceleration, const float distanceFromAvatarWhenAttacking)
	: m_Shape{ bottomLeftStartPoint.x, bottomLeftStartPoint.y, 0.f, 0.f }
	, m_StartPos{ bottomLeftStartPoint }
	, m_Scale{ scale }
	, m_Health{ health }
	, m_StartHealth{ health }
	, m_Velocity{ velocity }
	, m_Acceleration{ acceleration }
	, m_DistanceFromAvatarWhenAttacking{ distanceFromAvatarWhenAttacking }
	, m_AccuSec{ }
	, m_SecondsAftherDeath{ }
	, m_SecondsAfterAttack{ }
	, m_FacingDirection{ -1 }
	, m_LeftBoundary{ }
	, m_RightBoundary{ }
	, m_pSprites{ }
{
}

Enemy::~Enemy( )
{
	for (Sprite* sprite : m_pSprites)
	{
		delete sprite;
	}
}

void Enemy::Draw( ) const
{
	glTranslatef(m_Shape.left, m_Shape.bottom, 0.f);

	if (m_FacingDirection == 1)
	{
		glTranslatef(m_Shape.width, 0.f, 0.f);
		glScalef(-m_Scale, m_Scale, 1);
	}
	else
	{
		glScalef(m_Scale, m_Scale, 1);
	}
}

void Enemy::Hit(int damage)
{
	if (m_Health > 0)
	{
		m_Health -= damage;
	}
}

Rectf Enemy::GetShape( ) const
{
	return m_Shape;
}

int Enemy::GetHeath( ) const
{
	return m_Health;
}

void Enemy::Respawn( )
{
	m_SecondsAftherDeath = 0.f;
	m_Health = m_StartHealth;
	m_Shape.left = m_StartPos.x;
	m_Shape.bottom = m_StartPos.y;
}

bool Enemy::IsAvatarInAttackZone(const Point2f& avatarPos)
{
	if (((avatarPos.x >= m_Shape.left - m_DistanceFromAvatarWhenAttacking
		  && avatarPos.x <= m_Shape.left
		  && m_FacingDirection == -1    )
	     || (avatarPos.x <= m_Shape.left + m_Shape.width + m_DistanceFromAvatarWhenAttacking
		     && avatarPos.x >= m_Shape.left + m_Shape.width
	         && m_FacingDirection == 1                      )))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Enemy::Moving(float elapsedSec)
{
	if (m_Health > 0)
	{
		m_AccuSec += elapsedSec;

		if (m_Shape.left < m_LeftBoundary
			|| m_Shape.left + m_Shape.width > m_RightBoundary && m_AccuSec >= 1.f)
		{
			m_AccuSec = 0.f;
			m_FacingDirection *= -1;
		}

		m_Velocity.y += m_Acceleration.y * elapsedSec;

		m_Shape.left += m_Velocity.x * m_FacingDirection * elapsedSec;
		m_Shape.bottom += m_Velocity.y * elapsedSec;
	}
}