#pragma once
#include <vector>
#include "PowerUp.h"

class PowerUpManager final
{
public:
	PowerUpManager( );
	
	~PowerUpManager( );
	PowerUpManager(const PowerUpManager&) = delete;
	PowerUpManager& operator=(const PowerUpManager&) = delete;
	PowerUpManager(PowerUpManager&&) = delete;
	PowerUpManager& operator=(PowerUpManager&&) = delete;

	void InitializePowerUps( );
	void Update(float elapsedSec, const Level& level);
	void Draw( ) const;
	bool HitItem(const Rectf& rect, PowerUp::Type& powerUpType);
	void Reset( );
	void AddPowerUp(const Point2f& bottomLeftPos, PowerUp::Type powerUpType);

private:
	std::vector<PowerUp*> m_pPowerups;
};