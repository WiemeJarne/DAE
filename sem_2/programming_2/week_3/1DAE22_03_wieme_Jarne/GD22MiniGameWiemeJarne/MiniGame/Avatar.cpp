#include "pch.h"
#include "Avatar.h"
#include "Level.h"

Avatar::Avatar()
	:m_Shape{50.f, 280.f, 36.f, 97.f}
	,m_HorizontalSpeed{200.f}
	,m_JumpSpeed{600.f}
	,m_Velocity{0.f, 0.f}
	,m_Acceleration{ 0.f, -981.f }
	,m_ActionState{ActionState::moving}
	,m_AccuTransFormSec{0.f}
	,m_MaxTransFormSec{1.f}
	,m_Power{0}
{
	//no code
}

void Avatar::Update(float elapsedSec, const Level& level)
{
	if (m_ActionState == ActionState::waiting)
	{
		Waiting(elapsedSec);
	}
	else if (m_ActionState == ActionState::moving)
	{
		Moving(elapsedSec, level);

		level.HandleCollision(m_Shape, m_Velocity);
	}
	else Transforming(elapsedSec, level);
}

void Avatar::Draw() const
{
	if (m_ActionState == ActionState::waiting)
	{
		utils::SetColor(Color4f{ 1.f, 1.f, 0.f, 1.f });
	}
	else if (m_ActionState == ActionState::moving)
	{
		utils::SetColor(Color4f{ 1.f, 0.f, 0.f, 1.f });
	}
	else if (m_ActionState == ActionState::transforming)
	{
		utils::SetColor(Color4f{ 0.f, 0.f, 1.f, 1.f });
	}

	utils::FillRect(m_Shape);

	const float spaceBetweenSmallRects{ 5.f };

	Rectf smallRect{};
	smallRect.left = m_Shape.left + spaceBetweenSmallRects;
	smallRect.bottom = m_Shape.bottom + spaceBetweenSmallRects;
	smallRect.width = 5.f;
	smallRect.height = 5.f;

	utils::SetColor(Color4f{ 0.f, 0.f, 0.f, 1.f });

	for (int index{}; index < m_Power; ++index)
	{
		utils::FillRect(smallRect);
		smallRect.bottom += smallRect.height + spaceBetweenSmallRects;
	}
}

void Avatar::PowerUpHit()
{
	++m_Power;
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
		m_ActionState = ActionState::moving;
	}
}

void Avatar::Moving(float elapsedSec, const Level& level)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (pStates[SDL_SCANCODE_LEFT] && level.IsOnGround(m_Shape))
	{
		ChangeXVelocity();
		MoveHorizontal(-elapsedSec);
	}
	else if (pStates[SDL_SCANCODE_RIGHT] && level.IsOnGround(m_Shape))
	{
		ChangeXVelocity();
		MoveHorizontal(elapsedSec);
	}
	else if (pStates[SDL_SCANCODE_UP] && level.IsOnGround(m_Shape))
	{
		ChangeYVelocity();
	}

	m_Shape.bottom += elapsedSec * m_Velocity.y;

	if (level.IsOnGround(m_Shape) == false)
	{
		m_Velocity.y += m_Acceleration.y * elapsedSec;
	}

	if (level.IsOnGround(m_Shape) && !pStates[SDL_SCANCODE_LEFT] && !pStates[SDL_SCANCODE_RIGHT])
	{
		m_ActionState = ActionState::waiting;
	}
}

void Avatar::ChangeYVelocity()
{
	m_Velocity.y = m_JumpSpeed;
}

void Avatar::ChangeXVelocity()
{
	m_Velocity.x = m_HorizontalSpeed;
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

		m_ActionState = ActionState::moving;
	}
}