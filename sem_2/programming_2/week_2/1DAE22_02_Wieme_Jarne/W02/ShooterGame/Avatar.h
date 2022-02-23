#pragma once
#include "structs.h"
#include <vector>

class Enemy;

class Avatar
{
public:
	Avatar();
	Avatar(const Point2f& center, float width, float height);

	void Update(float elapsedSec, std::vector<Enemy*> pEnemies, int amountOfEnemies);
	void Draw() const;
	void SetCenter(const Point2f& center);
	void SetDimensions(float width, float height);
	void SetBoundaries(const Rectf& boundaries);

private:
	Point2f m_Center;
	Rectf m_AvatarRect;
	Rectf m_BoundariesRect;
	float m_Speed;
	
	void Clamp();
	void HandleMoveKeyState(float elapsedSec);
};