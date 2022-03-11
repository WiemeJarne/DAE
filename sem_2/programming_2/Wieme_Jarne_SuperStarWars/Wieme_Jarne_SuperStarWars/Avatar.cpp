#include "pch.h"
#include "Avatar.h"
#include "Level.h"
#include "Texture.h"
#include <iostream>
Avatar::Avatar()
	:m_Shape{50.f, 30.f, 0.f, 0.f}
	,m_HorizontalSpeed{150.f}
	,m_JumpSpeed{400.f}
	,m_Velocity{0.f, 0.f}
	,m_Acceleration{ 0.f, -981.f }
	,m_ActionState{ActionState::waiting}
	,m_Power{0}
	,m_pWalkTexture{ new Texture{"Resources/Luke/Walk.png"}}
	,m_pIdleTexture{ new Texture{"Resources/Luke/Idle.png"}}
	,m_pJumpTexture{ new Texture{"Resources/Luke/Jump.png"}}
	,m_NrOfWalkFrames{8}
	,m_NrOfIdleFrames{3}
	,m_NrOfJumpFrames{3}
	,m_NrFramesPerSec{10}
	,m_AnimTime{}
	,m_AnimFrame{}
	,m_FrameDirection{1}
{
	m_ClipWidth = m_pWalkTexture->GetWidth() / 8.f;
	m_ClipHeight = m_pWalkTexture->GetHeight();

	m_Shape.width = m_ClipWidth;
	m_Shape.height = m_ClipHeight;
}

Avatar::~Avatar()
{
	delete m_pWalkTexture;
	delete m_pIdleTexture;
	delete m_pJumpTexture;
}

void Avatar::Update(float elapsedSec, const Level& level)
{
	CheckActionState(level);

	if (!level.IsOnGround(m_Shape))
	{
		m_ActionState = ActionState::jumping;
	}

	CalculateFrame(elapsedSec);

	if (m_ActionState == ActionState::waiting)
	{
		m_NrFramesPerSec = 2;
		ChangeClipWidthAndHeight(m_pIdleTexture, m_NrOfIdleFrames);
	}
	else if (m_ActionState == ActionState::walking || m_ActionState == ActionState::jumping)
	{
		if (m_ActionState == ActionState::walking)
		{
			m_NrFramesPerSec = 10;
			ChangeClipWidthAndHeight(m_pWalkTexture, m_NrOfWalkFrames);
		}
		else
		{
			m_NrFramesPerSec = 10;
			ChangeClipWidthAndHeight(m_pJumpTexture, m_NrOfJumpFrames);
		}
		
		Moving(elapsedSec, level);

		StayInLevelBoundaries(level);

		level.HandleCollision(m_Shape, m_Velocity);
	}
}

void Avatar::Draw() const
{
	glPushMatrix();
		glTranslatef(m_Shape.left, m_Shape.bottom, 0.f);
		CheckAndChangeWalkDirection();
		DrawAvatar();
	glPopMatrix();
}

Rectf Avatar::GetShape() const
{
	return m_Shape;
}

void Avatar::CheckAndChangeWalkDirection() const
{
	if (m_Velocity.x < 0.f)
	{
		glScalef(-1, 1, 1);
		glTranslatef(-m_Shape.width, 0.f, 0.f);
	}
	else glScalef(1, 1, 1);
}

void Avatar::DrawAvatar() const
{
	Rectf avatarSrcRect{};
	avatarSrcRect.left = m_AnimFrame * m_ClipWidth;
	avatarSrcRect.bottom = (m_Power * 3 + int(m_ActionState)) * m_ClipHeight;
	avatarSrcRect.width = m_ClipWidth;
	avatarSrcRect.height = m_ClipHeight;

	if (m_ActionState == ActionState::waiting)
	{
		m_pIdleTexture->Draw(Rectf{}, avatarSrcRect);
	}
	else if (m_ActionState == ActionState::walking)
	{
		m_pWalkTexture->Draw(Rectf{}, avatarSrcRect);
	}
	else if (m_ActionState == ActionState::jumping)
	{
		m_pJumpTexture->Draw(Rectf{}, avatarSrcRect);
	}
}

void Avatar::CheckActionState(const Level& level)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (level.IsOnGround(m_Shape) && (pStates[SDL_SCANCODE_LEFT] || pStates[SDL_SCANCODE_RIGHT]))
	{
		m_ActionState = ActionState::walking;
	}
	else if (level.IsOnGround(m_Shape) && pStates[SDL_SCANCODE_UP])
	{
		m_AnimFrame = 0;
		m_AnimTime = 0.f;
		m_ActionState = ActionState::jumping;
	}
	else if (level.IsOnGround(m_Shape))
	{
		m_AnimFrame = 0;
		m_AnimTime = 0.f;
		m_ActionState = ActionState::waiting;
	}
}

void Avatar::Moving(float elapsedSec, const Level& level)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (level.IsOnGround(m_Shape))
	{
		if (pStates[SDL_SCANCODE_UP])
		{
			m_Velocity.y = m_JumpSpeed;
			m_Velocity.x = 0.f;
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

	if (level.IsOnGround(m_Shape) && !pStates[SDL_SCANCODE_LEFT] && !pStates[SDL_SCANCODE_RIGHT])
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

void Avatar::CalculateFrame(float elapsedSec)
{
	m_AnimTime += elapsedSec;
	if (1.f / m_NrFramesPerSec <= m_AnimTime)
	{
		m_AnimTime -= 1.f / m_NrFramesPerSec;

		if (m_ActionState == ActionState::waiting)
		{
			m_AnimFrame += m_FrameDirection;

			if (m_AnimFrame == m_NrOfIdleFrames - 1 || m_AnimFrame == 0)
			{
				m_FrameDirection *= -1;
			}
		}
		else if (m_ActionState == ActionState::walking)
		{
			m_AnimFrame = (m_AnimFrame + 1) % m_NrOfWalkFrames;
		}
		else if (m_ActionState == ActionState::jumping && m_AnimFrame < m_NrOfJumpFrames - 1)
		{
			++m_AnimFrame;
		}
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
		m_Shape.bottom = levelBoundaries.bottom + levelBoundaries.height - m_Shape.bottom;
	}
}

void Avatar::ChangeClipWidthAndHeight(const Texture* texture, int nrOfFrames)
{
	m_ClipWidth = texture->GetWidth() / nrOfFrames;
	m_ClipHeight = texture->GetHeight();
}