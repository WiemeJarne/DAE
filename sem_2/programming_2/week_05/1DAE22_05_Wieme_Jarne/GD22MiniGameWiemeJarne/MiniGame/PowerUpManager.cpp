#include "pch.h"
#include "PowerUpManager.h"
#include "PowerUp.h"
#include "utils.h"

PowerUpManager::PowerUpManager( )
	:m_pItems{}
	,m_PowerUpSound{ "Resources/Sounds/PowerUp.mp3" }
{

}

PowerUpManager::~PowerUpManager( )
{
	for (PowerUp* index : m_pItems)
	{
		delete index;
		index = nullptr;
	}
	m_pItems.clear();
}

PowerUp* PowerUpManager::AddItem(const Point2f& center, PowerUp::Type type)
{
	m_pItems.push_back(new PowerUp{ center, type });
	return m_pItems.back();
}

void PowerUpManager::Update(float elapsedSec)
{
	for (PowerUp* index : m_pItems)
	{
		index->Update(elapsedSec);
	}
}

void PowerUpManager::Draw( ) const
{
	for (PowerUp* index : m_pItems)
	{
		index->Draw();
	}
}

size_t PowerUpManager::Size( ) const
{
	return m_pItems.size();
}

bool PowerUpManager::HitItem(const Rectf& rect)
{
	const size_t size{ m_pItems.size() };

	for (int index{}; index < size; ++index)
	{
		if (m_pItems[index]->IsOverlapping(rect))
		{
			delete m_pItems[index];
			m_pItems[index] = m_pItems.back();
			m_pItems.pop_back();

			m_PowerUpSound.Play(0);

			return true;
		}
	}
	return false;
}