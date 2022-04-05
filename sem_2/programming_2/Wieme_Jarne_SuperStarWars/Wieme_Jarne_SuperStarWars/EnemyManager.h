#pragma once
#include <vector>

class Enemy;
class Level;

class EnemyManager final
{
public:
	explicit EnemyManager( );
	EnemyManager(const EnemyManager& other) = delete;
	EnemyManager(EnemyManager&& other) = delete;
	~EnemyManager();

	EnemyManager& operator=(const EnemyManager& rhs) = delete;
	EnemyManager& operator=(EnemyManager&& rhs) = delete;

	void Update(float elapsecSec, const Level& level);
	void Draw( ) const;
	void AddEnemy(const Point2f& bottomLeftStartPoint, float scale, int health);
	std::vector<Enemy*> GetEnemies();

private:
	std::vector<Enemy*> m_pEnemies;
	void DeleteEnemy(const int index);
};