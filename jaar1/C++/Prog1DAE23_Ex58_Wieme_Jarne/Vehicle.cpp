#include "pch.h"
#include "Vehicle.h"

Vehicle::Vehicle(int id)
	:m_MinSpeed{20}, m_MaxSpeed{200}
	,m_Position{0,0}
	,m_IsActive{false}
{
	m_Speed = float(rand() % (m_MaxSpeed + 1 - m_MinSpeed) + m_MinSpeed);
	utils::TextureFromFile("Resources/car-truck" + std::to_string(id) + ".bmp", m_Texture);
}

void Vehicle::Reset()
{
	const int minXPos{ -300 };
	const int maxXPos{};

	m_Position.x = float(rand() % (maxXPos + 1 - minXPos) + minXPos);

	m_Speed = float(rand() % (m_MaxSpeed + 1 - m_MinSpeed) + m_MinSpeed);

	m_IsActive = true;
}

Vehicle::~Vehicle()
{
	utils::DeleteTexture(m_Texture);
}

void Vehicle::Update(float elapsedSec, float windowWidth)
{
	if (m_IsActive == true)
	{
		if (m_Position.x >= windowWidth) m_Position.x = -m_Texture.width;
		else m_Position.x += m_Speed * elapsedSec;
	}
}

void Vehicle::Draw()
{
	utils::DrawTexture(m_Texture, m_Position);
}

bool Vehicle::IsIntersecting(const Point2f& pt)
{
	if (	pt.x >= m_Position.x
		 && pt.x <= m_Position.x + m_Texture.width
		 && pt.y >= m_Position.y
		 && pt.y <= m_Position.y + m_Texture.height)
	{
		return true;
	}

	return false;
}

void Vehicle::SetActive(bool isActive)
{
	m_IsActive = isActive;
}

void Vehicle::SetYPos(float posY)
{
	m_Position.y = posY;
}
