#pragma once
#include <vector>

class Enemy;

class EnemyManager final
{
public:
	explicit EnemyManager( );
	EnemyManager(const EnemyManager& other) = delete;
	EnemyManager(EnemyManager&& other) = delete;
	~EnemyManager();

	EnemyManager& operator=(const EnemyManager& rhs) = delete;
	EnemyManager& operator=(EnemyManager&& rhs) = delete;

	void Update(float elapsecSec);
	void Draw( ) const;
	void AddEnemy(const Point2f& bottomLeftStartPoint, float scale);

private:
	std::vector<Enemy*> m_Enemies;
	void DeleteEnemy(const int index);
};