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
	void DrawPitTexture(Point2f bottomLeftPoint) const;
	void DrawPitMonsterPitTexture(Point2f bottomLeftPoint) const;
	void HandleCollision(Rectf& actorShape, Vector2f& actorVelocity) const;
	bool IsOnGround(const Rectf& actorShape) const;
	Rectf GetBoundaries() const;

private:
	std::vector<std::vector<Point2f>> m_Vertices;
	Texture* m_LevelTexture;
	Texture* m_PitTexture;
	Texture* m_BossPitTexture;
	Rectf m_Boundaries;
};

