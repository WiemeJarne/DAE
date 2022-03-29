#pragma once
#include "Vector2f.h"

class Texture;

class Platform final
{
public:
	explicit Platform(const Point2f& bottomLeftPoint);
	Platform(const Platform& platform) = delete;
	Platform& operator=(const Platform& rhs) = delete;
	Platform(const Platform&& platform) = delete;
	Platform& operator=(const Platform&& rhs) = delete;
	~Platform();

	void Draw() const;
	void HandleCollision(Rectf& actorShape, Vector2f& actorVelocity) const;
	bool IsOnGround(const Rectf& actorShape, const Vector2f& actorVelocity) const;

private:
	Rectf m_Shape;
	Texture* m_pTexture;
};

