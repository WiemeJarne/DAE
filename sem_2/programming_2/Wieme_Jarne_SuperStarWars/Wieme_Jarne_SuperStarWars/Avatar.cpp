#include "pch.h"
#include "Avatar.h"
#include "Level.h"
#include "Enemy.h"
#include "BulletManager.h"
#include "Sprite.h"

Avatar::Avatar()
	: m_ActionState{ActionState::idle}
	, m_Shape{ }
	, m_HorizontalSpeed{ 150.f }
	, m_JumpSpeed{ 400.f }
	, m_Velocity{ 0.f, 0.f }
	, m_Acceleration{ 0.f, -981.f }
	, m_FacingDirection{1}
	, m_pBulletManager{ new BulletManager(0.65f) }
	, m_ShootDelay{ }
	, m_BulletVelocity{ 300.f }
	, m_StartHealth{ 20 }
	, m_AccuHitSec{ }
	, m_BlasterPowerUpHit{ }
{
	m_Health = m_StartHealth;
	InitializeSprites( );
	ChangeShapeDimensions(m_sprites[int(m_ActionState)]->GetAmountOfFrames());
}

Avatar::~Avatar( )
{
	for (Sprite* sprite : m_sprites)
	{
		delete sprite;
	}

	delete m_pBulletManager;
}

void Avatar::Update(float elapsedSec, const Level& level, std::vector<Enemy*> enemies)
{
	UpdateYPos(elapsedSec);

	m_AccuHitSec += elapsedSec;

	m_ShootDelay += elapsedSec;

	m_pBulletManager->HandleCollisionWithEnemies(enemies);

	HandleCollision(enemies);

	ChangeShapeDimensions(m_sprites[int(m_ActionState)]->GetAmountOfFrames( ));

	m_pBulletManager->Update(elapsedSec, level);

	m_sprites[int(m_ActionState)]->Update(elapsedSec);

	if (m_AccuHitSec >= 0.1f)
	{
		HandleInput(level);
	}

	if (m_Health == 0)
	{
		if (m_ActionState != ActionState::dead)
		{
			m_sprites[int(ActionState::dead)]->SetFrameNr(0);
			m_sprites[int(ActionState::dead)]->SetAccuSec(0.f);
		}

		m_ActionState = ActionState::dead;
		m_Velocity.x = 0.f;
	}

	switch (m_ActionState)
	{
	case ActionState::walking:
	case ActionState::sliding:
	case ActionState::jumping:
		UpdateXPos(elapsedSec);
		break;

	case ActionState::shoot:
		Shoot(Vector2f{m_BulletVelocity * m_FacingDirection, 0.f});
		break;

	case ActionState::shootDown:
		Shoot(Vector2f{ m_BulletVelocity * m_FacingDirection * 0.5f, -m_BulletVelocity * 0.5f });
		break;

	case ActionState::shootUp:
		Shoot(Vector2f{ 0.f, m_BulletVelocity });
		break;

	case ActionState::shootUpDiagonal:
		Shoot(Vector2f{ m_BulletVelocity * m_FacingDirection * 0.5f, m_BulletVelocity * 0.5f });
		break;

	case ActionState::jumpShoot:
		UpdateXPos(elapsedSec);
		Shoot(Vector2f{ m_BulletVelocity * m_FacingDirection, 0.f });
		break;

	case ActionState::jumpShootDown:
		UpdateXPos(elapsedSec);
		Shoot(Vector2f{ m_BulletVelocity * m_FacingDirection * 0.5f, -m_BulletVelocity * 0.5f });
		break;

	case ActionState::jumpShootUp:
		UpdateXPos(elapsedSec);
		Shoot(Vector2f{ 0.f, m_BulletVelocity });
		break;

	case ActionState::jumpShootUpDiagonal:
		UpdateXPos(elapsedSec);
		Shoot(Vector2f{ m_BulletVelocity * m_FacingDirection * 0.5f, m_BulletVelocity * 0.5f });
		break;
	}
	
	level.HandleCollision(m_Shape, m_Velocity);

	StayInLevelBoundaries(level);
}

