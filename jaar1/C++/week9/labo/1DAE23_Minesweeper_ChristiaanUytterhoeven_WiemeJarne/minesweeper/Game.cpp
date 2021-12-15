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

	std::cout << "-- Minesweeper --\nPress 'i' for more info.\n\n";
	AskUserInput();
	
	InitArr(g_GridArr, g_DefaultTileTexture);
	InitArr(g_MineGridArr, g_NumbersTexturesArr[0]);
	InitArr(g_TilesCheckedArr, -1);

	RandomMinesPosGenerator(g_MineGridArr);
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawGrid(g_GridArr, g_AmountOfRowsAndColumnsAndMines[0], g_AmountOfRowsAndColumnsAndMines[1]);
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
	delete[] g_AmountOfRowsAndColumnsAndMines;
	delete[] g_MineLocations;
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_r:
		reset();
		break;

	case SDLK_g:
		if(CheckIfPlayerWon()) RevealGrid();
		break;

	case SDLK_i:
		PrintInfo();
	}
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
	Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
	
	switch (e.button)
		{
		case SDL_BUTTON_LEFT:
			if (CheckIfPlayerWon() == false)
			{
				ClickedOnGrid(mousePos, Point2f{ 0,0 });
				
				if (CheckIfPlayerWon())
				{
					std::cout << "\nYOU WON!\nPress 'r' to reset.\nPress 'g' to reveal the grid.\n";
				}
			}
			break;

		case SDL_BUTTON_RIGHT:
			if (CheckIfPlayerWon() == false)
			{
				ToggleTexture(mousePos, Point2f{ 0,0 }, g_DefaultTileTexture, g_FlagTexture);

				if (CheckIfPlayerWon())
				{
					std::cout << "\nYOU WON!\nPress r to reset.\nPress g to reveal the grid.\n";
				}
			}
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
	const int amountOfRows{ g_AmountOfRowsAndColumnsAndMines[0] };
	const int amountOfColumns{ g_AmountOfRowsAndColumnsAndMines[1] };

	for (int index{}; index < g_AmountOfNumberTextures; ++index)
	{
		DeleteTexture(g_NumbersTexturesArr[index]);
	}

	for (int index{}; index < amountOfRows * amountOfColumns; ++index)
	{
		DeleteTexture(g_GridArr[index]);
	}
	
	DeleteTexture(g_DefaultTileTexture);
	DeleteTexture(g_FlagTexture);
	DeleteTexture(g_MineTexture);
}

void AskUserInput()
{

	g_AmountOfRowsAndColumnsAndMines = new int[3];
	int amountOfRows{};
	int amountOfColumns{};
	int amountOfmines{};
	float tileSideLenght{};
	int maxAmountOfRowsAndColumns{};

	std::cout << "How many pixels do you want the side lenght of 1 tile to have?(minimum 10) ";
	std::cin >> tileSideLenght;

	g_ScaleFactor = tileSideLenght / g_DefaultTileTexture.height;
	maxAmountOfRowsAndColumns = int(g_WindowHeight / tileSideLenght);

	std::cout << "\nHow large do you want the field to be?(maximum " << maxAmountOfRowsAndColumns << ") ";
	std::cin >> amountOfRows;
	g_AmountOfRowsAndColumnsAndMines[0] = amountOfRows;

	amountOfColumns = amountOfRows;
	g_AmountOfRowsAndColumnsAndMines[1] = amountOfColumns;

	std::cout << "\nHow many mines do you want on the field? ";
	std::cin >> amountOfmines;
	g_AmountOfRowsAndColumnsAndMines[2] = amountOfmines;
}

void InitArr(Texture*& textureArr, Texture texture)
{
	const int size{ g_AmountOfRowsAndColumnsAndMines[0] * g_AmountOfRowsAndColumnsAndMines[1] };
	textureArr = new Texture[size];

	for (int index{}; index < size; ++index)
	{
		textureArr[index] = texture;
	}
}

