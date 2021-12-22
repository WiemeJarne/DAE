#pragma once
using utils::Texture;

class Grid
{
public:
	Grid(Texture texture, int amountOfRows, int amountOfColumns);
	~Grid();

	void Draw(Texture* dynArrGrid, int amountOfRows, int amountOfColumns);

private:
	void RandomMinePosGenerator();
	void CheckAdjacentTiles(const int tileIndex);
	void InitDynArrGrid(const int amountOfRows, const int amountOfColumns);
	int GenerateRandomNumber(int topBoundary);

	Texture* m_DynArrGrid;
	Texture m_Texture;
	int m_AmountOfRows;
	int m_AmountOfColumns;
};