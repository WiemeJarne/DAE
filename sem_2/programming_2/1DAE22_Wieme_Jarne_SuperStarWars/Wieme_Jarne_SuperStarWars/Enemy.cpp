#include "pch.h"
#include "Enemy.h"
#include "Level.h"
#include "Avatar.h"
#include "Sprite.h"
#include "TextureManager.h"

Enemy::Enemy(const Point2f& bottomLeftStartPoint, float scale, int health, const Vector2f& velocity, const Vector2f& acceleration, const float distanceFromAvatarWhenAttacking)
	: m_Shape{ bottomLeftStartPoint.x, bottomLeftStartPoint.y, 0.f, 0.f }
	, m_StartPos{ bottomLeftStartPoint }
	, m_Velocity{ velocity }
	, m_Acceleration{ acceleration }
	, m_Scale{ scale }
	, m_AccuSec{ }
	, m_Health{ health }
	, m_StartHealth{ health }
	, m_SecondsAftherDeath{ }
	, m_AttackDelay{ }
	, m_FacingDirection{ -1 }
	, m_LeftBoundary{ }
	, m_RightBoundary{ }
	, m_DistanceFromAvatarWhenAttacking{ distanceFromAvatarWhenAttacking }
{
}

Enemy::~Enemy( )
{
	for (Sprite* sprite : m_pSprites)
	{
		delete sprite;
	}
}

void Enemy::Update(float elapsedSec, const Level& level, Avatar& avatar)
{ 
}

void Enemy::Draw( ) const
{
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

void Enemy::Attack( )
{
}

void Enemy::CheckActionState(const Avatar& avatar)
{
}

void Enemy::ChangeShapeDimensions( )
{
}