void InitArr(int*& gridArr, int number)
{
	const int size = { g_AmountOfRowsAndColumnsAndMines[0] * g_AmountOfRowsAndColumnsAndMines[1] };
	gridArr = new int[size];

	for (int index{}; index <size; ++index)
	{
		gridArr[index] = number;
	}
}

void RandomMinesPosGenerator(Texture*& mineGridArr)
{
	const int amountOfRows{ g_AmountOfRowsAndColumnsAndMines[0] };
	const int amountOfColumns{ g_AmountOfRowsAndColumnsAndMines[1] };
	const int amountOfMines{ g_AmountOfRowsAndColumnsAndMines[2] };
	const int topBoundary{ amountOfRows * amountOfColumns };
	g_MineLocations = new int[amountOfMines];

	for (int mineNumber{}; mineNumber < amountOfMines; ++mineNumber)
	{
		int randomLocation{ GenerateRandomNumber(topBoundary) };

		g_MineLocations[mineNumber] = randomLocation;

		for (int index{}; index < mineNumber; ++index)
		{	
			if (randomLocation == g_MineLocations[index])
			{
				randomLocation = GenerateRandomNumber(topBoundary);			
			}			
		}
		mineGridArr[randomLocation] = g_MineTexture;
	}

	for (int index{}; index < topBoundary; ++index)
	{
		if (mineGridArr[index].id != g_MineTexture.id)
		{
		mineGridArr[index] = g_NumbersTexturesArr[CheckAdjacentTiles(index)];
		}
	}
}

int GenerateRandomNumber(int topBoundary)
{
	int randomNumber{ rand() % topBoundary };
	if (g_MineGridArr[randomNumber].id == g_MineTexture.id)
	{
		GenerateRandomNumber(topBoundary);
	}
	return randomNumber;
}

