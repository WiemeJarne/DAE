#include "pch.h"
#include "Enemy.h"
#include "Texture.h"
#include "Level.h"
#include "Sprite.h"
#include "Bullet.h"
#include "EnemyBulletManager.h"
#include "Avatar.h"

Enemy::Enemy(const Point2f& bottomLeftStartPoint, float scale, int health, const Vector2f& velocity, const Vector2f& acceleration, const float distanceFromAvatarWhenAttacking)
	: m_ActionState{ }
	, m_Shape{ bottomLeftStartPoint.x, bottomLeftStartPoint.y, 0.f, 0.f }
	, m_Velocity{ velocity }
	, m_Acceleration{ acceleration }
	, m_Scale{ scale }
	, m_AccuSec{ }
	, m_Health{ health }
	, m_StartHealth{ health }
	, m_SecondsAftherDeath{ }
	, m_StartPos{ bottomLeftStartPoint }
	, m_AttackDelay{ }
	, m_FacingDirection{ -1 }
	, m_LeftBoundary{ }
	, m_RightBoundary{ }
	, m_DistanceFromAvatarWhenAttacking{ distanceFromAvatarWhenAttacking }
{
	m_pEnemyBulletManager = new EnemyBulletManager{ 1.f };
}

Enemy::Enemy(const Point2f& bottomLeftStartPoint, float scale, int health)
	: m_ActionState{ ActionState::moving }
	, m_Shape{ bottomLeftStartPoint.x, bottomLeftStartPoint.y, 0.f, 0.f }
	, m_Velocity{ 25.f, 0.f }
	, m_Acceleration{ 0.f, -981.f }
	, m_Scale{ scale }
	, m_AccuSec{ }
	, m_Health{ health }
	, m_StartHealth{ health }
	, m_SecondsAftherDeath{ }
	, m_StartPos{ bottomLeftStartPoint }
	, m_AttackDelay{ }
	, m_FacingDirection{ -1 }
	, m_DistanceFromAvatarWhenAttacking{ 60.f }
{
	m_pEnemyBulletManager = new EnemyBulletManager{ 1.f };

	m_pSprites.push_back(new Sprite{ "Resources/Enemies/Enemy1Walk.png", Sprite::AnimType::loop, 4, 1, 10 });
	m_pSprites.push_back(new Sprite{ "Resources/Enemies/Enemy1Attack.png", Sprite::AnimType::loop, 4, 1, 5 });

	m_Shape.width = m_pSprites[int(m_ActionState)]->GetFrameWidth( ) * m_Scale;
	m_Shape.height = m_pSprites[int(m_ActionState)]->GetFrameHeight( ) * m_Scale;

	m_LeftBoundary = m_Shape.left - 35.f;
	m_RightBoundary = m_Shape.left + m_Shape.width + 35.f;
}

Enemy::~Enemy( )
{
	for (Sprite* sprite : m_pSprites)
	{
		delete sprite;
	}

	delete m_pEnemyBulletManager;
}

void Enemy::Update(float elapsedSec, const Level& level, Avatar& avatar)
{
	if (m_Health <= 0)
	{
		m_SecondsAftherDeath += elapsedSec;

		if (m_SecondsAftherDeath >= 3.f)
		{
			Respawn( );
		}

		m_pEnemyBulletManager->DeleteAllEnemyBullets( );
	}

	if (m_Health > 0)
	{
		m_AttackDelay += elapsedSec;

		m_pEnemyBulletManager->UpdateBullets(elapsedSec, avatar, level);

		CheckActionState(avatar);

		ChangeShapeDimensions( );

		Moving(elapsedSec);

		switch (m_ActionState)
		{
		case Enemy::ActionState::attacking:

			if (m_Health > 0
				&& m_AttackDelay >= 0.3f                                                                                                     
				&& m_pSprites[int(ActionState::attacking)]->GetFrameNr() == m_pSprites[int(ActionState::attacking)]->GetAmountOfFrames() - 1)
			{
				m_AttackDelay = 0.f;
				Attack();
			}
			break;
		}

		m_pSprites[int(m_ActionState)]->Update(elapsedSec);

		level.HandleCollision(m_Shape, m_Velocity);
	}	
}

void Enemy::Draw( ) const
{
	if (m_pEnemyBulletManager != nullptr)
	{
		m_pEnemyBulletManager->Draw( );
	}

	glPushMatrix( );

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

		if (m_Health > 0)
		{
			m_pSprites[int(m_ActionState)]->Draw( );
		}
		
	glPopMatrix( );	
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

void Enemy::Attack( )
{
	Vector2f velocity{0, 100.f};

	if (m_FacingDirection == -1)
	{
		velocity.x = -150.f;
	}
	else
	{
		velocity.x = 150.f;
	}

	m_pEnemyBulletManager->AddBullet(Point2f{m_Shape.left + m_Shape.width * 0.5f, m_Shape.bottom + m_Shape.height * 0.7f}, velocity, EnemyBullet::BulletType::Enemy);
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

void Enemy::CheckActionState(const Avatar& avatar)
{
	if (IsAvatarInAttackZone(Point2f{ avatar.GetShape().left, avatar.GetShape().bottom }))
	{
		m_ActionState = ActionState::attacking;
	}
	else
	{
		m_ActionState = ActionState::moving;
	}
}

void Enemy::Moving(const float elapsedSec)
{
	if (m_Health > 0)
	{
		if (m_Shape.left < m_LeftBoundary
			|| m_Shape.left + m_Shape.width > m_RightBoundary)
		{
			m_AccuSec += elapsedSec;

			if (m_AccuSec >= 0.2f)
			{
				m_AccuSec = 0.f;
				m_FacingDirection *= -1;
			}
		}

		m_Velocity.y += m_Acceleration.y * elapsedSec;

		m_Shape.left += m_Velocity.x * m_FacingDirection * elapsedSec;
		m_Shape.bottom += m_Velocity.y * elapsedSec;
	}
}

void Enemy::ChangeShapeDimensions( )
{
	m_Shape.width = m_pSprites[int(m_ActionState)]->GetFrameWidth() * m_Scale;
	m_Shape.height = m_pSprites[int(m_ActionState)]->GetFrameHeight() * m_Scale;
}