#include "pch.h"
#include "Avatar.h"
#include "Level.h"
#include "Texture.h"
#include "BulletManager.h"
#include "Sprite.h"
#include <iostream>

Avatar::Avatar()
	:m_Shape{50.f, 30.f, 0.f, 0.f}
	,m_HorizontalSpeed{150.f}
	,m_JumpSpeed{400.f}
	,m_Velocity{0.f, 0.f}
	,m_Acceleration{ 0.f, -981.f }
	,m_ActionState{ActionState::idle}
	,m_Power{0}
	,m_NrOfIdleFrames{3}
	,m_NrOfWalkFrames{8}
	,m_NrOfSlideFrames{5}
	,m_NrOfJumpFrames{3}
	,m_NrOfShootFrames{2}
	,m_NrFramesPerSec{10}
	,m_AnimTime{}
	,m_AnimFrame{}
	,m_IdleFrameDirection{1}
	,m_AvatarFacingDirection{1}
	,m_pBullets{}
	,m_ShootDelay{}
	,m_BulletVelocity{500.f}
	,m_pBulletManager{new BulletManager(0.65f)}
{
	InitializeSprites( );

	m_Shape.width = m_sprites[int(m_ActionState)]->GetFrameWidth() / m_NrOfIdleFrames;
	m_Shape.height = m_sprites[int(m_ActionState)]->GetFrameHeight();
}

Avatar::~Avatar()
{
	for (Sprite* sprite : m_sprites)
	{
		delete sprite;
	}

	delete m_pBulletManager;
}

void Avatar::Update(float elapsedSec, const Level& level)
{
	m_ShootDelay += elapsedSec;

	m_pBulletManager->UpdateBullets(elapsedSec);
	m_sprites[int(m_ActionState) - 1]->Update(elapsedSec);

	HandleInput(level);

	if (!level.IsOnGround(m_Shape))
	{
		m_ActionState = ActionState::jumping;
	}

	switch (m_ActionState)
	{
	case ActionState::idle:
		m_NrFramesPerSec = 3;
		ChangeShapeDimensions(m_NrOfIdleFrames);
		break;
	
	case ActionState::walking:
		m_NrFramesPerSec = 10;
		ChangeShapeDimensions(m_NrOfWalkFrames);
		Moving(elapsedSec, level);
		break;

	case ActionState::sliding:
		m_NrFramesPerSec = 15;
		ChangeShapeDimensions(m_NrOfSlideFrames);
		Moving(elapsedSec, level);
		break;

	case ActionState::jumping:
		m_NrFramesPerSec = 7;
		ChangeShapeDimensions(m_NrOfJumpFrames);
		Moving(elapsedSec, level);
		break;

	case ActionState::shoot:
		m_NrFramesPerSec = 10;
		ChangeShapeDimensions(m_NrOfShootFrames);
		Shoot(Vector2f{m_BulletVelocity * m_AvatarFacingDirection, 0.f});
		break;

	case ActionState::shootDown:
		m_NrFramesPerSec = 10;
		ChangeShapeDimensions(m_NrOfShootFrames);
		Shoot(Vector2f{ m_BulletVelocity * m_AvatarFacingDirection, -m_BulletVelocity });
		break;

	case ActionState::shootUp:
		m_NrFramesPerSec = 10;
		ChangeShapeDimensions(m_NrOfShootFrames);
		Shoot(Vector2f{ 0.f, m_BulletVelocity });
		break;

	case ActionState::shootUpDiagonal:
		m_NrFramesPerSec = 10;
		ChangeShapeDimensions(m_NrOfShootFrames);
		Shoot(Vector2f{ m_BulletVelocity * m_AvatarFacingDirection, m_BulletVelocity });
		break;
	}

	StayInLevelBoundaries(level);
	level.HandleCollision(m_Shape, m_Velocity);
}

void Avatar::Draw() const
{
	glPushMatrix();

		m_pBulletManager->DrawBullets();

		std::cout << m_Shape.left << std::endl;

		glTranslatef(m_Shape.left, m_Shape.bottom, 0.f);

		glScalef(GLfloat(m_AvatarFacingDirection), 1, 1);

		if (m_AvatarFacingDirection == -1)
		{
			glTranslatef(-m_Shape.width, 0.f, 0.f);
		}

		DrawAvatar();

	glPopMatrix();
}

