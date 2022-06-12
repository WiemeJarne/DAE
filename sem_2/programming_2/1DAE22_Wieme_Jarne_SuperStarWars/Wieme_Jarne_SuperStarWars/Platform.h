#pragma once
#include "Vector2f.h"

class Platform final
{
public:
	explicit Platform(const Point2f& beginPoint, const float width);

	Platform(const Platform& other) = delete;
	Platform& operator=(const Platform& rhs) = delete;
	Platform(Platform&& other) = delete;
	Platform& operator=(Platform&& rhs) = delete;

	void HandleCollision(Rectf& actorShape, Vector2f& actorVelocity) const;
	bool IsOnGround(const Rectf& actorShape, const Vector2f& actorVelocity) const;

private:
	Rectf m_Shape;
};