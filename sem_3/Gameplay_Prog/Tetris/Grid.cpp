#include "Grid.h"

Grid::Grid(int topLeftX, int topLeftY, int amountOfRows, int amountOfCollumns, int cellSideLength, COLORREF color)
	: m_TopLeftX{ topLeftX }
	, m_TopLeftY{ topLeftY }
	, m_AmountOfRows{ amountOfRows }
	, m_AmountOfCollumns{ amountOfCollumns }
	, m_CellSideLenght{ cellSideLength }
	, m_Color{ color }
	, m_DropSpeed{ 0.5f }
	, m_AmountOfSecSinceLastCellDrop{ }
	, m_MoveSpeed{ 0.1f }
	, m_AmountOfSecSinceLastMove{ }
	, m_RotateSpeed{ 0.2f }
	, m_AmountOfSecSinceLastRotate{ }
	, m_CurrentDroppingTetrimino{ Tetrimino(0, 0, cellSideLength) }
{
	for (int index{}; index < m_AmountOfRows * m_AmountOfCollumns; ++index)
	{
		m_Cells.push_back(Cell());
	}
}

void Grid::Update(float elapsedSec)
{
	//m_AmountOfSecSinceLastCellDrop += elapsedSec;
	m_AmountOfSecSinceLastMove += elapsedSec;
	m_AmountOfSecSinceLastRotate += elapsedSec;

	if (m_CurrentDroppingTetrimino.rowNr != 0 && CollisionTest())
	{
		for (int rowIndex{}; rowIndex < 4; ++rowIndex)
		{
			for (int colIndex{}; colIndex < 4; ++colIndex)
			{
				if (m_CurrentDroppingTetrimino.data[rowIndex][colIndex] == 1.f)
				{
					m_Cells[(m_CurrentDroppingTetrimino.rowNr + rowIndex) * m_AmountOfCollumns + m_CurrentDroppingTetrimino.colNr + colIndex].isColored = true;
					m_Cells[(m_CurrentDroppingTetrimino.rowNr + rowIndex) * m_AmountOfCollumns + m_CurrentDroppingTetrimino.colNr + colIndex].color = RGB(120, 120, 120);
				}
			}
		}

		m_CurrentDroppingTetrimino = Tetrimino(0, 0, m_CellSideLenght);
	}
	else if (m_AmountOfSecSinceLastCellDrop >= m_DropSpeed)
	{
		m_AmountOfSecSinceLastCellDrop = 0;
		++m_CurrentDroppingTetrimino.rowNr;
	}
}

void Grid::Paint() const
{
	// Paint the current dropping tetrimino
	// calculate the position of the current dropping tetrimino
	int x{ m_TopLeftX + m_CurrentDroppingTetrimino.colNr * m_CellSideLenght };
	int y{ m_TopLeftY + m_CurrentDroppingTetrimino.rowNr * m_CellSideLenght };

	m_CurrentDroppingTetrimino.Paint(x, y);

	// Paint the cells
	for (int index{}; index < m_Cells.size(); ++index)
	{
		if (m_Cells[index].isColored)
		{
			// calculate the location of the cell
			const int x{ m_TopLeftX + index % m_AmountOfCollumns * m_CellSideLenght };
			const int y{ m_TopLeftY + index / m_AmountOfCollumns * m_CellSideLenght };

			m_Cells[index].Paint(x, y, m_CellSideLenght);
		}
	}

	// Paint the gird
	GAME_ENGINE->SetColor(m_Color);

	x = m_TopLeftX;
	y = m_TopLeftY;

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

void Grid::MoveCurrentDroppingTetriminoLeft()
{
	for (int rowIndex{}; rowIndex < 4; ++rowIndex)
	{
		for (int colIndex{}; colIndex < 4; ++colIndex)
		{
			if (m_CurrentDroppingTetrimino.colNr + colIndex == 0
				&& m_CurrentDroppingTetrimino.data[rowIndex][colIndex] == 1.f)
				return;
		}
	}

	if (m_AmountOfSecSinceLastMove < m_MoveSpeed) return;
	m_AmountOfSecSinceLastMove = 0;

	--m_CurrentDroppingTetrimino.colNr;
}

void Grid::MoveCurrentDroppingTetriminoRight()
{
	for (int rowIndex{}; rowIndex < 4; ++rowIndex)
	{
		for (int colIndex{}; colIndex < 4; ++colIndex)
		{
			if (m_CurrentDroppingTetrimino.colNr + colIndex == m_AmountOfCollumns - 1
				&& m_CurrentDroppingTetrimino.data[rowIndex][colIndex] == 1.f)
				return;
		}
	}

	if (m_AmountOfSecSinceLastMove < m_MoveSpeed) return;
	m_AmountOfSecSinceLastMove = 0;

	++m_CurrentDroppingTetrimino.colNr;
}

void Grid::RotateCurrentDroppingTetriminoCCW()
{
	if (m_AmountOfSecSinceLastRotate < m_RotateSpeed) return;
	m_AmountOfSecSinceLastRotate = 0;

	m_CurrentDroppingTetrimino.RotateCCW();
}

void Grid::RotateCurrentDroppingTetriminoCW()
{
	if (m_AmountOfSecSinceLastRotate < m_RotateSpeed) return;
	m_AmountOfSecSinceLastRotate = 0;

	m_CurrentDroppingTetrimino.RotateCW();
}

bool Grid::CollisionTest()
{
	// calcute the rowNr and colNr for all cells that need to be checked
	std::vector<std::pair<int, int>> cellsToCheck{};

	for (int rowIndex{}; rowIndex < 4; ++rowIndex)
	{
		for (int colIndex{}; colIndex < 4; ++colIndex)
		{
			if (m_CurrentDroppingTetrimino.data[rowIndex][colIndex] == 0.f)
			{
				cellsToCheck.push_back(std::pair(m_CurrentDroppingTetrimino.rowNr + rowIndex, m_CurrentDroppingTetrimino.colNr + colIndex));
			}
		}
	}

	for (const auto& cell : cellsToCheck)
	{
		if (cell.first == (m_AmountOfRows) || cell.second == (m_AmountOfCollumns)) return true;

		const int cellIndex{ cell.first * m_AmountOfCollumns + cell.second };

		if (m_Cells[cellIndex].isColored == true) return true;
	}

	return false;
}