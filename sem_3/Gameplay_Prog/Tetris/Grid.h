#pragma once
#include "GameEngine.h"

class Grid
{
public:
	Grid(int topLeftX, int topLeftY, int amountOfRows, int amountOfCollumns, int CellSideLength, COLORREF color = RGB(255.f, 255.f, 255.f));

	void Paint();
	
private:
	struct Tetrimino
	{
		int rowIndex;
		int collumnIndex;
		COLORREF color;
		
		

		void PaintTetrimino(Tetrimino tetrimino)
		{

		};
	};

	const int m_TopLeftX;
	const int m_TopLeftY;
	const int m_AmountOfRows;
	const int m_AmountOfCollumns;
	const int m_CellSideLenght;
	const COLORREF m_Color;
};