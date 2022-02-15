#pragma once
#include <vector>
#include "structs.h"
#include "utils.h"

class Texture;

class Level
{
public:
	Level();

	void DrawBackground() const;
	void DrawForeground() const;
	void HandleCollision(Rectf& actorShape, Vector2f& actorVelocity);
	bool IsOnGround(const Rectf& actorShape);

private:
	std::vector<Point2f> m_Vertices;
	Texture* m_pBackgroundTexture;
	Texture* m_pFenceTexture;
	Point2f m_FenceBottomLeft;
};

