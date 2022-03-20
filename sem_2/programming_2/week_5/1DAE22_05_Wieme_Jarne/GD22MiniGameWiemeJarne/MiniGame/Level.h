#pragma once
#include <vector>
#include "utils.h"

class Texture;
class Platform;

class Level
{
public:
	Level();
	~Level();

	void DrawBackground() const;
	void DrawForeground() const;
	void HandleCollision(Rectf& actorShape, Vector2f& actorVelocity) const;
	bool IsOnGround(const Rectf& actorShape, const Vector2f& actorVelocity) const;
	Rectf GetBoundaries() const;
	bool HasReachedEnd(const Rectf& actorShape) const;

private:
	std::vector<std::vector<Point2f>> m_Vertices;
	Texture* m_pBackgroundTexture;
	Texture* m_pFenceTexture;
	Point2f m_FenceBottomLeft;
	Rectf m_Boundaries;
	Platform* m_pPlatform;
	Texture* m_pSignTexture;
	Rectf m_EndSignShape;
};