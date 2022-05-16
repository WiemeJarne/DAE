#include "pch.h"
#include "JumpingEnemy.h"
#include "Sprite.h"
#include "Level.h"
#include "Avatar.h"
#include "TextureManager.h"

JumpingEnemy::JumpingEnemy(const Point2f& bottomLeftStartPoint, float scale, int health, TextureManager& pTextureManager)
	: Enemy(bottomLeftStartPoint, scale, health, Vector2f{0.f, 0.f}, Vector2f{0.f, -981.f}, 125.f, pTextureManager)
	, m_ActionState{ ActionState::idle }
{
	m_pSprites.push_back(new Sprite{ pTextureManager.GetTexture("Resources/Enemies/Enemy4Idle.png"), Sprite::AnimType::loop, 3, 1, 3.f });
	m_pSprites.push_back(new Sprite{ pTextureManager.GetTexture("Resources/Enemies/Enemy4Jump.png"), Sprite::AnimType::dontRepeat, 3, 1, 3.f });
}

void JumpingEnemy::Update(float elapsedSec, const Level& level, Avatar& avatar)
{
	if (m_Health <= 0)
	{
		m_SecondsAftherDeath += elapsedSec;

		if (m_SecondsAftherDeath >= 5.f)
		{
			Respawn( );
		}
	}

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

		m_AttackDelay += elapsedSec;

		m_Velocity.y += m_Acceleration.y * elapsedSec;

		m_Shape.left += m_Velocity.x * elapsedSec;
		m_Shape.bottom += m_Velocity.y * elapsedSec;

		level.HandleCollision(m_Shape, m_Velocity);

		if (level.IsOnGround(m_Shape, m_Velocity) && m_ActionState == ActionState::jumping)
		{
			m_Velocity.x = 0;
			m_ActionState = ActionState::idle;
		}

		CheckActionState(avatar);

		if ( m_ActionState == ActionState::jumping
			 && level.IsOnGround(m_Shape, m_Velocity)
			 && m_AccuSec >= 1.f                      )
		{
			m_AccuSec = 0.f;
			m_pSprites[int(ActionState::jumping)]->SetFrameNr(0);
			m_ActionState = ActionState::idle;
			m_Velocity.x = 0.f;
		}

		if (m_ActionState == ActionState::jumping)
		{
			m_AccuSec += elapsedSec;
		}

		ChangeShapeDimensions( );

		m_pSprites[int(m_ActionState)]->Update(elapsedSec);

		
	}
}

void JumpingEnemy::Draw( ) const
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

void JumpingEnemy::CheckActionState(const Avatar& avatar)
{
	if ( m_AttackDelay >= 1.f
		 && m_ActionState != ActionState::jumping
		 && IsAvatarInAttackZone( Point2f{ avatar.GetShape( ).left, avatar.GetShape( ).bottom } ))
	{
		m_AttackDelay = 0.f;
		
		m_Velocity.y = 400.f;

		if (m_FacingDirection == -1)
		{
			m_Velocity.x = -100.f;
		}
		else
		{
			m_Velocity.x = 100.f;
		}

		m_ActionState = ActionState::jumping;
	}
}

void JumpingEnemy::ChangeShapeDimensions( )
{
	m_Shape.width = m_pSprites[int(m_ActionState)]->GetFrameWidth() * m_Scale;
	m_Shape.height = m_pSprites[int(m_ActionState)]->GetFrameHeight() * m_Scale;

	m_LeftBoundary = m_Shape.left - 75.f;
	m_RightBoundary = m_Shape.left + m_Shape.width + 75.f;
}