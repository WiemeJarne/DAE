#include "Grid.h"

Grid::Grid(int topLeftX, int topLeftY, int amountOfRows, int amountOfCollumns, int CellSideLength, COLORREF color)
	: m_TopLeftX{ topLeftX }
	, m_TopLeftY{ topLeftY }
	, m_AmountOfRows{ amountOfRows }
	, m_AmountOfCollumns{ amountOfCollumns }
	, m_CellSideLenght{ CellSideLength }
	, m_Color{ color }
{
	//nothing to create
}

void Grid::Paint()
{
	GAME_ENGINE->SetColor(m_Color);

	int x{ m_TopLeftX };
	int y{ m_TopLeftY };

	for (int rowNr{}; rowNr <= m_AmountOfRows; ++rowNr)
	{
		GAME_ENGINE->DrawLine(x, y, x + m_CellSideLenght * m_AmountOfCollumns, y);
		y += m_CellSideLenght;
	}

	y = m_TopLeftY;

	for (int colNr{}; colNr <= m_AmountOfCollumns; ++colNr)
	{
		GAME_ENGINE->DrawLine(x, y, x, y + m_CellSideLenght * m_AmountOfRows);
		x += m_CellSideLenght;
	}
}