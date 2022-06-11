#pragma once
#include <vector>

class PowerUp;

class PowerUpManager final
{
public:
	explicit PowerUpManager( );
	PowerUpManager(const PowerUpManager&) = delete;
	PowerUpManager(PowerUpManager&&) = delete;
	~PowerUpManager( );

	PowerUpManager& operator=(const PowerUpManager&) = delete;
	PowerUpManager& operator=(PowerUpManager&&) = delete;

	void InitializePowerUps( );
	void Draw( ) const;
	bool HitItem(const Rectf& rect);
	void Reset( );

private:
	std::vector<PowerUp*> m_pPowerups;
};
