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
		Waiting(elapsedSec, level);
	}

	else if (m_ActionState == ActionState::moving)
	{
		const Uint8* pStates = SDL_GetKeyboardState(nullptr);

		if (pStates[SDL_SCANCODE_LEFT])
		{
			m_Shape.left -= elapsedSec * m_Velocity.x;
		}
		else if (pStates[SDL_SCANCODE_RIGHT])
		{
			m_Shape.left += elapsedSec * m_Velocity.x;
		}
		else if (pStates[SDL_SCANCODE_UP])
		{
			m_Shape.bottom += elapsedSec * m_Velocity.y;
		}

		m_Shape.bottom += elapsedSec * m_Acceleration.y;
		level.HandleCollision(m_Shape, m_Acceleration);

		if (level.IsOnGround(m_Shape)) m_ActionState = ActionState::waiting;
	}
	else Transforming(elapsedSec);
}

void Avatar::Draw() const
{
	utils::SetColor(Color4f{ 1.f, 1.f, 0.f, 1.f });
	utils::FillRect(m_Shape);
}

void Avatar::PowerUpHit()
{
	
}

Rectf Avatar::GetShape() const
{
	return m_Shape;
}

void Avatar::Waiting(float elapsedSec, const Level& level)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (level.IsOnGround(m_Shape))
	{
		if (pStates[SDL_SCANCODE_UP])
		{
			m_ActionState = ActionState::moving;
			Jump();
		}
		else
		{
			MoveHorizontal();
		}
	}
}

void Avatar::MoveHorizontal()
{
	m_Velocity.x = m_HorizontalSpeed;
	m_ActionState = ActionState::moving;
}

void Avatar::Jump()
{
	m_Velocity.y = m_JumpSpeed;
	m_ActionState = ActionState::moving;
}

void Avatar::Transforming(float elapsedSec)
{

}