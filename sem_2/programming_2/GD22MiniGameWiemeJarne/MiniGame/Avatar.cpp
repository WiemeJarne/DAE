#include "pch.h"
#include "Avatar.h"
#include "Level.h"
#include "Texture.h"
#include <iostream>
Avatar::Avatar()
	:m_Shape{50.f, 280.f, 0.f, 0.f}
	,m_HorizontalSpeed{200.f}
	,m_JumpSpeed{600.f}
	,m_Velocity{0.f, 0.f}
	,m_Acceleration{ 0.f, -981.f }
	,m_ActionState{ActionState::moving}
	,m_AccuTransFormSec{0.f}
	,m_MaxTransFormSec{1.f}
	,m_Power{0}
	,m_pSpriteTexture{ new Texture{"Resources/Images/AvatarSheet.png"}}
	,m_ClipHeight{97.f}
	,m_ClipWidth{72.f}
	,m_NrOfFrames{10}
	,m_NrFramesPerSec{10}
	,m_AnimTime{}
	,m_AnimFrame{}
{
	m_Shape.width = m_ClipWidth;
	m_Shape.height = m_ClipHeight;
}

Avatar::~Avatar()
{
	delete m_pSpriteTexture;
}

void Avatar::Update(float elapsedSec, const Level& level)
{
	CalculateFrame(elapsedSec);
	if (m_ActionState == ActionState::waiting)
	{
		Waiting(elapsedSec);
	}
	else if (m_ActionState == ActionState::moving)
	{
		Moving(elapsedSec, level);

		StayInLevelBoundaries(level);

		level.HandleCollision(m_Shape, m_Velocity);
	}
	else Transforming(elapsedSec, level);
}

void Avatar::Draw() const
{
	Rectf AvatarSrcRect{};
	AvatarSrcRect.left = m_AnimFrame * m_ClipWidth;
	AvatarSrcRect.bottom = (m_Power * 3 + int(m_ActionState)) * m_ClipHeight;
	AvatarSrcRect.width = m_ClipWidth;
	AvatarSrcRect.height = m_ClipHeight;

	glPushMatrix();
		glTranslatef(m_Shape.left, m_Shape.bottom, 0.f);
		if (m_Velocity.x < 0.f)
		{
			glScalef(-1, 1, 1);
			glTranslatef(-m_Shape.width, 0.f, 0.f);
		}
		m_pSpriteTexture->Draw(Rectf{}, AvatarSrcRect);
	glPopMatrix();
}

void Avatar::PowerUpHit()
{
	m_Velocity.x = 0.f;
	m_Velocity.y = 0.f;
	m_ActionState = ActionState::transforming;
}

Rectf Avatar::GetShape() const
{
	return m_Shape;
}

void Avatar::Waiting(float elapsedSec)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (pStates[SDL_SCANCODE_LEFT] || pStates[SDL_SCANCODE_RIGHT] || pStates[SDL_SCANCODE_UP])
	{
		m_AnimFrame = 0;
		m_AnimTime = 0.f;
		m_ActionState = ActionState::moving;
	}
}

void Avatar::Moving(float elapsedSec, const Level& level)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (level.IsOnGround(m_Shape, m_Velocity))
	{
		if (pStates[SDL_SCANCODE_UP])
		{
			m_Velocity.x = 0;
			m_Velocity.y = m_JumpSpeed;
		}

		if (pStates[SDL_SCANCODE_LEFT])
		{
			m_Velocity.x = -m_HorizontalSpeed;
		}

		if (pStates[SDL_SCANCODE_RIGHT])
		{
			m_Velocity.x = m_HorizontalSpeed;
		}
	}
	UpdatePos(elapsedSec);

	m_Velocity.y += m_Acceleration.y * elapsedSec;

	if (level.IsOnGround(m_Shape, m_Velocity) && !pStates[SDL_SCANCODE_LEFT] && !pStates[SDL_SCANCODE_RIGHT])
	{
		m_AnimFrame = 0;
		m_AnimTime = 0.f;
		m_ActionState = ActionState::waiting;
	}
}

void Avatar::UpdatePos(float elapsedSec)
{
	MoveHorizontal(elapsedSec);
	m_Shape.bottom += elapsedSec * m_Velocity.y;
}

void Avatar::MoveHorizontal(float elapsedSec)
{
	m_Shape.left += elapsedSec * m_Velocity.x;
}

void Avatar::Transforming(float elapsedSec, const Level& level)
{
	m_AccuTransFormSec += elapsedSec;

	if (m_AccuTransFormSec >= m_MaxTransFormSec)
	{
		m_AccuTransFormSec = 0.f;

		m_AnimFrame = 0;
		m_AnimTime = 0.f;
		++m_Power;
		m_ActionState = ActionState::moving;
	}
}

void Avatar::CalculateFrame(float elapsedSec)
{
	m_AnimTime += elapsedSec;
	if (1.f / m_NrFramesPerSec <= m_AnimTime)
	{
		m_AnimTime -= 1.f / m_NrFramesPerSec;
		m_AnimFrame = (m_AnimFrame + 1) % m_NrOfFrames;
	}
}

void Avatar::StayInLevelBoundaries(const Level& level)
{
	Rectf levelBoundaries{ level.GetBoundaries() };

	if (m_Shape.left < levelBoundaries.left)
	{
		m_Shape.left = levelBoundaries.left;
	}
	else if (m_Shape.left + m_Shape.width > levelBoundaries.left + levelBoundaries.width)
	{
		m_Shape.left = levelBoundaries.left + levelBoundaries.width - m_Shape.width;
	}

	if (m_Shape.bottom < levelBoundaries.bottom)
	{
		m_Shape.bottom = levelBoundaries.bottom;
	}
	else if (m_Shape.bottom + m_Shape.height > levelBoundaries.bottom + levelBoundaries.height)
	{
		m_Shape.bottom = levelBoundaries.bottom + levelBoundaries.height - m_Shape.height;
	}
}