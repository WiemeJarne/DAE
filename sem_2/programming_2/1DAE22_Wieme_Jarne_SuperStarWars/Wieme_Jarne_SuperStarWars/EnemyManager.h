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
	explicit EnemyManager(TextureManager& textureManager, BulletManager& bulletManager);
	EnemyManager(const EnemyManager& other) = delete;
	EnemyManager(EnemyManager&& other) = delete;
	~EnemyManager( );

	EnemyManager& operator=(const EnemyManager& rhs) = delete;
	EnemyManager& operator=(EnemyManager&& rhs) = delete;

	void InitializeEnemies(TextureManager& textureManager, BulletManager& bulletManager);
	void Update(float elapsecSec, const Level& level, Avatar& avatar);
	void Draw( ) const;
	std::vector<Enemy*>& GetEnemies( );

private:
	std::vector<Enemy*> m_pEnemies;

	void DeleteEnemy(int index);
};