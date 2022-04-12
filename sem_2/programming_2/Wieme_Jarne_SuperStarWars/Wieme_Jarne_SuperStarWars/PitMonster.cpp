#include "pch.h"
#include "PitMonster.h"
#include "EnemyBulletManager.h"
#include "Sprite.h"
#include "Avatar.h"
#include "Level.h"
#include "Vector2f.h"

PitMonster::PitMonster(const Point2f& bottomLeftStartPoint, float scale, int health)
	: Enemy(bottomLeftStartPoint, scale, health, Vector2f{ 0.f, 0.f }, Vector2f{ 0.f, -981.f }, 0.f) /*distanceFromAvatarWhenAttacking is 0 because the pitmonster
																									   always attacks when it is alive no matter the possition of the avatar*/
	, m_ActionState{ ActionState::inground }
	, m_HasBeenSummoned{false}
	, m_TentaclesDelay{ }
{
	m_pSprites.push_back(new Sprite{ "Resources/PitMonster/Tentacles.png", Sprite::AnimType::repeatBackwards, 3, 1, 3.f });
	m_pSprites.push_back(new Sprite{ "Resources/PitMonster/RiseOutGround.png", Sprite::AnimType::repeatBackwards, 5, 1, 5.f });
	m_pSprites.push_back(new Sprite{ "Resources/PitMonster/Attack.png", Sprite::AnimType::repeatBackwards, 6, 1, 3.f });
}

PitMonster::~PitMonster( )
{
	for (Sprite* sprite : m_pSprites)
	{
		delete sprite;
	}
}

void PitMonster::Update(float elapsedSec, const Level& level, Avatar& avatar)
{
	if (m_Health > 0)
	{
		m_AttackDelay += elapsedSec;

		m_pEnemyBulletManager->Update(elapsedSec, avatar, level);

		CheckActionState(avatar);

		ChangeShapeDimensions();

		m_Shape.left = m_StartPos.x - m_Shape.width;

		if (avatar.GetShape().left < m_Shape.left + m_Shape.width)
		{
			m_FacingDirection = -1;
		}

		if (avatar.GetShape().left > m_Shape.left + m_Shape.width)
		{
			m_FacingDirection = 1;
		}

		if (m_ActionState == ActionState::tentacles
			&& m_HasBeenSummoned == true)
		{
			m_TentaclesDelay += elapsedSec;
		}

		if (int(m_ActionState) >= 0)
		{
			m_pSprites[int(m_ActionState)]->Update(elapsedSec);
		}

		if (m_AttackDelay >= 1.f
			&& m_ActionState == ActionState::attack
			&& m_pSprites[int(ActionState::attack)]->GetFrameNr() == m_pSprites[int(ActionState::attack)]->GetAmountOfFrames() - 3)
		{
			m_AttackDelay = 0.f;
			Attack();
		}

		level.HandleCollision(m_Shape, m_Velocity);
	}
}

void PitMonster::Draw( ) const
{
	m_pEnemyBulletManager->Draw();

	glPushMatrix( );

	glTranslatef(m_Shape.left, m_Shape.bottom, 0.f);

	if (m_FacingDirection == -1)
	{
		glTranslatef(m_Shape.width, 0.f, 0.f);
		glScalef(-m_Scale, m_Scale, 1);
	}
	else
	{
		glScalef(m_Scale, m_Scale, 1);
	}

	if (m_Health > 0 && int(m_ActionState) >= 0)
	{
		m_pSprites[int(m_ActionState)]->Draw();
	}

	glPopMatrix( );	
}

void PitMonster::CheckActionState(const Avatar& avatar)
{
	if (avatar.GetShape().left >= 7850.f && m_ActionState == ActionState::inground && m_HasBeenSummoned == false)
	{
		m_HasBeenSummoned = true;
		m_ActionState = ActionState::tentacles;
	}

	if (m_ActionState == ActionState::tentacles && m_TentaclesDelay >= 1.f && m_pSprites[int(ActionState::tentacles)]->GetFrameNr() == 0)
	{
		m_ActionState = ActionState::inground;
	}
	
	if (m_HasBeenSummoned == true && m_ActionState == ActionState::inground)
	{
		m_HasBeenSummoned = false;
		m_ActionState = ActionState::summon;
	}

	if (m_ActionState == ActionState::summon
		&& m_pSprites[int(ActionState::summon)]->GetFrameNr() == m_pSprites[int(ActionState::summon)]->GetAmountOfFrames() - 1)
	{
		m_ActionState = ActionState::attack;
	}
}

void PitMonster::ChangeShapeDimensions( )
{
	if (int(m_ActionState) >= 0)
	{
		m_Shape.width = m_pSprites[int(m_ActionState)]->GetFrameWidth() * m_Scale;
		m_Shape.height = m_pSprites[int(m_ActionState)]->GetFrameHeight() * m_Scale;
	}
}

void PitMonster::Attack( )
{
	Vector2f velocity{ 0.f, 75.f };

	const int minXVelocity{ 100 };
	const int maxXVelocity{ 250 };

	if (m_FacingDirection == -1)
	{
		velocity.x = - float(rand() % (maxXVelocity - minXVelocity + 1) + minXVelocity);
	}
	else
	{
		velocity.x = float(rand() % (maxXVelocity - minXVelocity + 1) + minXVelocity);
	}

	m_pEnemyBulletManager->AddBullet(Point2f{ m_Shape.left + m_Shape.width / 2.f, m_Shape.height }, velocity, EnemyBullet::BulletType::boss);
}