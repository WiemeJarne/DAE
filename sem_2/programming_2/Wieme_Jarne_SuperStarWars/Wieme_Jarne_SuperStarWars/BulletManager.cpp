#include "pch.h"
#include "BulletManager.h"
#include "Bullet.h"
#include <iostream>

BulletManager::BulletManager(const float bulletScale)
	:m_pBullets{}
	,m_BulletScale{bulletScale}
{
	//no code
}

BulletManager::~BulletManager()
{
	int index{};

	for (Bullet* bullet : m_pBullets)
	{
		if (bullet != nullptr)
		{
			DeleteBullet(index);
		}

		++index;
	}

	m_pBullets.clear();
}

void BulletManager::UpdateBullets(const float elapsedSec)
{
	int index{};

	for (Bullet* bullet : m_pBullets)
	{
		if (bullet != nullptr)
		{
			bullet->Update(elapsedSec);

			if (bullet->IsBulletOutOfBoundaries())
			{
				DeleteBullet(index);
			}
		}

		++index;
	}
}

void BulletManager::DrawBullets() const
{
	for (Bullet* bullet : m_pBullets)
	{
		if (bullet != nullptr)
		{
			bullet->Draw();
		}
	}
}

void BulletManager::DeleteBullet(const int index)
{
	delete m_pBullets[index];
	m_pBullets[index] = nullptr;

	m_pBullets[index] = m_pBullets.back();
	m_pBullets.pop_back();	
}

void BulletManager::AddBullet(const Rectf& avatarShape, const Vector2f& bulletVelocity, const Point2f& bulletBottomLeftPoint, const Bullet::BulletState& bulletState, const int avatarFacingDirection)
{
	m_pBullets.push_back(new Bullet{ avatarShape, bulletVelocity, bulletState, avatarFacingDirection, m_BulletScale });
}