#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	CreateNumbersTexturesArr(g_NumbersTexturesArr, g_AmountOfNumberTextures);
	CreateTextures();
	InitGridArr(g_GridArr, g_AmountOfRows, g_AmountOfColumns, g_DefaultTileTexture);
	InitGridArr(g_MineGridArr, g_AmountOfRows, g_AmountOfColumns, g_TilePressedTexture);
	InitGridArr(g_TilesCheckedArr, g_AmountOfRows, g_AmountOfColumns, g_TilePressedTexture);
	RandomMinesPosGenerator(g_MineGridArr, g_AmountOfRows, g_AmountOfColumns, 10);
	
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawGrid(g_GridArr, g_AmountOfRows, g_AmountOfColumns);
}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
	DeleteTextures();
	delete[] g_NumbersTexturesArr;
	delete[] g_GridArr;
	delete[] g_MineGridArr;
	delete[] g_TilesCheckedArr;
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		CheckMousePos(Point2f{ float(e.x), float(g_WindowHeight - e.y) }, Point2f{ 0,0 });
		break;
	}
	case SDL_BUTTON_RIGHT:
		
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void CreateTextures()
{
	TextureFromFile("Resources/default.png", g_DefaultTileTexture);
	TextureFromFile("Resources/flag.png", g_FlagTexture);
	TextureFromFile("Resources/mine.png", g_MineTexture);
}

void CreateNumbersTexturesArr(Texture*& textureArr, const int amountOfTextures)
{
	textureArr = new Texture[amountOfTextures];
	int number{0};

	for (int index{}; index < amountOfTextures; ++index)
	{
		if (!(TextureFromFile("Resources/" + std::to_string(number) + ".png", textureArr[index])))
		{
			std::cout << "Texture failed to load\n";
		};
		++number;
	}
}

void DeleteTextures()
{
	for (int index{}; index < g_AmountOfNumberTextures; ++index)
	{
		DeleteTexture(g_NumbersTexturesArr[index]);
	}

	for (int index{}; index < g_AmountOfRows * g_AmountOfColumns; ++index)
	{
		DeleteTexture(g_GridArr[index]);
	}
	
	DeleteTexture(g_DefaultTileTexture);
	DeleteTexture(g_FlagTexture);
	DeleteTexture(g_MineTexture);
}

void InitGridArr(Texture*& gridArr, const int amountOfRows, const int amountOfColumns, Texture texture)
{
	gridArr = new Texture[amountOfRows * amountOfColumns];

	for (int index{}; index < amountOfRows * amountOfColumns; ++index)
	{
		gridArr[index] = texture;
	}
}

void InitGridArr(int*& gridArr, const int amountOfRows, const int amountOfColumns, Texture texture)
{
	gridArr = new int[amountOfRows * amountOfColumns];

	for (int index{}; index < amountOfRows * amountOfColumns; ++index)
	{
		gridArr[index] = -1;
	}
}

void DrawGrid(Texture* gridArr, const int amountOfRows, const int amountOfColumns)
{
	Rectf dstRect{ 0, 0, gridArr[0].width  * g_ScaleFactor, gridArr[0].height  * g_ScaleFactor };

	for (int rowNumber{}; rowNumber < amountOfRows; ++rowNumber)
	{
		for (int columnNumber{}; columnNumber < amountOfColumns; ++columnNumber)
		{
			DrawTexture(gridArr[columnNumber + (amountOfRows * rowNumber)], dstRect);

			dstRect.left += gridArr[0].width * g_ScaleFactor;
		}

		dstRect.left = 0;
		dstRect.bottom += gridArr[0].height * g_ScaleFactor;
	}
}

