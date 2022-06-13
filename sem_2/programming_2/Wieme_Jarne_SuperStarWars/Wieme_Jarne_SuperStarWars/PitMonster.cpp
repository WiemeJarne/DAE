#include "pch.h"
#include "PitMonster.h"
#include "Level.h"
#include "Avatar.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "BulletManager.h"

PitMonster::PitMonster(const Point2f& bottomLeftStartPoint, float scale, int health, TextureManager& textureManager, BulletManager& bulletManager)
	: Enemy(bottomLeftStartPoint, scale, health, Vector2f{ 0.f, 0.f }, Vector2f{ 0.f, -981.f }, 0.f) /*distanceFromAvatarWhenAttacking is 0 because the pitmonster
																									   always attacks when it is alive no matter the possition of the avatar*/
	, m_ActionState{ ActionState::inground }
	, m_HasBeenSummoned{ }
	, m_SecondsSinceLastTentacle{ }
	, m_BulletManager{ bulletManager }
	, m_AvatarYPosToSummon{ 7850.f }
{
	m_pSprites.push_back(new Sprite{ textureManager.GetTexture("Resources/PitMonster/Tentacles.png"), Sprite::AnimType::repeatBackwards, 3, 1, 3.f });
	m_pSprites.push_back(new Sprite{ textureManager.GetTexture("Resources/PitMonster/RiseOutGround.png"), Sprite::AnimType::repeatBackwards, 5, 1, 5.f });
	m_pSprites.push_back(new Sprite{ textureManager.GetTexture("Resources/PitMonster/Attack.png"), Sprite::AnimType::repeatBackwards, 6, 1, 3.f });
}

void PitMonster::Update(float elapsedSec, const Level& level, const Avatar& avatar)
{
	if (m_Health > 0)
	{
		m_SecondsAfterAttack += elapsedSec;

		CheckActionState(avatar);

		ChangeShapeDimensions();

		m_Shape.left = m_StartPos.x - m_Shape.width;

		if (avatar.GetShape().left < m_Shape.left + m_Shape.width)
		{
			m_FacingDirection = 1;
		}

		if (avatar.GetShape().left > m_Shape.left + m_Shape.width)
		{
			m_FacingDirection = -1;
		}

		if (m_ActionState == ActionState::tentacles
			&& m_HasBeenSummoned == true)
		{
			m_SecondsSinceLastTentacle += elapsedSec;
		}

		if (int(m_ActionState) >= 0)
		{
			m_pSprites[int(m_ActionState)]->Update(elapsedSec);
		}

		if (m_SecondsAfterAttack >= 1.f
			&& m_ActionState == ActionState::attack
			&& m_pSprites[int(ActionState::attack)]->GetFrameNr() == m_pSprites[int(ActionState::attack)]->GetAmountOfFrames() - 3)
		{
			m_SecondsAfterAttack = 0.f;
			Attack();
		}

		level.HandleCollision(m_Shape, m_Velocity);
	}
}

void PitMonster::Draw( ) const
{
	glPushMatrix( );

	Enemy::Draw( );

	if (m_Health > 0 && int(m_ActionState) >= 0)
	{
		m_pSprites[int(m_ActionState)]->Draw();
	}

	glPopMatrix( );	
}

bool PitMonster::AvatarIsInRange(const Rectf& avatarShape) const
{
	if (avatarShape.left >= m_Shape.left - 2 * m_Shape.width)
	{
		return true;
	}
	return false;
}

void PitMonster::Attack( )
{
	Vector2f velocity{ 0.f, 0.f };

	const int minXVelocity{ 100 };
	const int maxXVelocity{ 250 };

	const int minYVelocity{ 75 };
	const int maxYVelocity{ 150 };

	if (m_FacingDirection == 1)
	{
		velocity.x = -float(rand() % (maxXVelocity - minXVelocity + 1) + minXVelocity);
	}
	else
	{
		velocity.x = float(rand() % (maxXVelocity - minXVelocity + 1) + minXVelocity);
	}

	velocity.y = float(rand() % (maxYVelocity - minYVelocity + 1) + minYVelocity);

	m_BulletManager.AddBullet(Point2f{ m_Shape.left + m_Shape.width / 2.f, m_Shape.height }, velocity, 1.f, Bullet::Type::boss);
}

void PitMonster::ChangeShapeDimensions( )
{
	if (int(m_ActionState) >= 0)
	{
		m_Shape.width = m_pSprites[int(m_ActionState)]->GetFrameWidth() * m_Scale;
		m_Shape.height = m_pSprites[int(m_ActionState)]->GetFrameHeight() * m_Scale;
	}
}

void PitMonster::CheckActionState(const Avatar& avatar)
{
	if (avatar.GetShape().left >= m_AvatarYPosToSummon && m_ActionState == ActionState::inground && m_HasBeenSummoned == false)
	{
		m_HasBeenSummoned = true;
		m_ActionState = ActionState::tentacles;
	}

	if (avatar.GetShape().left <= 100.f)
	{
		m_HasBeenSummoned = false;
		m_ActionState = ActionState::inground;
	}

	if (m_ActionState == ActionState::tentacles && m_SecondsSinceLastTentacle >= 1.f && m_pSprites[int(ActionState::tentacles)]->GetFrameNr() == 0)
	{
		m_ActionState = ActionState::inground;
	}
	
	if (m_HasBeenSummoned == true && m_ActionState == ActionState::inground)
	{
		m_ActionState = ActionState::summon;
	}

	if (m_ActionState == ActionState::summon
		&& m_pSprites[int(ActionState::summon)]->GetFrameNr() == m_pSprites[int(ActionState::summon)]->GetAmountOfFrames() - 1)
	{
		m_ActionState = ActionState::attack;
	}
}