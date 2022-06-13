#pragma once
#include <vector>
#include "Explosion.h"

class TextureManager;

class ExplosionManager final
{
public:
	ExplosionManager( );
	
	~ExplosionManager( );
	ExplosionManager(const ExplosionManager& other) = delete;
	ExplosionManager& operator=(const ExplosionManager& rhs) = delete;
	ExplosionManager(ExplosionManager&& other) = delete;
	ExplosionManager& operator=(ExplosionManager&& rhs) = delete;

	void Update(float elapsedSec);
	void Draw( ) const;
	void AddExplosion(const Point2f& bottomLeftPos, float scale, Explosion::ExplosionType explosionType, TextureManager& textureManager);

private:
	std::vector<Explosion*> m_pExplosions;

	void DeleteExplosion(int index);
};