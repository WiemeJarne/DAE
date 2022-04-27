#include "pch.h"
#include "PowerUpManager.h"
#include "PowerUp.h"
#include "utils.h"

PowerUpManager::PowerUpManager( )
	:m_pPowerups{ }
{
}

PowerUpManager::~PowerUpManager( )
{
	for (PowerUp* index : m_pPowerups)
	{
		delete index;
	}
}

void PowerUpManager::AddPowerUp(const Point2f& bottomLeftPos)
{
	m_pPowerups.push_back(new PowerUp{ bottomLeftPos });
}

void PowerUpManager::Draw( ) const
{
	for (PowerUp* index : m_pPowerups)
	{
		index->Draw( );
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

size_t PowerUpManager::GetAmountOfPowerUps( ) const
{
	return m_pPowerups.size( );
}