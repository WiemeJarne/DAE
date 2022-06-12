#include "pch.h"
#include "PowerUpManager.h"
#include "PowerUp.h"

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
	m_pPowerups.push_back(new PowerUp{ Point2f{2925.f, 100.f}, PowerUp::Type::blaster });
}

void PowerUpManager::Update(float elapsedSec, const Level& level)
{
	for (PowerUp* powerUp : m_pPowerups)
	{
		powerUp->Update(elapsedSec, level);
	}
}

void PowerUpManager::Draw( ) const
{
	for (PowerUp* powerUp : m_pPowerups)
	{
		powerUp->Draw( );
	}
}

bool PowerUpManager::HitItem(const Rectf& rect, PowerUp::Type& powerUpType)
{
	const size_t size{ m_pPowerups.size( ) };

	for (int index{}; index < size; ++index)
	{
		if (m_pPowerups[index]->IsOverlapping(rect))
		{
			powerUpType = m_pPowerups[index]->GetPowerUpType();
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
	for (PowerUp* powerUp : m_pPowerups)
	{
		delete powerUp;
		powerUp = nullptr;
	}

	m_pPowerups.clear();
	
	InitializePowerUps( );
}

void PowerUpManager::AddPowerUp(const Point2f& bottomLeftPos, PowerUp::Type powerUpType)
{
	m_pPowerups.push_back(new PowerUp{ bottomLeftPos, powerUpType });
}