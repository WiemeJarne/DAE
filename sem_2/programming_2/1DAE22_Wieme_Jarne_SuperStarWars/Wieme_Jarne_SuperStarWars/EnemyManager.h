#pragma once
#include <vector>

class TextureManager;
class BulletManager;
class Level;
class Avatar;
class PitMonster;
class Enemy;

class EnemyManager final
{
public:
	explicit EnemyManager(TextureManager& textureManager, BulletManager& bulletManager);
	
	~EnemyManager( );
	EnemyManager(const EnemyManager& other) = delete;
	EnemyManager& operator=(const EnemyManager& rhs) = delete;
	EnemyManager(EnemyManager&& other) = delete;
	EnemyManager& operator=(EnemyManager&& rhs) = delete;

	void InitializeEnemies(TextureManager& textureManager, BulletManager& bulletManager);
	void Update(float elapsecSec, const Level& level, const Avatar& avatar);
	void Draw( ) const;
	std::vector<Enemy*>& GetEnemies( );
	const PitMonster* GetPitMonster( ) const;

private:
	std::vector<Enemy*> m_pEnemies;

	void DeleteEnemy(int index);
};