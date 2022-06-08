#include "pch.h"
#include "Scorpion.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "Level.h"
#include "Avatar.h"
#include "BulletManager.h"

Scorpion::Scorpion(const Point2f& bottomLeftStartPoint, float scale, int health, TextureManager& pTextureManager, BulletManager& pBulletManager)
	: Enemy(bottomLeftStartPoint, scale, health, Vector2f{ 25.f, 0.f }, Vector2f{ 0.f, -981.f }, 60.f)
	, m_ActionState{ }
	, m_pBulletManager{ pBulletManager }
{
	m_ActionState = ActionState::moving;

	m_pSprites.push_back(new Sprite{ pTextureManager.GetTexture("Resources/Enemies/Enemy1Walk.png"), Sprite::AnimType::loop, 4, 1, 10 });
	m_pSprites.push_back(new Sprite{ pTextureManager.GetTexture("Resources/Enemies/Enemy1Attack.png"), Sprite::AnimType::loop, 4, 1, 5 });

	m_Shape.width = m_pSprites[int(m_ActionState)]->GetFrameWidth( ) * m_Scale;
	m_Shape.height = m_pSprites[int(m_ActionState)]->GetFrameHeight( ) * m_Scale;

	m_LeftBoundary = m_Shape.left - 40.f;
	m_RightBoundary = m_Shape.left + m_Shape.width + 40.f;
}

void Scorpion::Update(float elapsedSec, const Level& level, Avatar& avatar)
{
	if (m_Health <= 0)
	{
		m_SecondsAftherDeath += elapsedSec;

		if (m_SecondsAftherDeath >= 3.f)
		{
			Respawn( );
		}
	}

	if (m_Health > 0)
	{
		m_AttackDelay += elapsedSec;

		CheckActionState(avatar);

		ChangeShapeDimensions( );

		Moving(elapsedSec);

		switch (m_ActionState)
		{
		case Scorpion::ActionState::attacking:

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

void Scorpion::Draw() const
{
	glPushMatrix();

	Enemy::Draw();

	if (m_Health > 0)
	{
		m_pSprites[int(m_ActionState)]->Draw( );
	}

	glPopMatrix( );
}

void Scorpion::Attack()
{
	Vector2f velocity{ 0, 100.f };

	if (m_FacingDirection == -1)
	{
		velocity.x = -200.f;
	}
	else
	{
		velocity.x = 200.f;
	}

	m_pBulletManager.AddBullet(Point2f{ m_Shape.left + m_Shape.width * 0.5f, m_Shape.bottom + m_Shape.height * 0.7f }, velocity, 1.f, Bullet::Type::Enemy);
}

void Scorpion::CheckActionState(const Avatar& avatar)
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

void Scorpion::ChangeShapeDimensions( )
{
	m_Shape.width = m_pSprites[int(m_ActionState)]->GetFrameWidth() * m_Scale;
	m_Shape.height = m_pSprites[int(m_ActionState)]->GetFrameHeight() * m_Scale;
}