void Avatar::Draw( ) const
{
	glPushMatrix( );

		m_pBulletManager->Draw();

		glTranslatef(m_Shape.left, m_Shape.bottom, 0.f);

		glScalef(GLfloat(m_FacingDirection), 1, 1);

		if (m_FacingDirection == -1)
		{
			glTranslatef(-m_Shape.width, 0.f, 0.f);
		}

		DrawAvatar();

	glPopMatrix();
}

void Avatar::Hit( )
{
	if (m_Health > 0 && m_AccuHitSec > .5f)
	{
		m_AccuHitSec = 0.f;
		--m_Health;
		m_ActionState = ActionState::hit;
	}
}

void Avatar::PowerupHit( )
{
	m_BlasterPowerUpHit = true;
}

Rectf Avatar::GetShape( ) const
{
	return m_Shape;
}

void Avatar::InitializeSprites( )
{
	float framesPerSec{ 3 };

	m_sprites.push_back(new Sprite{ "Resources/Luke/Idle.png", Sprite::AnimType::repeatBackwards, 3, 1, framesPerSec });

	framesPerSec = 10.f;
	m_sprites.push_back(new Sprite{ "Resources/Luke/Walk.png", Sprite::AnimType::loop, 8, 1, framesPerSec });

	framesPerSec = 15.f;
	m_sprites.push_back(new Sprite{ "Resources/Luke/Slide.png", Sprite::AnimType::dontRepeat, 5, 1,  framesPerSec });

	framesPerSec = 7.f;
	m_sprites.push_back(new Sprite{ "Resources/Luke/Jump.png", Sprite::AnimType::dontRepeat, 3, 1, framesPerSec });

	framesPerSec = 10.f;
	m_sprites.push_back(new Sprite{ "Resources/Luke/ShootRight.png", Sprite::AnimType::loop, 2, 1, framesPerSec });

	m_sprites.push_back(new Sprite{ "Resources/Luke/ShootDownRight.png", Sprite::AnimType::loop, 2, 1, framesPerSec });

	m_sprites.push_back(new Sprite{ "Resources/Luke/ShootUp.png", Sprite::AnimType::loop, 2, 1, framesPerSec });

	m_sprites.push_back(new Sprite{ "Resources/Luke/ShootUpRight.png", Sprite::AnimType::loop, 2, 1, framesPerSec });

	m_sprites.push_back(new Sprite{ "Resources/Luke/JumpShootRight.png", Sprite::AnimType::loop, 2, 1, framesPerSec });

	m_sprites.push_back(new Sprite{ "Resources/Luke/JumpShootDownRight.png", Sprite::AnimType::loop, 2, 1, framesPerSec });

	m_sprites.push_back(new Sprite{ "Resources/Luke/JumpShootUp.png", Sprite::AnimType::loop, 2, 1, framesPerSec });

	m_sprites.push_back(new Sprite{ "Resources/Luke/JumpShootUpRight.png", Sprite::AnimType::loop, 2, 1, framesPerSec });

	framesPerSec = 1.f;
	m_sprites.push_back(new Sprite{ "Resources/Luke/Hit.png", Sprite::AnimType::loop, 1, 1, framesPerSec });

	framesPerSec = 3.f;
	m_sprites.push_back(new Sprite{ "Resources/Luke/Die.png", Sprite::AnimType::dontRepeat, 2, 1, framesPerSec });
}

void Avatar::UpdateXPos(float elapsedSec)
{
	m_Shape.left += elapsedSec * m_Velocity.x;
}

