#pragma once
using utils::Texture;

class Grid
{
public:
	Grid(const int windowWidth, const int windowHeight);
	~Grid();

	void Draw();
	void AskUserInput(const int windowWidth, const int windowHeight);

private:
	void RandomMinePosGenerator();
	void CheckAdjacentTiles(const int tileIndex);
	void InitDynArrGrid();
	void InitDynnArrMineGrid();
	void CreateTextures();
	void CreateNumberTextures();
	int GenerateRandomNumber();

	Texture* m_DynArrGrid;
	Texture* m_DynArrNumberTextures;
	Texture* m_DynArrMineGrid;
	Texture m_DefaultTileTexture;
	Texture m_FlagTexture;
	Texture m_MineTexture;
	Texture m_DefaultTiletexture;

	int* m_DynArrMineLocations;
	int m_SizeDynnArr;
	int m_AmountOfRows;
	int m_AmountOfColumns;
	int m_AmountOfMines;
	int m_TileSideLenght;
	int m_ScaleFactor;
	int m_AmountOfNumberTextures;
};