void CheckMousePos(Point2f mousePos, Point2f bottomLeftCornerOfGrid)
{
	Point2f bottomLeftCornerOfCurrentTile{bottomLeftCornerOfGrid};

	for (int rowNumber{}; rowNumber < g_AmountOfRows; ++rowNumber)
	{
		for (int columnNumber{}; columnNumber < g_AmountOfColumns; ++columnNumber)
		{
			if (    mousePos.x >= bottomLeftCornerOfCurrentTile.x
				 && mousePos.x <= bottomLeftCornerOfCurrentTile.x + g_GridArr[0].width * g_ScaleFactor
				 && mousePos.y >= bottomLeftCornerOfCurrentTile.y
				 && mousePos.y <= bottomLeftCornerOfCurrentTile.y + g_GridArr[0].height * g_ScaleFactor 
				 && g_GridArr[columnNumber + (g_AmountOfRows * rowNumber)].id == g_DefaultTileTexture.id )
			{
				ChangeTileTexture(columnNumber + (g_AmountOfRows * rowNumber));
			}
			bottomLeftCornerOfCurrentTile.x += g_GridArr[0].width * g_ScaleFactor;
		}
		bottomLeftCornerOfCurrentTile.x = bottomLeftCornerOfGrid.x;
		bottomLeftCornerOfCurrentTile.y += g_GridArr[0].height * g_ScaleFactor;
	}
}

int CheckAdjacentTiles(const int tileIndex)
{
	int amountOfMines{};
	int rowNumber{ tileIndex / g_AmountOfRows };
	int columnNumber{ tileIndex % g_AmountOfColumns };
	
	//columnNumber + (g_AmountOfRows * rowNumber)
	for (int dRow{ -1 }; dRow <= 1; ++dRow)
	{
		for (int dColumn{ -1 }; dColumn <= 1; ++dColumn)
		{
			if (g_MineGridArr[columnNumber + dColumn + g_AmountOfRows * (rowNumber + dRow)].id == g_MineTexture.id)
			{
				++amountOfMines;
			}
		}
	}

	return amountOfMines;
}

void ChangeTileTexture(const int tileIndex)
{
	int rowNumber{ tileIndex / g_AmountOfRows };
	int columnNumber{ tileIndex % g_AmountOfRows };

	for (int dRow{ -1 }; dRow <= 1; ++dRow) // dRow stands for difference
	{
		for (int dColumn{ -1 }; dColumn <= 1; ++dColumn)
		{
			if ((columnNumber + dColumn) >= 0
				&& (columnNumber + dColumn) < g_AmountOfColumns
				&& (rowNumber + dRow) >= 0
				&& (rowNumber + dRow) < g_AmountOfRows)
			{
				int currentTileIndex{ columnNumber + dColumn + g_AmountOfRows * (rowNumber + dRow) };
				if (g_MineGridArr[tileIndex].id == g_NumbersTexturesArr[0].id
					&& !BInCheckedTilesArr(currentTileIndex))
				{
					g_TilesCheckedArr[g_AmountOfTilesChecked] = currentTileIndex;
					++g_AmountOfTilesChecked;
					g_GridArr[currentTileIndex] = g_NumbersTexturesArr[0];
					ChangeTileTexture(currentTileIndex);
				} 
				else if (g_MineGridArr[tileIndex].id == g_NumbersTexturesArr[1].id && !BInCheckedTilesArr(currentTileIndex))
				{
					g_TilesCheckedArr[g_AmountOfTilesChecked] = currentTileIndex;
					++g_AmountOfTilesChecked;
					g_GridArr[currentTileIndex] = g_NumbersTexturesArr[1];
					ChangeTileTexture(currentTileIndex);
				}

			}
		}
	}
}

bool BInCheckedTilesArr(const int tileToCheck)
{
	for (int index{}; index < g_AmountOfTilesChecked; ++index)
	{
		if (g_TilesCheckedArr[index] == tileToCheck)
		{
			return true;
		}
	}
	return false;
}

void RandomMinesPosGenerator(Texture*& mineGridArr, const int amountOfRows, const int amountOfColumns, const int amountOfMines)
{
	int topBoundary{ amountOfRows * amountOfColumns };

	for (int mineNumber{}; mineNumber < amountOfMines; ++mineNumber)
	{
		int randomNumber{ rand() % topBoundary };
		std::cout << randomNumber << '\n';
		mineGridArr[randomNumber] = g_MineTexture;
	}

	for (int index{}; index < topBoundary; ++index)
	{
		if (mineGridArr[index].id != g_MineTexture.id)
		{
			mineGridArr[index] = g_NumbersTexturesArr[CheckAdjacentTiles(index)];
		}
	}
}
#pragma endregion ownDefinitions