void Avatar::UpdateYPos(float elapsedSec)
{
	m_Shape.bottom += elapsedSec * m_Velocity.y;
	m_Velocity.y += m_Acceleration.y * elapsedSec;
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

void Avatar::HandleInput(const Level& level)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	SDL_Scancode reset{ SDL_Scancode::SDL_SCANCODE_R };

	if (pStates[reset])
	{
		m_Health = m_StartHealth;
		m_Shape.left = 0.f;
		m_ActionState = ActionState::idle;
	}

	if (m_Health > 0)
	{
		SDL_Scancode left{ SDL_Scancode::SDL_SCANCODE_A };
		SDL_Scancode right{ SDL_Scancode::SDL_SCANCODE_D };
		SDL_Scancode up{ SDL_Scancode::SDL_SCANCODE_W };
		SDL_Scancode down{ SDL_Scancode::SDL_SCANCODE_S };
		SDL_Scancode jump{ SDL_Scancode::SDL_SCANCODE_SPACE };
		SDL_Scancode shoot{ SDL_Scancode::SDL_SCANCODE_LSHIFT };

		if (pStates[left])
		{
			m_FacingDirection = -1;
		}

		if (pStates[right])
		{
			m_FacingDirection = 1;
		}

		if (level.IsOnGround(m_Shape, m_Velocity))
		{
			if (pStates[left] && m_ActionState != ActionState::sliding)
			{
				m_Velocity.x = m_HorizontalSpeed * m_FacingDirection;
				m_ActionState = ActionState::walking;
			}

			if (pStates[right] && m_ActionState != ActionState::sliding)
			{
				m_Velocity.x = m_HorizontalSpeed * m_FacingDirection;
				m_ActionState = ActionState::walking;
			}

			if (pStates[down])
			{
				if (m_ActionState != ActionState::sliding)
				{
					m_sprites[int(ActionState::sliding)]->SetFrameNr(0);
					m_sprites[int(ActionState::sliding)]->SetAccuSec(0.f);
				}

				const int speedMultiplier{ 2 };

				m_Velocity.x = m_HorizontalSpeed * m_FacingDirection * speedMultiplier;

				m_ActionState = ActionState::sliding;
			}

			if (pStates[jump] && m_ActionState != ActionState::sliding)
			{
				m_sprites[int(ActionState::jumping)]->SetFrameNr(0);
				m_sprites[int(ActionState::jumping)]->SetAccuSec(0.f);

				m_Velocity.y = m_JumpSpeed;

				m_ActionState = ActionState::jumping;
			}

			if (pStates[shoot])
			{
				m_ActionState = ActionState::shoot;

				if (pStates[down])
				{
					m_ActionState = ActionState::shootDown;
				}

				if (pStates[up])
				{
					m_ActionState = ActionState::shootUp;

					if (pStates[left])
					{
						m_ActionState = ActionState::shootUpDiagonal;
					}

					if (pStates[right])
					{
						m_ActionState = ActionState::shootUpDiagonal;
					}

				}
			}

			if (!pStates[left]
				&& !pStates[right]
				&& !pStates[down]
				&& !pStates[jump]
				&& !pStates[shoot]
				&& m_Health != 0)
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
		else
		{
			if (pStates[shoot])
			{
				m_ActionState = ActionState::jumpShoot;

				if (pStates[down])
				{
					m_ActionState = ActionState::jumpShootDown;
				}

				if (pStates[up])
				{
					m_ActionState = ActionState::jumpShootUp;

					if (pStates[left])
					{
						m_ActionState = ActionState::jumpShootUpDiagonal;
					}

					if (pStates[right])
					{
						m_ActionState = ActionState::jumpShootUpDiagonal;
					}
				}
			}
		}
	}
}

void Avatar::DrawAvatar( ) const
{
	m_sprites[int(m_ActionState)]->Draw( );
}

void Avatar::Shoot(const Vector2f& bulletVelocity)
{
	if (m_ShootDelay > 0.1f)
	{
		m_ShootDelay = 0;

		m_pBulletManager->AddBullet( DetermineBulletPos( ), bulletVelocity, m_BlasterPowerUpHit );
	}
}

Point2f Avatar::DetermineBulletPos( ) const
{
	Point2f bulletBottomLeftPoint{};

	switch (m_ActionState)
	{
	case ActionState::shoot:
	case ActionState::jumpShoot:

		bulletBottomLeftPoint.y = m_Shape.bottom + m_Shape.height * 0.77f;

		if (m_FacingDirection == 1)
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

		if (m_FacingDirection == 1)
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

		if (m_FacingDirection == 1)
		{
			bulletBottomLeftPoint.x = m_Shape.left + m_Shape.width * 0.95f;
		}
		else
		{
			bulletBottomLeftPoint.x = m_Shape.left + m_Shape.width * 0.05f;
		}

		break;
	}

	return bulletBottomLeftPoint;
}

void Avatar::HandleCollision(std::vector<Enemy*> enemies)
{
	for (Enemy* enemy : enemies)
	{
		if (utils::IsOverlapping(enemy->GetShape(), m_Shape) && enemy->GetHeath( ) > 0)
		{
			Hit( );
		}
	}
}