#pragma once
#include <vector>
#include "Vector2f.h"

class Texture;
class Platform;

class Level final
{
public:
	Level( );
	
	~Level( );
	Level(const Level& level) = delete;
	Level& operator=(const Level& rhs) = delete;
	Level(const Level&& level) = delete;
	Level& operator=(const Level&& rhs) = delete;

	void DrawForeground( ) const;
	void DrawBackground(const Point2f& translation) const;
	void HandleCollision(Rectf& actorShape, Vector2f& actorVelocity) const;
	bool IsOnGround(const Rectf& actorShape, const Vector2f& actorVelocity) const;
	Rectf GetBoundaries( ) const;

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