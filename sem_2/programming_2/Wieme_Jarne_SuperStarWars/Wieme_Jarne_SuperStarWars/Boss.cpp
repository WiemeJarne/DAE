#include "pch.h"
#include "Boss.h"
#include "EnemyBulletManager.h"
#include "Sprite.h"
#include "Avatar.h"
#include "Level.h"
#include "Vector2f.h"
#include <iostream>

Boss::Boss(const Point2f& bottomLeftStartPoint, float scale, int health)
	: Enemy(bottomLeftStartPoint, scale, health, Vector2f{ 0.f, 0.f }, Vector2f{ 0.f, -981.f })
	, m_ActionState{ActionState::inground}
	, m_HasBeenSummoned{false}
	, m_TentaclesDelay{ }
{
	++m_amountOfEnemies;

	if (m_pEnemyBulletManager == nullptr)
	{
		m_pEnemyBulletManager = new EnemyBulletManager{ 1.f };
	}

	m_pSprites.push_back(new Sprite{ "Resources/PitMonster/Tentacles.png", Sprite::AnimType::repeatBackwards, 3, 1, 3.f, 1.f });
	m_pSprites.push_back(new Sprite{ "Resources/PitMonster/RiseOutGround.png", Sprite::AnimType::dontRepeat, 5, 1, 5.f, 1.f });
	m_pSprites.push_back(new Sprite{ "Resources/PitMonster/Attack.png", Sprite::AnimType::repeatBackwards, 6, 1, 3.f, 1.f });
}

Boss::~Boss( )
{
	for (Sprite* sprite : m_pSprites)
	{
		delete sprite;
	}
}

void Boss::Update(float elapsedSec, const Level& level, Avatar& avatar)
{
	std::cout << int(m_ActionState) << std::endl;


	CheckActionState(avatar);

	ChangeShapeDimensions( );

	m_Shape.left = m_StartPos.x - m_Shape.width;

	if ( avatar.GetShape().left < m_Shape.left
		 && m_ActionState != ActionState::attack
		 && m_ActionState != ActionState::summon )
	{
		m_FacingDirection = -1;
	}

	if ( avatar.GetShape().left >= m_Shape.left + m_Shape.width
		 && m_ActionState != ActionState::attack
		 && m_ActionState != ActionState::summon               )
	{
		m_FacingDirection = 1;
	}

	if ( m_ActionState == ActionState::tentacles
		 && m_HasBeenSummoned == true            )
	{
		m_TentaclesDelay += elapsedSec;
	}

	if (int(m_ActionState) >= 0)
	{
		m_pSprites[int(m_ActionState)]->Update(elapsedSec);
	}

	if (m_ActionState == ActionState::attack && m_pSprites[int(ActionState::attack)]->GetFrameNr() == m_pSprites[int(ActionState::attack)]->GetAmountOfFrames() - 3)
	{
		std::cout << "Attack\n";
		Attack( );
	}

	level.HandleCollision(m_Shape, m_Velocity);
}

void Boss::Draw( ) const
{
	glPushMatrix();

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

	glPopMatrix();
}

void Boss::CheckActionState(const Avatar& avatar)
{
	if (m_ActionState == ActionState::tentacles && m_TentaclesDelay >= 1.f && m_pSprites[int(ActionState::tentacles)]->GetFrameNr() == 0)
	{
		m_ActionState = ActionState::inground;
	}

	if (avatar.GetShape().left >= 7850.f && m_ActionState == ActionState::inground && m_HasBeenSummoned == false)
	{
		m_HasBeenSummoned = true;
		m_ActionState = ActionState::tentacles;
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

void Boss::ChangeShapeDimensions( )
{
	if (int(m_ActionState) >= 0)
	{
		m_Shape.width = m_pSprites[int(m_ActionState)]->GetFrameWidth() * m_Scale;
		m_Shape.height = m_pSprites[int(m_ActionState)]->GetFrameHeight() * m_Scale;
	}
}

void Boss::Attack( )
{
	m_pEnemyBulletManager->AddBullet(Point2f{ m_Shape.left + m_Shape.width / 2.f, m_Shape.height }, Vector2f{ 50.f, 50.f }, EnemyBullet::BulletType::boss);
}