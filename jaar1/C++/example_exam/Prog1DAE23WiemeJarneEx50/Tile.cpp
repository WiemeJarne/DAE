#include "pch.h"		
#include "Tile.h"

Tile::Tile(const Rectf& dstRect, const std::string& textPath, int nrAnimals)
	:m_DestinationRect{dstRect}
	,m_AmountOfAnimals{nrAnimals}
	,m_TileState{false}
	,m_TileIsActive{true}
{
	utils::TextureFromFile(textPath, m_Texture);

	m_CurrentAnimal = rand() % nrAnimals;

	m_SourceRect.height = m_Texture.height;
	m_SourceRect.width = m_Texture.width / nrAnimals;
	m_SourceRect.left = m_CurrentAnimal * m_SourceRect.width;
	m_SourceRect.bottom = 128;

	m_SmallRectX = m_DestinationRect.left + 1;
	m_SmallRectY = m_DestinationRect.bottom;
	m_SmallRectWidth = m_DestinationRect.width / 4;
	m_SmallRectHeight = m_DestinationRect.height / 4;
}

Tile::~Tile()
{
	utils::DeleteTexture(m_Texture);
}

void Tile::Draw()
{
	m_SourceRect.left = m_CurrentAnimal * m_SourceRect.width;
	utils::DrawTexture(m_Texture, m_DestinationRect, m_SourceRect);

	if (m_TileState == true && m_TileIsActive == true)
	{
		utils::SetColor(128 / 255.f, 128 / 255.f, 128 / 255.f, 0.5f);
		utils::FillRect(m_DestinationRect);

		utils::SetColor(1.f, 0.f, 0.f);

		utils::DrawRect(m_SmallRectX, m_SmallRectY, m_SmallRectWidth, m_SmallRectHeight);
		utils::DrawRect(m_SmallRectX + 3 * m_SmallRectWidth - 1, m_SmallRectY, m_SmallRectWidth, m_SmallRectHeight);
	}
}

void Tile::CheckActivation(const Point2f& pos)
{
	if (	pos.x >= m_DestinationRect.left
		 && pos.x <= m_DestinationRect.left + m_DestinationRect.width
		 && pos.y >= m_DestinationRect.bottom
		 && pos.y <= m_DestinationRect.bottom + m_DestinationRect.height)
	{
		m_TileState = true;
	}
	else m_TileState = false;
}

bool Tile::CheckHit(const Point2f& pos)
{
	if (    pos.x >= m_SmallRectX
		 && pos.x <= m_SmallRectX + m_SmallRectWidth
		 && pos.y >= m_SmallRectY
		 && pos.y <= m_SmallRectY + m_SmallRectHeight
		 && m_TileIsActive == true					  )
	{
		--m_CurrentAnimal;

		if (m_CurrentAnimal == -1) m_CurrentAnimal = m_AmountOfAnimals - 1;

		return true;
	}
	else if (	pos.x >= m_SmallRectX + 3 * m_SmallRectWidth - 1
			  && pos.x <= m_SmallRectX + 3 * m_SmallRectWidth - 1 + m_SmallRectWidth
			  && pos.y >= m_SmallRectY
			  && pos.y <= m_SmallRectY + m_SmallRectHeight
			  && m_TileIsActive	== true												 )
	{
		++m_CurrentAnimal;

		if (m_CurrentAnimal == m_AmountOfAnimals) m_CurrentAnimal = 0;

		return true;
	}
	return false;
}

int Tile::GetCurrentAnimal()
{
	return m_CurrentAnimal;
}

void Tile::Deactivate()
{
	m_TileIsActive = false;
}