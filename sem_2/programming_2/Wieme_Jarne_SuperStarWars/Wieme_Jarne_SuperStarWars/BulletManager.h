#pragma once
#include <vector>
#include "Vector2f.h"
#include "Bullet.h"

class BulletManager final
{
public:
	explicit BulletManager(const float bulletScale);
	BulletManager(const Bullet& bullet) = delete;
	BulletManager(Bullet&& bullet) = delete;
	~BulletManager();

	BulletManager& operator=(const BulletManager& rhs) = delete;
	BulletManager& operator=(BulletManager&& rhs) = delete;

	void UpdateBullets(const float elapsedSec);
	void DrawBullets() const;
	void AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity);

private:
	std::vector<Bullet*> m_pBullets;
	const float m_BulletScale;

	void DeleteBullet(const int index);
};