int CheckAdjacentTiles(const int tileIndex)
{
	const int amountOfRows{ g_AmountOfRowsAndColumnsAndMines[0] };
	const int amountOfColumns{ g_AmountOfRowsAndColumnsAndMines[1] };
	const int rowNumber{ tileIndex / amountOfRows };
	const int columnNumber{ tileIndex % amountOfColumns };
	int amountOfMines{};

	for (int dRow{ -1 }; dRow <= 1; ++dRow) // dRow stands for difference
	{
		for (int dColumn{ -1 }; dColumn <= 1; ++dColumn)
		{
			const int currentTileIndex{ columnNumber + dColumn + amountOfRows * (rowNumber + dRow) };

			if (	g_MineGridArr[currentTileIndex].id == g_MineTexture.id
				 && rowNumber + dRow != amountOfRows
				 && rowNumber + dRow != -1
				 && columnNumber + dColumn != amountOfColumns
				 && columnNumber + dColumn != -1							)
			{
				++amountOfMines;
			}
		}
	}
	return amountOfMines;
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

void ClickedOnGrid(Point2f mousePos, Point2f bottomLeftCornerOfGrid)
{
	const int amountOfRows{ g_AmountOfRowsAndColumnsAndMines[0] };
	const int amountOfColumns{ g_AmountOfRowsAndColumnsAndMines[1] };
	Point2f bottomLeftCornerOfCurrentTile{bottomLeftCornerOfGrid};

	for (int rowNumber{}; rowNumber < amountOfRows; ++rowNumber)
	{
		for (int columnNumber{}; columnNumber < amountOfColumns; ++columnNumber)
		{
			const int currentTileIndex{ columnNumber + (amountOfRows * rowNumber) };

			if (    mousePos.x >= bottomLeftCornerOfCurrentTile.x
				 && mousePos.x <= bottomLeftCornerOfCurrentTile.x + g_GridArr[0].width * g_ScaleFactor
				 && mousePos.y >= bottomLeftCornerOfCurrentTile.y
				 && mousePos.y <= bottomLeftCornerOfCurrentTile.y + g_GridArr[0].height * g_ScaleFactor 
				 && g_GridArr[columnNumber + (amountOfRows * rowNumber)].id == g_DefaultTileTexture.id )
			{
				if (BCheckIfClickedPosIsMine(currentTileIndex))
				{
					RevealGrid();
					std::cout << "\nGAME OVER\nYou caused an explosion! Press 'r' to restart.";
				}
				else
				{
					ChangeTileTexture(currentTileIndex);
				}
			}
			bottomLeftCornerOfCurrentTile.x += g_GridArr[0].width * g_ScaleFactor;
		}
		bottomLeftCornerOfCurrentTile.x = bottomLeftCornerOfGrid.x;
		bottomLeftCornerOfCurrentTile.y += g_GridArr[0].height * g_ScaleFactor;
	}
}

bool BCheckIfClickedPosIsMine(const int index)
{
	if (g_MineGridArr[index].id == g_MineTexture.id)
	{
		return true;
	}
	return false;
}

void ChangeTileTexture(const int tileIndex)
{
	const int amountOfRows{ g_AmountOfRowsAndColumnsAndMines[0] };
	const int amountOfColumns{ g_AmountOfRowsAndColumnsAndMines[1] };
	const int rowNumber{ tileIndex / amountOfRows };
	const int columnNumber{ tileIndex % amountOfRows };

	for (int dRow{ -1 }; dRow <= 1; ++dRow) // dRow stands for difference
	{
		for (int dColumn{ -1 }; dColumn <= 1; ++dColumn)
		{
			const int currentTileIndex{ columnNumber + dColumn + amountOfRows * (rowNumber + dRow) };

			if (	(columnNumber + dColumn) >= 0
				 && (columnNumber + dColumn) < amountOfColumns
				 && (rowNumber + dRow) >= 0
				 && (rowNumber + dRow) < amountOfRows			)
			{
				if (    g_MineGridArr[currentTileIndex].id == g_NumbersTexturesArr[0].id && !BInCheckedTilesArr(currentTileIndex))
				{
					g_TilesCheckedArr[g_AmountOfTilesChecked] = currentTileIndex;
					++g_AmountOfTilesChecked;
					g_GridArr[currentTileIndex] = g_NumbersTexturesArr[0];
					ChangeTileTexture(currentTileIndex);
				}
				else if (g_MineGridArr[currentTileIndex].id == g_MineTexture.id && !BInCheckedTilesArr(currentTileIndex))
				{
					g_TilesCheckedArr[g_AmountOfTilesChecked] = currentTileIndex;
					++g_AmountOfTilesChecked;
					ChangeTileTexture(currentTileIndex);
				}
				else
				{
					for (int index{ 1 }; index < g_AmountOfNumberTextures; ++index)
					{
						if (g_MineGridArr[currentTileIndex].id == g_NumbersTexturesArr[index].id && !BInCheckedTilesArr(currentTileIndex))
						{
							g_TilesCheckedArr[g_AmountOfTilesChecked] = currentTileIndex;
							++g_AmountOfTilesChecked;
							g_GridArr[currentTileIndex] = g_NumbersTexturesArr[index];
						}
					}
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

void RevealGrid()
{
	const int amountOfRows{ g_AmountOfRowsAndColumnsAndMines[0] };
	const int amountOfColumns{ g_AmountOfRowsAndColumnsAndMines[1] };

	for (int rowNumber{}; rowNumber < amountOfRows; ++rowNumber)
	{
		for (int columnNumber{}; columnNumber <amountOfColumns; ++columnNumber)
		{
			const int currentTileIndex{ columnNumber + (amountOfRows * rowNumber) };
			g_GridArr[currentTileIndex].id = g_MineGridArr[currentTileIndex].id;
		}
	}
}

void ToggleTexture(Point2f mousePos, Point2f bottomLeftCornerOfGrid, Texture defaultTexture, Texture textureToToggle)
{
	if (g_GridArr[CheckMousePos(mousePos, bottomLeftCornerOfGrid)].id == defaultTexture.id)
	{
		g_GridArr[CheckMousePos(mousePos, bottomLeftCornerOfGrid)] = textureToToggle;
	}
	else if (g_GridArr[CheckMousePos(mousePos, bottomLeftCornerOfGrid)].id == textureToToggle.id)
	{
		g_GridArr[CheckMousePos(mousePos, bottomLeftCornerOfGrid)] = defaultTexture;
	}
}

int CheckMousePos(Point2f mousePos, Point2f bottomLeftCornerOfGrid)
{
	const int amountOfRows{ g_AmountOfRowsAndColumnsAndMines[0] };
	const int amountOfColumns{ g_AmountOfRowsAndColumnsAndMines[1] };
	Point2f bottomLeftCornerOfCurrentTile{ bottomLeftCornerOfGrid };

	for (int rowNumber{}; rowNumber < amountOfRows; ++rowNumber)
	{
		for (int columnNumber{}; columnNumber < amountOfColumns; ++columnNumber)
		{
			const int currentTileIndex{ columnNumber + (amountOfRows * rowNumber) };

			if (	mousePos.x >= bottomLeftCornerOfCurrentTile.x
				 && mousePos.x <= bottomLeftCornerOfCurrentTile.x + g_GridArr[0].width * g_ScaleFactor
				 && mousePos.y >= bottomLeftCornerOfCurrentTile.y
				 && mousePos.y <= bottomLeftCornerOfCurrentTile.y + g_GridArr[0].height * g_ScaleFactor)
			{
				return currentTileIndex;
			}
			bottomLeftCornerOfCurrentTile.x += g_GridArr[0].width * g_ScaleFactor;
		}
		bottomLeftCornerOfCurrentTile.x = bottomLeftCornerOfGrid.x;
		bottomLeftCornerOfCurrentTile.y += g_GridArr[0].height * g_ScaleFactor;
	}
	return -1;
}

bool CheckIfPlayerWon()
{
	const int amountOfRows{ g_AmountOfRowsAndColumnsAndMines[0] };
	const int amountOfColumns{ g_AmountOfRowsAndColumnsAndMines[1] };
	const int amountOfMines{ g_AmountOfRowsAndColumnsAndMines[2] };
	int minesFound{};

	for (int rowNumber{}; rowNumber < amountOfRows; ++rowNumber)
	{
		for (int columnNumber{}; columnNumber < amountOfColumns; ++columnNumber)
		{
			int currentTileIndex{ columnNumber + (amountOfRows * rowNumber) };

			if (g_GridArr[currentTileIndex].id == g_FlagTexture.id && g_MineGridArr[currentTileIndex].id == g_MineTexture.id)
			{
				++minesFound;
			}

			if (minesFound == amountOfMines)
			{
				return true;
			}
		}
	}	
	return false;
}

void reset()
{
	AskUserInput();

	InitArr(g_GridArr, g_DefaultTileTexture);
	InitArr(g_MineGridArr, g_NumbersTexturesArr[0]);
	InitArr(g_TilesCheckedArr, -1);

	RandomMinesPosGenerator(g_MineGridArr);
}

void PrintInfo()
{
	std::cout << "\nThere are " << g_AmountOfRowsAndColumnsAndMines[2] << " mines on the field.\n\n";
	std::cout << "The left mouse button is used to uncover the squares.\n";
	std::cout << "If you click on a mine you cause an explosion and is it GAME OVER.\n";
	std::cout << "The right mouse butten is used to place flags.\n";
	std::cout << "If you click on a flag with the left mouse button nothing happens.\n";
	std::cout << "But if you click on a flag with the right mouse button the flag disappears.\n";
	std::cout << "The goal of the game is to place flags on all mines without causing an explosion.\n";
	std::cout << "If you want to restart the game press the 'r' button\n\n";
}
#pragma endregion ownDefinitions