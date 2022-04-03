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
	,m_AvatarFacingDirection{1}
	,m_pBullets{}
	,m_ShootDelay{}
	,m_BulletVelocity{500.f}
	,m_pBulletManager{new BulletManager(0.65f)}
{
	InitializeSprites( );
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

	ChangeShapeDimensions(m_sprites[int(m_ActionState)]->GetAmountOfFrames());

	m_pBulletManager->UpdateBullets(elapsedSec);
	m_sprites[int(m_ActionState)]->Update(elapsedSec);

	HandleInput(level);

	if (!level.IsOnGround(m_Shape))
	{
		m_ActionState = ActionState::jumping;
	}

	switch (m_ActionState)
	{
	case ActionState::sliding:
		Moving(elapsedSec);
		break;

	case ActionState::walking:
	case ActionState::jumping:
		Moving(elapsedSec);
		break;

	case ActionState::shoot:
		Shoot(Vector2f{m_BulletVelocity * m_AvatarFacingDirection, 0.f});
		break;

	case ActionState::shootDown:
		Shoot(Vector2f{ m_BulletVelocity * m_AvatarFacingDirection, -m_BulletVelocity });
		break;

	case ActionState::shootUp:
		Shoot(Vector2f{ 0.f, m_BulletVelocity });
		break;

	case ActionState::shootUpDiagonal:
		Shoot(Vector2f{ m_BulletVelocity * m_AvatarFacingDirection, m_BulletVelocity });
		break;

	case ActionState::jumpShoot:
		Moving(elapsedSec);
		Shoot(Vector2f{ m_BulletVelocity * m_AvatarFacingDirection, 0.f });
		break;

	case ActionState::jumpShootDown:
		Shoot(Vector2f{ m_BulletVelocity * m_AvatarFacingDirection, -m_BulletVelocity });
		Moving(elapsedSec);
		break;

	case ActionState::jumpShootUp:
		Shoot(Vector2f{ 0.f, m_BulletVelocity });
		Moving(elapsedSec);
		break;

	case ActionState::jumpShootUpDiagonal:
		Shoot(Vector2f{ m_BulletVelocity * m_AvatarFacingDirection, m_BulletVelocity });
		Moving(elapsedSec);
		break;
	}

	StayInLevelBoundaries(level);
	level.HandleCollision(m_Shape, m_Velocity);
}

void Avatar::Draw() const
{
	glPushMatrix();

		m_pBulletManager->DrawBullets();

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
	m_sprites[int(m_ActionState)]->Draw(Point2f{});
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
			m_sprites[int(ActionState::jumping)]->SetFrameNr(0);
			m_sprites[int(ActionState::jumping)]->SetAccuSec(0.f);

			m_Velocity.y = m_JumpSpeed;
			m_ActionState = ActionState::jumping;
		}

		if (pStates[SDL_SCANCODE_DOWN])
		{
			if (m_ActionState != ActionState::sliding)
			{
				m_sprites[int(ActionState::sliding)]->SetFrameNr(0);
				m_sprites[int(ActionState::sliding)]->SetAccuSec(0.f);
			}

			const int speedMultiplier{ 2 };

			m_Velocity.x = m_HorizontalSpeed * m_AvatarFacingDirection * speedMultiplier;

			m_ActionState = ActionState::sliding;
		}
	
		if (pStates[SDL_SCANCODE_A])
		{
			m_ActionState = ActionState::shoot;

			if (pStates[SDL_SCANCODE_DOWN])
			{
				m_ActionState = ActionState::shootDown;
			}

			if (pStates[SDL_SCANCODE_UP])
			{
				m_ActionState = ActionState::shootUp;

				if (pStates[SDL_SCANCODE_RIGHT] && m_AvatarFacingDirection == 1)
				{
					m_ActionState = ActionState::shootUpDiagonal;
				}
				
				if (pStates[SDL_SCANCODE_LEFT])
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
				m_sprites[int(ActionState::idle)]->SetFrameNr(0);
				m_sprites[int(ActionState::idle)]->SetAccuSec(0.f);
			}

			m_Velocity.x = 0.f;
			m_Velocity.y = 0.f;

			m_ActionState = ActionState::idle;
		}
	}
	
	if(!level.IsOnGround(m_Shape))
	{
		if (pStates[SDL_SCANCODE_A])
		{
			m_ActionState = ActionState::jumpShoot;

			if (pStates[SDL_SCANCODE_DOWN])
			{
				m_ActionState = ActionState::jumpShootDown;
			}

			if (pStates[SDL_SCANCODE_UP])
			{
				m_ActionState = ActionState::jumpShootUp;

				if (pStates[SDL_SCANCODE_RIGHT] && m_AvatarFacingDirection == 1)
				{
					m_ActionState = ActionState::jumpShootUpDiagonal;
				}

				if (pStates[SDL_SCANCODE_LEFT])
				{
					m_ActionState = ActionState::jumpShootUpDiagonal;
				}
			}
		}
	}
}

