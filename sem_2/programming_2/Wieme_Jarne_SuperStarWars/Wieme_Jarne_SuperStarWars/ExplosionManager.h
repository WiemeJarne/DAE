#pragma once
#include <vector>
#include "Explosion.h"

class ExplosionManager
{
public:
	explicit ExplosionManager( );
	ExplosionManager(const ExplosionManager& other) = delete;
	ExplosionManager(ExplosionManager&& other) = delete;
	~ExplosionManager( );

	ExplosionManager& operator=(const ExplosionManager& rhs) = delete;
	ExplosionManager& operator=(ExplosionManager&& rhs) = delete;

	void Update(float elapsedSec);
	void Draw( ) const;
	void AddExplosion(const Point2f& bottomLeftPos, float scale, Explosion::ExplosionType explosionType);

private:
	std::vector<Explosion*> m_pExplosions;

	void DeleteExplosion(int index);
};