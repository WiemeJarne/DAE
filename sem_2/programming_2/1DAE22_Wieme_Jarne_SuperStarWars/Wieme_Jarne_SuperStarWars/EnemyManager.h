#pragma once
#include <vector>

class Level;
class Avatar;
class Enemy;
class TextureManager;
class BulletManager;

class EnemyManager final
{
public:
	explicit EnemyManager( );
	EnemyManager(const EnemyManager& other) = delete;
	EnemyManager(EnemyManager&& other) = delete;
	~EnemyManager( );

	EnemyManager& operator=(const EnemyManager& rhs) = delete;
	EnemyManager& operator=(EnemyManager&& rhs) = delete;

	enum class EnemyKind
	{
		Scorpion,
		flying,
		worm,
		jumping,
		boss
	};

	void Update(float elapsecSec, const Level& level, Avatar& avatar);
	void Draw( ) const;
	void AddEnemy(const Point2f& bottomLeftStartPoint, float scale, int health, EnemyKind enemyKind, TextureManager& pTextureManager, BulletManager& BulletManager);
	std::vector<Enemy*>& GetEnemies( );

private:
	std::vector<Enemy*> m_pEnemies;

	void DeleteEnemy(int index);
};