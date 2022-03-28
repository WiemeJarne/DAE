#pragma once
#include <vector>
#include "Vector2f.h"
#include "Bullet.h"

class BulletManager final
{
public:
	explicit BulletManager(const float bulletScale);
	~BulletManager();
	BulletManager& operator=(const BulletManager& rhs) = delete;
	BulletManager(const Bullet& bullet) = delete;

	void UpdateBullets(const float elapsedSec);
	void DrawBullets() const;
	void AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity);

private:
	std::vector<Bullet*> m_pBullets;
	const float m_BulletScale;

	void DeleteBullet(const int index);
};

