#include "pch.h"
#include "FlyingEnemy.h"
#include "Sprite.h"
#include "Level.h"
#include "Avatar.h"
#include "TextureManager.h"

FlyingEnemy::FlyingEnemy(const Point2f& bottomLeftStartPoint, float scale, int health, TextureManager& pTextureManager)
	: Enemy(bottomLeftStartPoint, scale, health, Vector2f{175.f, 0.f}, Vector2f{ 0.f, 0.f }, 60.f)
	, m_ActionState{ ActionState::flying }
	, m_BottomBoundary{ 50.f }
{
	m_pSprites.push_back(new Sprite{ pTextureManager.GetTexture("Resources/Enemies/Enemy2Fly.png"), Sprite::AnimType::loop, 4, 1, 5.f });
	m_pSprites.push_back(new Sprite{ pTextureManager.GetTexture("Resources/Enemies/Enemy2Attack.png"), Sprite::AnimType::dontRepeat, 3, 1, 0.f });

	m_Shape.width = m_pSprites[int(m_ActionState)]->GetFrameWidth() * m_Scale;
	m_Shape.height = m_pSprites[int(m_ActionState)]->GetFrameHeight() * m_Scale;

	m_LeftBoundary = m_Shape.left - m_DistanceFromAvatarWhenAttacking;
	m_RightBoundary = m_Shape.left + m_Shape.width + m_DistanceFromAvatarWhenAttacking;
}

void FlyingEnemy::Update(float elapsedSec, const Level& level, Avatar& avatar)
{
	if (m_Health <= 0)
	{
		m_SecondsAftherDeath += elapsedSec;

		if (m_SecondsAftherDeath >= 2.f)
		{
			Respawn( );
		}
	}

	if (m_Health > 0)
	{
		CheckActionState(avatar);

		ChangeShapeDimensions( );

		if (m_Shape.bottom > m_StartPos.y)
		{
			m_Shape.bottom = m_StartPos.y;
		}

		switch (m_ActionState)
		{
		case ActionState::flying:
			m_pSprites[int(m_ActionState)]->Update(elapsedSec);

			m_AttackDelay += elapsedSec;

			break;

		case ActionState::attacking:
			if (m_Shape.bottom > m_BottomBoundary && m_Velocity.y == 0)
			{
				m_Velocity.y = -60.f;
			}

			if (m_Velocity.y < 0)
			{
				m_pSprites[int(ActionState::attacking)]->SetFrameNr(0);
			}

			if (m_Shape.bottom <= m_BottomBoundary)
			{
				m_Velocity.y = 60.f;
			}

			if (m_Velocity.y > 0)
			{
				m_pSprites[int(ActionState::attacking)]->SetFrameNr(1);

				if (m_Shape.bottom >= m_StartPos.y)
				{
					m_Velocity.y = 0.f;
				}
			}

			break;
		}

		Moving(elapsedSec);
	}
}

void FlyingEnemy::Draw() const
{
	glPushMatrix();

	Enemy::Draw();

	if (m_Health > 0)
	{
		m_pSprites[int(m_ActionState)]->Draw();
	}

	glPopMatrix();
}

void FlyingEnemy::CheckActionState(const Avatar& avatar)
{
	if (IsAvatarInAttackZone(Point2f{ avatar.GetShape().left, avatar.GetShape().bottom }))
	{
		m_ActionState = ActionState::attacking;
	}

	if (m_Shape.bottom < m_StartPos.y || m_AttackDelay >= 1.f)
	{
		m_AttackDelay = 0.f;
		m_ActionState = ActionState::attacking;
	}
	else
	{
		m_ActionState = ActionState::flying;
	}
}

void FlyingEnemy::ChangeShapeDimensions( )
{
	m_Shape.width = m_pSprites[int(m_ActionState)]->GetFrameWidth( ) * m_Scale;
	m_Shape.height = m_pSprites[int(m_ActionState)]->GetFrameHeight( ) * m_Scale;
}