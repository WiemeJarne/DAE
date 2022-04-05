#pragma once
#include <vector>
#include "utils.h"

class Texture;
class Platform;

class Level
{
public:
	Level();
	Level(const Level& level) = delete;
	Level(const Level&& level) = delete;
	~Level();
	
	Level& operator=(const Level& rhs) = delete;
	Level& operator=(const Level&& rhs) = delete;

	void DrawLevel( ) const;
	void DrawPitTexture(Point2f bottomLeftPoint) const;
	void DrawPitMonsterPitTexture(Point2f bottomLeftPoint) const;
	void HandleCollision(Rectf& actorShape, Vector2f& actorVelocity) const;
	bool IsOnGround(const Rectf& actorShape, const Vector2f& actorVelocity) const;
	void DrawBackground(const Point2f& translation) const;
	Rectf GetBoundaries() const;

private:
	std::vector<std::vector<Point2f>> m_Vertices;
	Texture* m_LevelTexture;
	Texture* m_PitTexture;
	Texture* m_BossPitTexture;
	Texture* m_BackgroundTexture;
	Rectf m_Boundaries;
	std::vector<Platform*> m_Platforms;

	void InitializePlatforms( );
};