#include "pch.h"
#include "PowerUpManager.h"
#include "PowerUp.h"
#include "utils.h"

PowerUpManager::PowerUpManager( )
	:m_pPowerups{ }
{
	InitializePowerUps( );
	
}

PowerUpManager::~PowerUpManager( )
{
	for (PowerUp* powerUp : m_pPowerups)
	{
		delete powerUp;
	}
}

void PowerUpManager::InitializePowerUps( )
{
	m_pPowerups.push_back(new PowerUp{ Point2f{2925.f, 100.f} });
}

void PowerUpManager::Draw( ) const
{
	for (PowerUp* powerUp : m_pPowerups)
	{
		powerUp->Draw( );
	}
}

bool PowerUpManager::HitItem(const Rectf& rect)
{
	const size_t size{ m_pPowerups.size( ) };

	for (int index{}; index < size; ++index)
	{
		if (m_pPowerups[index]->IsOverlapping(rect))
		{
			delete m_pPowerups[index];
			m_pPowerups[index] = m_pPowerups.back( );
			m_pPowerups.pop_back();

			return true;
		}
	}
	return false;
}

void PowerUpManager::Reset( )
{
	if (m_pPowerups.size() == 0)
	{
		InitializePowerUps( );
	}
}