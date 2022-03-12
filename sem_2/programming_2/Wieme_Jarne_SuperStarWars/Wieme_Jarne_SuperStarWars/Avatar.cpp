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
	,m_pShootTexture{ new Texture{"Resources/Luke/ShootRight.png"}}
	,m_pShootDownTexture{ new Texture{"Resources/Luke/ShootDownRight.png"}}
	,m_pShootUpTexture{ new Texture{"Resources/Luke/ShootUpRight.png"}}
	,m_NrOfWalkFrames{8}
	,m_NrOfIdleFrames{3}
	,m_NrOfJumpFrames{3}
	,m_NrOfShootFrames{2}
	,m_NrFramesPerSec{10}
	,m_AnimTime{}
	,m_AnimFrame{}
	,m_FrameDirection{1}
{
	m_ClipWidth = m_pIdleTexture->GetWidth() / m_NrOfIdleFrames;
	m_ClipHeight = m_pIdleTexture->GetHeight();

	m_Shape.width = m_ClipWidth;
	m_Shape.height = m_ClipHeight;
}

Avatar::~Avatar()
{
	delete m_pWalkTexture;
	delete m_pIdleTexture;
	delete m_pJumpTexture;
	delete m_pShootTexture;
	delete m_pShootDownTexture;
	delete m_pShootUpTexture;
}

void Avatar::Update(float elapsedSec, const Level& level)
{
	CheckActionState(level);
	CalculateFrame(elapsedSec);

	if (!level.IsOnGround(m_Shape))
	{
		m_ActionState = ActionState::jumping;
	}

	switch (m_ActionState)
	{
	case ActionState::waiting:
		m_NrFramesPerSec = 2;
		ChangeClipWidthAndHeight(m_pIdleTexture, m_NrOfIdleFrames);
		break;
	
	case ActionState::walking:
		m_NrFramesPerSec = 10;
		ChangeClipWidthAndHeight(m_pWalkTexture, m_NrOfWalkFrames);

		Moving(elapsedSec, level);
		StayInLevelBoundaries(level);
		level.HandleCollision(m_Shape, m_Velocity);
		break;

	case ActionState::jumping:
		m_NrFramesPerSec = 7;
		ChangeClipWidthAndHeight(m_pJumpTexture, m_NrOfJumpFrames);

		Moving(elapsedSec, level);
		StayInLevelBoundaries(level);
		level.HandleCollision(m_Shape, m_Velocity);
		break;

	case ActionState::shoot:
		m_NrFramesPerSec = 10;
		ChangeClipWidthAndHeight(m_pShootTexture, m_NrOfShootFrames);
		break;

	case ActionState::shootDown:
		m_NrFramesPerSec = 10;
		ChangeClipWidthAndHeight(m_pShootDownTexture, m_NrOfShootFrames);
		break;

	case ActionState::shootUp:
		m_NrFramesPerSec = 10;
		ChangeClipWidthAndHeight(m_pShootUpTexture, m_NrOfShootFrames);
		break;
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

	switch (m_ActionState)
	{
	case ActionState::waiting:
		m_pIdleTexture->Draw(Rectf{}, avatarSrcRect);
		break;

	case ActionState::walking:
		m_pWalkTexture->Draw(Rectf{}, avatarSrcRect);
		break;

	case ActionState::jumping:
		m_pJumpTexture->Draw(Rectf{}, avatarSrcRect);
		break;

	case ActionState::shoot:
		m_pShootTexture->Draw(Rectf{}, avatarSrcRect);
		break;

	case ActionState::shootDown:
		m_pShootDownTexture->Draw(Rectf{}, avatarSrcRect);
		break;

	case ActionState::shootUp:
		m_pShootUpTexture->Draw(Rectf{}, avatarSrcRect);
	}
}

void Avatar::CheckActionState(const Level& level)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (level.IsOnGround(m_Shape))
	{
		if ((pStates[SDL_SCANCODE_LEFT] || pStates[SDL_SCANCODE_RIGHT]))
		{
			m_ActionState = ActionState::walking;
		}
		else if (pStates[SDL_SCANCODE_Z])
		{
			m_AnimFrame = 0;
			m_AnimTime = 0.f;
			m_ActionState = ActionState::jumping;
		}
		else if (pStates[SDL_SCANCODE_A])
		{
			m_ActionState = ActionState::shoot;
		}
		else if (/*pStates[SDL_SCANCODE_A] &&*/ pStates[SDL_SCANCODE_DOWN])
		{
			m_ActionState = ActionState::shootDown;
		}
		else if (/*pStates[SDL_SCANCODE_A] &&*/ pStates[SDL_SCANCODE_UP])
		{
			m_ActionState = ActionState::shootUp;
		}
		else
		{
			m_ActionState = ActionState::waiting;
		}
	}
}

void Avatar::Moving(float elapsedSec, const Level& level)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (level.IsOnGround(m_Shape))
	{
		if (pStates[SDL_SCANCODE_Z])
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
	std::cout << int(m_ActionState) << std::endl;
	if (1.f / m_NrFramesPerSec <= m_AnimTime)
	{
		m_AnimTime -= 1.f / m_NrFramesPerSec;

		switch (m_ActionState)
		{
		case ActionState::waiting:
			m_AnimFrame += m_FrameDirection;

			if (m_AnimFrame == m_NrOfIdleFrames - 1 || m_AnimFrame == 0)
			{
				m_FrameDirection *= -1;
			}
			break;

		case ActionState::walking:
			m_AnimFrame = (m_AnimFrame + 1) % m_NrOfWalkFrames;
			break;

		case ActionState::jumping:
			if (m_AnimFrame < m_NrOfJumpFrames - 1)
			{
				++m_AnimFrame;
			}
			break;

		case ActionState::shoot:
		case ActionState::shootDown:
		case ActionState::shootUp:
			m_AnimFrame = (m_AnimFrame + 1) % m_NrOfShootFrames;
			break;
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

	m_Shape.width = m_ClipWidth;
	m_Shape.height = m_ClipHeight;
}