Rectf Avatar::GetShape() const
{
	return m_Shape;
}

void Avatar::DrawAvatar() const
{
	switch (m_ActionState)
	{
	case ActionState::idle:
		m_sprites[int(m_ActionState) - 1]->Draw(Point2f{});
		break;

	case ActionState::walking:
		m_sprites[int(m_ActionState) - 1]->Draw(Point2f{});
		break;

	case ActionState::sliding:
		m_sprites[int(m_ActionState) - 1]->Draw(Point2f{});
		break;

	case ActionState::jumping:
		m_sprites[int(m_ActionState) - 1]->Draw(Point2f{});
		break;

	case ActionState::shoot:
		m_sprites[int(m_ActionState) - 1]->Draw(Point2f{});
		break;

	case ActionState::shootDown:
		m_sprites[int(m_ActionState) - 1]->Draw(Point2f{});
		break;

	case ActionState::shootUp:
		m_sprites[int(m_ActionState) - 1]->Draw(Point2f{});
		break;

	case ActionState::shootUpDiagonal:
		m_sprites[int(m_ActionState) - 1]->Draw(Point2f{});
		break;
	}
}

void Avatar::HandleInput(const Level& level)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (level.IsOnGround(m_Shape))
	{
		if (pStates[SDL_SCANCODE_LEFT])
		{
			m_AvatarFacingDirection = -1;
			m_Velocity.x = m_HorizontalSpeed * m_AvatarFacingDirection;
			m_ActionState = ActionState::walking;
		}
		
		if (pStates[SDL_SCANCODE_RIGHT])
		{
			m_AvatarFacingDirection = 1;
			m_Velocity.x = m_HorizontalSpeed * m_AvatarFacingDirection;
			m_ActionState = ActionState::walking;
		}

		if (pStates[SDL_SCANCODE_Z])
		{
			m_AnimFrame = 0;
			m_AnimTime = 0.f;
			m_Velocity.y = m_JumpSpeed;
			m_ActionState = ActionState::jumping;
		}

		if (pStates[SDL_SCANCODE_DOWN])
		{
			if (m_ActionState != ActionState::sliding)
			{
				m_AnimFrame = 0;
				m_AnimTime = 0.f;
			}

			const int speedMultiplier{ 2 };

			m_Velocity.x = m_HorizontalSpeed * m_AvatarFacingDirection * speedMultiplier;

			m_ActionState = ActionState::sliding;
		}
	
		if (pStates[SDL_SCANCODE_A])
		{
			m_ActionState = ActionState::shoot;

			if (pStates[SDL_SCANCODE_LEFT])
			{
				m_AvatarFacingDirection = -1;
			}

			if (pStates[SDL_SCANCODE_RIGHT])
			{
				m_AvatarFacingDirection = 1;
			}

			if (pStates[SDL_SCANCODE_DOWN])
			{
				m_ActionState = ActionState::shootDown;
			}
			else if (pStates[SDL_SCANCODE_UP])
			{
				m_ActionState = ActionState::shootUp;

				if (pStates[SDL_SCANCODE_RIGHT] && m_AvatarFacingDirection == 1)
				{
					m_ActionState = ActionState::shootUpDiagonal;
				}
				else if (pStates[SDL_SCANCODE_LEFT])
				{
					m_ActionState = ActionState::shootUpDiagonal;
				}
			}
		}

		if (	!pStates[SDL_SCANCODE_A]
		     && !pStates[SDL_SCANCODE_LEFT] 
			 && !pStates[SDL_SCANCODE_RIGHT]
			 && !pStates[SDL_SCANCODE_Z]
			 && !pStates[SDL_SCANCODE_DOWN]  )
		{
			if (m_ActionState != ActionState::idle)
			{
				m_AnimFrame = 0;
				m_AnimTime = 0.f;
			}

			m_Velocity.x = 0.f;
			m_Velocity.y = 0.f;

			m_ActionState = ActionState::idle;
		}
	}
}

