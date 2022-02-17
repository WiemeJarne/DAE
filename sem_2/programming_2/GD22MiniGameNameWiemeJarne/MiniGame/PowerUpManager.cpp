#include "pch.h"
#include "PowerUpManager.h"

PowerUpManager::PowerUpManager()
	:m_pItems{}
{
	
}

PowerUpManager::~PowerUpManager()
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
	m_pItems.push_back( new PowerUp{ center, type } );
	return m_pItems.back();
}

void PowerUpManager::Draw() const
{
	for (int index{}; index < m_pItems.size(); ++index)
	{
		m_pItems[index]->Draw();
	}
}

void PowerUpManager::Update(float elapsedSec)
{
	for (int index{}; index < m_pItems.size(); ++index)
	{
		m_pItems[index]->Update(elapsedSec);
	}
}

size_t PowerUpManager::Size() const
{
	return m_pItems.size();
}

bool PowerUpManager::HitItem(const Rectf& rect)
{
	size_t vectorSize{ m_pItems.size() };
	

	for (int index{}; index < vectorSize; ++index)
	{
		if (m_pItems[index]->IsOverlapping(rect))
		{
			m_pItems[index] = m_pItems.back();
			m_pItems.pop_back();
			return true;
		}
	}
	return false;
}