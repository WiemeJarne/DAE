#pragma once
#include <vector>
#include "PowerUp.h"

class PowerUpManager final
{
public:
	explicit PowerUpManager( );
	PowerUpManager(const PowerUpManager&) = delete;
	PowerUpManager(PowerUpManager&&) = delete;
	~PowerUpManager( );

	PowerUpManager& operator=(const PowerUpManager&) = delete;
	PowerUpManager& operator=(PowerUpManager&&) = delete;

	void AddItem(const Point2f& bottomLeftPos);
	void Draw( ) const;

	size_t Size( ) const;
	bool HitItem(const Rectf& rect);

private:
	std::vector<PowerUp*> m_pPowerups;
};