void Avatar::InitializeSprites( )
{
	float framesPerSec{3};

	m_sprites.push_back(new Sprite{ "Resources/Luke/Idle.png", m_NrOfIdleFrames, 1, framesPerSec, false });

	framesPerSec = 10;
	m_sprites.push_back(new Sprite{ "Resources/Luke/Walk.png", m_NrOfWalkFrames, 1, framesPerSec, true });

	framesPerSec = 15;
	m_sprites.push_back(new Sprite{ "Resources/Luke/Slide.png", m_NrOfSlideFrames, 1, framesPerSec, false });

	framesPerSec = 7;
	m_sprites.push_back(new Sprite{ "Resources/Luke/Jump.png", m_NrOfJumpFrames, 1, framesPerSec, false });

	framesPerSec = 10;
	m_sprites.push_back(new Sprite{ "Resources/Luke/ShootRight.png", m_NrOfShootFrames, 1, framesPerSec, true });

	m_sprites.push_back(new Sprite{ "Resources/Luke/ShootDownRight.png", m_NrOfShootFrames, 1, framesPerSec, true });

	m_sprites.push_back(new Sprite{ "Resources/Luke/ShootUp.png", m_NrOfShootFrames, 1, framesPerSec, true });

	m_sprites.push_back(new Sprite{ "Resources/Luke/ShootUpRight.png", m_NrOfShootFrames, 1, framesPerSec, true });
}

void Avatar::Moving(float elapsedSec, const Level& level)
{
	m_Velocity.y += m_Acceleration.y * elapsedSec;

	UpdatePos(elapsedSec);

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

		switch (m_ActionState)
		{
		case ActionState::idle:
			
			m_AnimFrame += m_IdleFrameDirection;

			if (m_AnimFrame == m_NrOfIdleFrames - 1 || m_AnimFrame == 0)
			{
				m_IdleFrameDirection *= -1;
			}

			break;

		case ActionState::walking:

			m_AnimFrame = (m_AnimFrame + 1) % m_NrOfWalkFrames;

			break;

		case ActionState::sliding:

			if (m_AnimFrame < m_NrOfSlideFrames - 1)
			{
				++m_AnimFrame;
			}

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
		case ActionState::shootUpDiagonal:

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
		m_Shape.bottom = levelBoundaries.bottom + levelBoundaries.height - m_Shape.height;
	}
}

void Avatar::ChangeShapeDimensions(int nrOfFrames)
{
	m_Shape.width = m_sprites[int(m_ActionState) - 1]->GetFrameWidth() / nrOfFrames;
	m_Shape.height = m_sprites[int(m_ActionState) - 1]->GetFrameHeight();
}

void Avatar::Shoot(const Vector2f& bulletVelocity)
{
	if (m_ShootDelay > 0.1f)
	{
		m_ShootDelay = 0;

		Point2f bulletBottomLeftPoint{};

		switch (m_ActionState)
		{
		case ActionState::shoot:

			bulletBottomLeftPoint.y = m_Shape.bottom + m_Shape.height * 0.77f;

			if (m_AvatarFacingDirection == 1)
			{
				bulletBottomLeftPoint.x = m_Shape.left + m_Shape.width * 0.95f;
			}
			else
			{
				bulletBottomLeftPoint.x = m_Shape.left + m_Shape.width * 0.05f;
			}
			
			break;

		case ActionState::shootDown:

			bulletBottomLeftPoint.y = m_Shape.bottom + m_Shape.height * 0.45f;

			if (m_AvatarFacingDirection == 1)
			{
				bulletBottomLeftPoint.x = m_Shape.left + m_Shape.width * 0.9f;
			}
			else
			{
				bulletBottomLeftPoint.x = m_Shape.left + m_Shape.width * 0.1f;
			}

			break;
			
		case ActionState::shootUp:

			bulletBottomLeftPoint.x = m_Shape.left + m_Shape.width * 0.53f;

			bulletBottomLeftPoint.y = m_Shape.bottom + m_Shape.height;

			break;

		case ActionState::shootUpDiagonal:
			
			bulletBottomLeftPoint.y = m_Shape.bottom + m_Shape.height * 0.98f;

			if (m_AvatarFacingDirection == 1)
			{
				bulletBottomLeftPoint.x = m_Shape.left + m_Shape.width * 0.95f;
			}
			else
			{
				bulletBottomLeftPoint.x = m_Shape.left + m_Shape.width * 0.05f;
			}

			break;
		}
		
		m_pBulletManager->AddBullet(bulletBottomLeftPoint, bulletVelocity);
	}
}