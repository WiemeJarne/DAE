#include "pch.h"
#include "WormEnemy.h"
#include "Level.h"
#include "Avatar.h"
#include "Sprite.h"
#include "TextureManager.h"

WormEnemy::WormEnemy(const Point2f& bottomLeftStartPoint, float scale, int health, TextureManager& textureManager)
	: Enemy(bottomLeftStartPoint, scale, health, Vector2f{ 0.f, 0.f }, Vector2f{0, -981.f}, 10.f)
	, m_ActionState{ ActionState::inGround }
{
	m_pSprites.push_back(new Sprite{ textureManager.GetTexture("Resources/Enemies/Enemy5InGround.png"), Sprite::AnimType::dontRepeat });
	m_pSprites.push_back(new Sprite{ textureManager.GetTexture("Resources/Enemies/Enemy5RiseOutGround.png"), Sprite::AnimType::repeatBackwards, 4, 1, 5.f });
	m_pSprites.push_back(new Sprite{ textureManager.GetTexture("Resources/Enemies/Enemy5Idle.png"), Sprite::AnimType::loop, 2, 1, 5.f });
	m_pSprites.push_back(new Sprite{ textureManager.GetTexture("Resources/Enemies/Enemy5Attack.png"), Sprite::AnimType::dontRepeat });

	m_LeftBoundary = m_Shape.left - 40.f;
	m_RightBoundary = m_Shape.left + m_Shape.width + 40.f;
}

void WormEnemy::Update(float elapsedSec, const Level& level, const Avatar& avatar)
{
	if (m_Health > 0)
	{
		if (avatar.GetShape().left < m_Shape.left)
		{
			m_FacingDirection = -1;
		}
		else
		{
			m_FacingDirection = 1;
		}

		m_SecondsAfterAttack += elapsedSec;

		m_Velocity.y += m_Acceleration.y * elapsedSec;

		m_Shape.bottom += m_Velocity.y * elapsedSec;

		CheckActionState(avatar);

		ChangeShapeDimensions( );

		m_pSprites[int(m_ActionState)]->Update(elapsedSec);

		level.HandleCollision(m_Shape, m_Velocity);
	}
}

void WormEnemy::Draw( ) const
{
	glPushMatrix( );

	Enemy::Draw( );

	if (m_Health > 0)
	{
		m_pSprites[int(m_ActionState)]->Draw( );
	}

	glPopMatrix( );
}

void WormEnemy::CheckActionState(const Avatar& avatar)
{
	if (avatar.GetShape().left >= m_LeftBoundary - 20.f && avatar.GetShape().left < m_LeftBoundary
		|| avatar.GetShape().left <= m_RightBoundary + 20.f && avatar.GetShape().left > m_RightBoundary)
	{
		if (m_ActionState == ActionState::inGround)
		{
			m_ActionState = ActionState::summon;
		}

		if (m_pSprites[1]->GetFrameNr() == m_pSprites[1]->GetAmountOfFrames() - 1)
		{
			m_ActionState = ActionState::idle;
		}
	}
	else if (IsAvatarInAttackZone(Point2f{ avatar.GetShape().left, avatar.GetShape().bottom }))
	{
		if (m_SecondsAfterAttack >= 1.f)
		{
			m_SecondsAfterAttack = 0.f;
			m_ActionState = ActionState::attacking;
		}
		else if(m_SecondsAfterAttack >= 0.5f)
		{
			m_ActionState = ActionState::idle;
		}
		
	}
	else if(m_ActionState != ActionState::inGround)
	{
		m_ActionState = ActionState::summon;

		if (m_pSprites[1]->GetFrameNr() == 0)
		{
			m_ActionState = ActionState::inGround;
		}
	}
}

void WormEnemy::ChangeShapeDimensions( )
{
	m_Shape.width = m_pSprites[int(m_ActionState)]->GetFrameWidth() * m_Scale;
	m_Shape.height = m_pSprites[int(m_ActionState)]->GetFrameHeight() * m_Scale;

	m_LeftBoundary = m_Shape.left - 15.f;
	m_RightBoundary = m_Shape.left + m_Shape.width + 15.f;
}