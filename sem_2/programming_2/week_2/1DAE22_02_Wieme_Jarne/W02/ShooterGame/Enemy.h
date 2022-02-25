#pragma once
#include "structs.h"

class Enemy
{
public:
	Enemy();
	Enemy(const Point2f& center, float width, float height);

	void Draw() const;
	void SetCenter(const Point2f& center);
	void SetDimensions(float width, float height);
	bool DoHitTest(const Rectf& other);
	bool IsDead();

private:
	Point2f m_Center;
	Rectf m_EnemyRect;
	bool m_IsDead;

	void ChangeEnemyRect(float width, float height);
};