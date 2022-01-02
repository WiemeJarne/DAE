#include "pch.h"
#include "Game.h"
#include "Tile.h"
#include <iostream>
#include <string>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	CreateTiles();
}

void Draw()
{
	ClearBackground(0,0,0);

	DrawTiles();

}

void Update(float elapsedSec)
{
	// process input, do physics 

	CheckActivation(g_MousePos);

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
	Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };

	g_MousePos = mousePos;
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		//std::cout << "Left mouse button released\n";

		CheckHitregions(g_MousePos);
		break;
	}
	case SDL_BUTTON_RIGHT:
		//std::cout << "Right mouse button released\n";
		break;
	case SDL_BUTTON_MIDDLE:
		//std::cout << "Middle mouse button released\n";
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void CreateTiles()
{
	for (int rowIdx{}; rowIdx < g_GridRows; ++rowIdx)
	{
		for (int colIdx{}; colIdx < g_GridColumns; ++colIdx)
		{
			int index{ utils::GetGridIndex(rowIdx, colIdx, g_GridColumns) };
			std::string texturePath{ "Resources/Tiles" + std::to_string(rowIdx) + std::to_string(colIdx) + ".png" };
			const int nrOfAnimals{ 6 };


			g_DstTile[index].width = g_TileSize;
			g_DstTile[index].height = g_TileSize;
			g_DstTile[index].left = g_Margin + colIdx * g_DstTile[index].width;
			g_DstTile[index].bottom = g_Margin + rowIdx * g_DstTile[index].height;

			g_pTileArr[index] = new Tile(g_DstTile[index], texturePath, nrOfAnimals);
		}
	}

	std::cout << "Tiles are created..\n";

}

void DrawTiles()
{
	for (int index{}; index < g_AmountOfTiles; ++index)
	{
		g_pTileArr[index]->Draw();
	}

	Color4f borderColor{ 1,0,0,1 };
	SetColor(borderColor);

	DrawRect(g_Margin, g_Margin, g_TileSize * 2, g_TileSize * 2, 5);
}

void CheckActivation(const Point2f& rMousePos)
{
	for (int index{}; index < g_AmountOfTiles; ++index)
	{
		g_pTileArr[index]->CheckActivation(rMousePos);
	}
}

void CheckHitregions(const Point2f& rMousePos)
{
	for (int index{}; index < g_AmountOfTiles; ++index)
	{
			g_pTileArr[index]->CheckHit(rMousePos);
	}
}

void DrawName()
{

}

#pragma endregion ownDefinitions