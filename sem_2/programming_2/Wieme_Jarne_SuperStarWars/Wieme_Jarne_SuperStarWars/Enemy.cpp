#include "pch.h"
#include "Enemy.h"
#include "Texture.h"
#include "Level.h"
#include "Sprite.h"
#include "Bullet.h"
#include "utils.h"
#include "EnemyBulletManager.h"
#include "Avatar.h"
#include <iostream>

Enemy::Enemy(const Point2f& bottomLeftStartPoint, float scale, int health)
	: m_ActionState{ ActionState::walking }
	, m_Shape{ bottomLeftStartPoint.x, bottomLeftStartPoint.y, 0.f, 0.f }
	, m_Velocity{ 75.f, 0.f }
	, m_Acceleration{ 0.f, -981.f }
	, m_Scale{ scale }
	, m_AccuSec{ }
	, m_Health{ health }
	, m_StartHealth{ health }
	, m_RespawnDelay{ }
	, m_StartPos{ bottomLeftStartPoint }
	, m_pEnemyBulletManager{ new EnemyBulletManager(1.f) }
	, m_ShootDelay{ }
	, m_FacingDirection{ 1 }
{
	m_pSprites.push_back(new Sprite{ "Resources/Enemies/Enemy1Walk.png", Sprite::animType::loop, 4, 1, 10, scale });
	m_pSprites.push_back(new Sprite{ "Resources/Enemies/Enemy1Attack.png", Sprite::animType::loop, 4, 1, 5, scale });

	m_Shape.width = m_pSprites[int(m_ActionState)]->GetFrameWidth() * m_Scale;
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
	Point2f avatarPos{ avatar.GetShape( ).left, avatar.GetShape( ).bottom };

	m_ShootDelay += elapsedSec;

	m_pEnemyBulletManager->UpdateBullets(elapsedSec);

	m_pEnemyBulletManager->HandleCollision(avatar);

	if ( avatarPos.x <= m_Shape.left - 50.f
		 || avatarPos.x >= m_Shape.left + m_Shape.width + 50.f)
	{
		m_ActionState = ActionState::walking;
	}

	if ((  (avatarPos.x >= m_Shape.left - 50.f 
		    && avatarPos.x <= m_Shape.left 
		    && m_FacingDirection == -1        )
	    || (avatarPos.x <= m_Shape.left + m_Shape.width + 50.f 
		    && avatarPos.x >= m_Shape.left + m_Shape.width
		    && m_FacingDirection == 1                          )))
	{
		m_ActionState = ActionState::attacking;
	}

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
		if (m_ActionState == ActionState::walking)
		{
			if (m_Shape.left < m_LeftBoundary
				|| m_Shape.left + m_Shape.width > m_RightBoundary)
			{
				m_AccuSec += elapsedSec;

				if (m_AccuSec >= 0.1f)
				{
					m_AccuSec = 0.f;
					m_FacingDirection *= -1;
				}
			}

			m_Velocity.y += m_Acceleration.y * elapsedSec;

			m_Shape.left += m_Velocity.x * m_FacingDirection * elapsedSec;
			m_Shape.bottom += m_Velocity.y * elapsedSec;
		}

		if ( m_ActionState == ActionState::attacking
			 && m_pSprites[int(ActionState::attacking)]->GetFrameNr( ) == m_pSprites[int(ActionState::attacking)]->GetAmountOfFrames( ) - 1
			 && m_ShootDelay >= 0.3f																									    )
		{
			m_ShootDelay = 0.f;
			Shoot();
		}

		m_pSprites[int(m_ActionState)]->Update(elapsedSec);

		level.HandleCollision(m_Shape, m_Velocity);
	}	
}

void Enemy::Draw( ) const
{
	m_pEnemyBulletManager->DrawBullets();

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
			
			m_pSprites[int(m_ActionState)]->Draw();
		}
		
	glPopMatrix( );	
}

void Enemy::Hit( )
{
	if (m_Health > 0)
	{
		--m_Health;
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

void Enemy::Shoot( )
{
	Vector2f velocity{0, 180.f};

	if (m_FacingDirection == -1)
	{
		velocity.x = -200.f;
	}
	else
	{
		velocity.x = 200.f;
	}

	m_pEnemyBulletManager->AddBullet(Point2f{m_Shape.left + m_Shape.width * 0.5f, m_Shape.bottom + m_Shape.height * 0.7f}, velocity);
}