void Avatar::InitializeSprites( )
{
	float framesPerSec{3};

	m_sprites.push_back(new Sprite{ "Resources/Luke/Idle.png", Sprite::animType::repeatBackwards, 3, 1, framesPerSec });

	framesPerSec = 10;
	m_sprites.push_back(new Sprite{ "Resources/Luke/Walk.png", Sprite::animType::loop, 8, 1, framesPerSec });

	framesPerSec = 15;
	m_sprites.push_back(new Sprite{ "Resources/Luke/Slide.png", Sprite::animType::dontRepeat, 5, 1,  framesPerSec });

	framesPerSec = 7;
	m_sprites.push_back(new Sprite{ "Resources/Luke/Jump.png", Sprite::animType::dontRepeat, 3, 1, framesPerSec });

	framesPerSec = 10;
	m_sprites.push_back(new Sprite{ "Resources/Luke/ShootRight.png", Sprite::animType::loop, 2, 1, framesPerSec });

	m_sprites.push_back(new Sprite{ "Resources/Luke/ShootDownRight.png", Sprite::animType::loop, 2, 1, framesPerSec });

	m_sprites.push_back(new Sprite{ "Resources/Luke/ShootUp.png", Sprite::animType::loop, 2, 1, framesPerSec });

	m_sprites.push_back(new Sprite{ "Resources/Luke/ShootUpRight.png", Sprite::animType::loop, 2, 1, framesPerSec });

	m_sprites.push_back(new Sprite{ "Resources/Luke/JumpShootRight.png", Sprite::animType::loop, 2, 1, framesPerSec });

	m_sprites.push_back(new Sprite{ "Resources/Luke/JumpShootDownRight.png", Sprite::animType::loop, 2, 1, framesPerSec });

	m_sprites.push_back(new Sprite{ "Resources/Luke/JumpShootUp.png", Sprite::animType::loop, 2, 1, framesPerSec });

	m_sprites.push_back(new Sprite{ "Resources/Luke/JumpShootUpRight.png", Sprite::animType::loop, 2, 1, framesPerSec });
}

void Avatar::Moving(float elapsedSec)
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
	m_Shape.width = m_sprites[int(m_ActionState)]->GetFrameWidth() / nrOfFrames;
	m_Shape.height = m_sprites[int(m_ActionState)]->GetFrameHeight();
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
		case ActionState::jumpShoot:

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
		case ActionState::jumpShootDown:

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
		case ActionState::jumpShootUp:

			bulletBottomLeftPoint.x = m_Shape.left + m_Shape.width * 0.53f;

			bulletBottomLeftPoint.y = m_Shape.bottom + m_Shape.height;

			break;

		case ActionState::shootUpDiagonal:
		case ActionState::jumpShootUpDiagonal:

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