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

	void AddPowerUp(const Point2f& bottomLeftPos);
	void Draw( ) const;

	bool HitItem(const Rectf& rect);

private:
	std::vector<PowerUp*> m_pPowerups;
};
