#include "pch.h"
#include "Avatar.h"
#include "Enemy.h"
#include "utils.h"
#include "Game.h"
#include <iostream>

Avatar::Avatar()
	:m_Center{ }
	,m_Speed{500.f}
	,m_BoundariesRect{ }
	,m_Bullet{ }
{
	ChangeAvatarRect(50.f, 50.f);
}

Avatar::Avatar(const Point2f& center, float width, float height)
	:Avatar()
{
	m_Center = center;
	ChangeAvatarRect(width, height);
}

void Avatar::Update(const float elapsedSec, std::vector<Enemy*> pEnemies, bool move)
{
	m_Bullet.SetBoundaries(m_BoundariesRect);
	m_Bullet.Update(elapsedSec, pEnemies);
	if(move) HandleMoveKeyState(elapsedSec);
}

void Avatar::Draw() const
{
	m_Bullet.Draw();

	const float lineWidth{ 2.f };
	Color4f yellow{ 1.f, 1.f, 0.f, 1.f };
	utils::SetColor(yellow);
	utils::DrawRect(m_AvatarRect, lineWidth);
}

void Avatar::SetCenter(const Point2f& center)
{
	m_Center = center;
}

void Avatar::SetDimensions(float width, float height)
{
	ChangeAvatarRect(width, height);
}

void Avatar::SetBoundaries(const Rectf& boundaries)
{
	m_BoundariesRect = boundaries;
}

void Avatar::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	switch (e.keysym.sym)
	{
	case SDLK_UP:
		m_Bullet.Shoot(m_Center, Vector2f{ 0, 750.f });
		break;
	}
}

void Avatar::Clamp()
{
	if (m_AvatarRect.left < m_BoundariesRect.left)
	{
		m_AvatarRect.left = m_BoundariesRect.left;
		m_Center.x = m_AvatarRect.left + m_AvatarRect.width / 2.f;
	}

	if (m_AvatarRect.left + m_AvatarRect.width > m_BoundariesRect.left + m_BoundariesRect.width)
	{
		m_AvatarRect.left = m_BoundariesRect.width - m_AvatarRect.width;
		m_Center.x = m_AvatarRect.left + m_AvatarRect.width / 2.f;
	}
}

void Avatar::HandleMoveKeyState(float elapsedSec)
{
	m_Center.x += elapsedSec * m_Speed;
	m_AvatarRect.left = m_Center.x - m_AvatarRect.width / 2.f;
	Clamp();
}

void Avatar::ChangeAvatarRect(float width, float height)
{
	m_AvatarRect.width = width;
	m_AvatarRect.height = height;
	m_AvatarRect.left = m_Center.x - m_AvatarRect.width / 2.f;
	m_AvatarRect.bottom = m_Center.y - m_AvatarRect.height / 2.f;
}