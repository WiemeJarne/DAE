#pragma once
#include <vector>
#include "utils.h"

class Texture;

class Level
{
public:
	Level();
	~Level();

	void DrawBackground() const;
	void HandleCollision(Rectf& actorShape, Vector2f& actorVelocity) const;
	bool IsOnGround(const Rectf& actorShape) const;
	Rectf GetBoundaries() const;

private:
	std::vector<std::vector<Point2f>> m_Vertices;
	Texture* m_LevelTexture;
	Rectf m_Boundaries;
};

