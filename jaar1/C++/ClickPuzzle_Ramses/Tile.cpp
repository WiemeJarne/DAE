#include "pch.h"		
#include "Tile.h"
#include "utils.h"
#include <iostream>

using namespace utils;

Tile::Tile(const Rectf& dstRect, const std::string& textPath, int nrAnimals)

	: m_DstCurrentAnimal{ dstRect }
	, m_NrOfColumns{ nrAnimals }
	, m_IndexCurrentAnimal{}
	, m_TileSize{ 128 }
	, m_LeftHitRegion {}
	, m_RightHitRegion{}
	, m_IsActivated{ false }
		
{
	m_HitRegionWidth = m_DstCurrentAnimal.width / 4;
	m_HitRegionHeight = m_DstCurrentAnimal.width / 4 ;
	TextureFromFile(textPath, m_TileTexture);

	//array voor opslaan van de dieren

	m_pSrcAnimals = new Rectf[m_NrOfColumns]{};

	for (int index{}; index < m_NrOfColumns; index++)
	{
		m_pSrcAnimals[index].width = m_TileSize;
		m_pSrcAnimals[index].height = m_TileSize;
		m_pSrcAnimals[index].left = index * m_pSrcAnimals[index].width;
		m_pSrcAnimals[index].bottom = m_pSrcAnimals[index].height;
	}

	std::cout << "Animal sources loaded...\n";

	Randomize();

	std::cout << "Animal Randomized...\n" <<std::endl;

	// HitRegions initialiseren

	m_LeftHitRegion.left = m_DstCurrentAnimal.left;
	m_LeftHitRegion.bottom = m_DstCurrentAnimal.bottom;
	m_LeftHitRegion.width = m_HitRegionWidth;
	m_LeftHitRegion.height = m_HitRegionHeight;

	m_RightHitRegion = m_LeftHitRegion;
	m_RightHitRegion.left = m_DstCurrentAnimal.left + m_DstCurrentAnimal.width - m_HitRegionWidth;

}

Tile::~Tile()
{

}

void Tile::Draw()
{
	
	DrawTexture(m_TileTexture, m_DstCurrentAnimal, m_SrcCurrentAnimal);

	if (m_IsActivated)
	{
		SetColor(0.6f, 0.6f, 0.6f, 0.7f);
		FillRect(m_DstCurrentAnimal);

		SetColor(1, 0, 0, 1);
		DrawRect(m_LeftHitRegion);
		DrawRect(m_RightHitRegion);
	}
		
		

}

void Tile::CheckActivation(const Point2f& pos)
{
	m_IsActivated = (utils::IsPointInRectangle(m_DstCurrentAnimal, pos)) ? true : false;
}

bool Tile::CheckHit(const Point2f& pos)
{
	
	//std::cout << m_RightHitRegion.bottom << '\n';

	if (pos.x >= m_LeftHitRegion.left
		&& pos.x <= m_LeftHitRegion.left + m_LeftHitRegion.width
		&& pos.y >= m_LeftHitRegion.bottom
		&& pos.y <= m_LeftHitRegion.bottom + m_LeftHitRegion.height)
	{
		m_SrcCurrentAnimal = m_pSrcAnimals[--m_IndexCurrentAnimal];

		if (GetCurrentAnimal() == 0) m_SrcCurrentAnimal = m_pSrcAnimals[5];

		return true;
	}
	
	if (pos.x >= m_RightHitRegion.left
		&& pos.x <= m_RightHitRegion.left + m_RightHitRegion.width
		&& pos.y >= m_RightHitRegion.bottom
		&& pos.y <= m_RightHitRegion.bottom + m_RightHitRegion.height)
	{
		m_SrcCurrentAnimal = m_pSrcAnimals[++m_IndexCurrentAnimal];

		if (GetCurrentAnimal() == 5) m_SrcCurrentAnimal = m_pSrcAnimals[0];

		return true;
	}

	return false;
}

int Tile::GetCurrentAnimal()
{
	return m_IndexCurrentAnimal;
}

void Tile::Deactivate()
{

}

void Tile::Randomize()
{
	int amountAnimals{ m_NrOfColumns - 1 };
	m_IndexCurrentAnimal = int(utils::GetRandomNr(0, amountAnimals));

	m_SrcCurrentAnimal = m_pSrcAnimals[m_IndexCurrentAnimal];
	std::cout << "index CurrentAnimal: " << m_IndexCurrentAnimal << std::endl;

}