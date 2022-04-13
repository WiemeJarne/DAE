#include "pch.h"
#include "FlyingEnemy.h"
#include "Sprite.h"
#include "Level.h"
#include "Avatar.h"

FlyingEnemy::FlyingEnemy(const Point2f& bottomLeftStartPoint, float scale, int health)
	: Enemy(bottomLeftStartPoint, scale, health, Vector2f{175.f, 0.f}, Vector2f{ 0.f, 0.f }, 40.f)
	, m_ActionState{ ActionState::flying }
	, m_BottomBoundary{ 50.f }
{
	m_pSprites.push_back(new Sprite{ "Resources/Enemies/Enemy2Fly.png", Sprite::AnimType::loop, 4, 1, 5.f });
	m_pSprites.push_back(new Sprite{ "Resources/Enemies/Enemy2Attack.png", Sprite::AnimType::dontRepeat, 3, 1, 0.f });

	m_Shape.width = m_pSprites[int(m_ActionState)]->GetFrameWidth() * m_Scale;
	m_Shape.height = m_pSprites[int(m_ActionState)]->GetFrameHeight() * m_Scale;

	m_LeftBoundary = m_Shape.left - 60.f;
	m_RightBoundary = m_Shape.left + m_Shape.width + 60.f;
}

FlyingEnemy::~FlyingEnemy( )
{
	for (Sprite* sprite : m_pSprites)
	{
		delete sprite;
	}
}

void FlyingEnemy::Update(float elapsedSec, const Level& level, Avatar& avatar)
{
	m_AccuSec += elapsedSec;

	m_AttackDelay += elapsedSec;
	
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

			if ((m_Shape.left <= m_LeftBoundary || m_Shape.left + m_Shape.width >= m_RightBoundary) && m_AccuSec >= 1.f)
			{
				m_FacingDirection *= -1;
			}
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

void FlyingEnemy::Draw( ) const
{
	glPushMatrix();

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
	m_Shape.width = m_pSprites[int(m_ActionState)]->GetFrameWidth() * m_Scale;
	m_Shape.height = m_pSprites[int(m_ActionState)]->GetFrameHeight() * m_Scale;
}