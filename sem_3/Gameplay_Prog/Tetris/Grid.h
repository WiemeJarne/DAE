#pragma once
#include "GameEngine.h"
#include "structs.h"

class Grid
{
public:
	Grid(int topLeftX, int topLeftY, int amountOfRows, int amountOfCollumns, int cellSideLength, COLORREF color = RGB(255.f, 255.f, 255.f));

	void Update(float elapsedSec);
	void Paint() const;
	void MoveCurrentDroppingTetriminoLeft();
	void MoveCurrentDroppingTetriminoRight();
	void RotateCurrentDroppingTetriminoCCW(); // CCW = counter clock wise
	void RotateCurrentDroppingTetriminoCW(); // CW = clock wise

private:
	struct Tetrimino
	{
		int rowNr; // the rowNr on the grid of the top left cell
		int colNr; // the colNr on the grid of the top left cell
		int cellSideLenght;
		COLORREF color{ RGB(120, 120, 120) };

		Matrix* pData{};

		Matrix4X4 data
		{
			Vector4(0.f, 0.f, 0.f, 0.f),
			Vector4(1.f, 1.f, 1.f, 1.f), 
			Vector4(0.f, 0.f, 0.f, 0.f),
			Vector4(0.f, 0.f, 0.f, 0.f)
		};

		Tetrimino(int _rowNr, int _colNr, int _cellSideLenght)
		{
			rowNr = _rowNr;
			colNr = _colNr;
			cellSideLenght = _cellSideLenght;

			pData = new Matrix4X4
			{
				Vector4(0.f, 0.f, 0.f, 0.f),
				Vector4(1.f, 1.f, 1.f, 1.f),
				Vector4(0.f, 0.f, 0.f, 0.f),
				Vector4(0.f, 0.f, 0.f, 0.f)
			};

			//pData = new	Matrix3X3
			//{
			//	Vector3(1.f, 0.f, 0.f),
			//	Vector3(1.f, 1.f, 1.f),
			//	Vector3(0.f, 0.f, 0.f)
			//};
		}

		void Paint(int x, int y) const
		{
			GAME_ENGINE->SetColor(color);
			
			for (int rowNr{}; rowNr < 4; ++rowNr)
			{
				for (int colNr{}; colNr < 4; ++colNr)
				{
					if (pData->GetValue(rowNr, colNr) == 1.f)
					{
						GAME_ENGINE->FillRect(x + cellSideLenght * colNr, y + cellSideLenght * rowNr, cellSideLenght, cellSideLenght);
					}
				}
			}
		}

		void RotateCCW()
		{
			//data.Transpose();
			//data.InverseCollumns();
			pData->Transpose();
			pData->InverseCollumns();
		}

		void RotateCW()
		{
			//data.Transpose();
			//data.InverseRows();
			pData->Transpose();
			pData->InverseRows();
		}
	};

	bool CollisionTest(); // returns true if the current dropping tetrimino has hit another tetrimino,
												// the current dropping tetrimino has hit one of the borders of the grid

	float m_DropSpeed; // how many seconds it takes for the current dropping tetrimino to drop 1 cell
	float m_AmountOfSecSinceLastCellDrop; // how many seconds it has been since the current dropping tetrimino dropped 1 cell

	float m_MoveSpeed; // how fast the player can move the current dropping tetrimino to the left or right
	float m_AmountOfSecSinceLastMove; // how many seconds it has been since the current dropping tetrimino moved to the left or right

	float m_RotateSpeed; // how fast the player can rotate the current dropping tetrimino
	float m_AmountOfSecSinceLastRotate; // how many seconds it has been since the current dropping tetrimino was rotated

	Tetrimino m_CurrentDroppingTetrimino;
	const int m_TopLeftX;
	const int m_TopLeftY;
	const int m_AmountOfRows;
	const int m_AmountOfCollumns;
	const int m_CellSideLenght;
	const COLORREF m_Color;
	
	struct Cell
	{
		Cell() = default;

		bool isColored{ false };
		COLORREF color = RGB(0, 0, 0);

		void Paint(int x, int y, int sideLenght) const
		{
			GAME_ENGINE->SetColor(color);
			GAME_ENGINE->FillRect(x, y, sideLenght, sideLenght);
		}
	};

	std::vector<Cell> m_Cells;
};