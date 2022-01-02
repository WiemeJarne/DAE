#include "pch.h"
#include "Grid.h"
#include <iostream>

Grid::Grid(const int windowWidth, const int windowHeight)
	:m_AmountOfNumberTextures{9}
{
	CreateTextures();

	AskUserInput(windowWidth, windowHeight);

	m_DynArrGrid = new Texture[m_SizeDynnArr]{};
	InitDynArrGrid();

	m_DynArrMineGrid = new int[m_SizeDynnArr]{};
	InitDynnArrMineGrid();

	m_DynArrMineLocations = new int[m_SizeDynnArr]{};
	GenerateRandomNumber();
}

Grid::~Grid()
{
	utils::DeleteTexture(m_DefaultTileTexture);
	utils::DeleteTexture(m_FlagTexture);
	utils::DeleteTexture(m_MineTexture);

	for (int index{}; index < m_AmountOfNumberTextures; ++index)
	{
		utils::DeleteTexture(m_DynArrNumberTextures[index]);
	}
	delete[] m_DynArrNumberTextures;
	m_DynArrNumberTextures = nullptr;

	for (int index{}; index < m_SizeDynnArr; ++index)
	{
		utils::DeleteTexture(m_DynArrGrid[index]);
	}
	delete[] m_DynArrGrid;
	m_DynArrGrid = nullptr;

	delete[] m_DynArrMineGrid;
	m_DynArrMineGrid = nullptr;

	delete[] m_DynArrMineLocations;
	m_DynArrMineLocations = nullptr;
}

void Grid::AskUserInput(const int windowWidth, const int windowHeight)
{
	std::cout << "How many pixels do you want the side lenght of 1 tile to have?(minimum 10) ";
	std::cin >> m_TileSideLenght;

	m_ScaleFactor = m_TileSideLenght / m_DefaultTileTexture.height;
	int maxAmountOfRowsAndColumns = int(windowWidth / windowHeight);

	std::cout << "\nHow large do you want the field to be?(maximum " << maxAmountOfRowsAndColumns << ") ";
	std::cin >> m_AmountOfRows;

	m_AmountOfColumns = m_AmountOfRows;
	m_SizeDynnArr = m_AmountOfRows * m_AmountOfColumns;

	std::cout << "\nHow many mines do you want on the field? ";
	std::cin >> m_AmountOfMines;
}

void Grid::CreateTextures()
{
	utils::TextureFromFile("Resources/default.png", m_DefaultTileTexture);
	utils::TextureFromFile("Resources/flag.png", m_FlagTexture);
	utils::TextureFromFile("Resources/mine.png", m_MineTexture);

	CreateNumberTextures();
}

void Grid::InitDynArrGrid()
{
	for (int index{}; index < m_SizeDynnArr; ++index)
	{
		m_DynArrGrid[index] = m_DefaultTileTexture;
	}
}

void Grid::InitDynnArrMineGrid()
{
	for (int index{}; index < m_SizeDynnArr; ++index)
	{
		m_DynArrMineGrid[index] = -1;
	}
}

void Grid::CreateNumberTextures()
{
	for (int index{}; index < m_AmountOfNumberTextures; ++index)
	{
		utils::TextureFromFile("Resources/" + std::to_string(index) + ".png", m_DynArrNumberTextures[index]);
	}
}

void Grid::RandomMinePosGenerator()
{
	const int topBoundary{ m_SizeDynnArr };

	for (int mineNumber{}; mineNumber < m_AmountOfMines; ++mineNumber)
	{
		int randomLocation{ GenerateRandomNumber() };

		m_DynArrMineGrid[mineNumber] = randomLocation;

		for (int index{}; index < mineNumber; ++index)
		{
			if (randomLocation == m_DynArrMineGrid[index])
			{
				randomLocation = GenerateRandomNumber();
			}
		}
		m_DynArrMineGrid[randomLocation] = m_MineTexture;
	}

	for (int index{}; index < topBoundary; ++index)
	{
		if (m_DynArrMineGrid[index].id != m_MineTexture.id)
		{
			m_DynArrMineGrid[index] = m_DynArrNumberTextures[CheckAdjacentTiles(index)];
		}
	}
}

int Grid::GenerateRandomNumber()
{
	const int topBoundary{ m_SizeDynnArr };

	int randomNumber{ rand() % topBoundary };

	if (m_DynArrGrid[randomNumber].id == m_MineTexture.id)
	{
		GenerateRandomNumber();
	}
	return randomNumber;
}