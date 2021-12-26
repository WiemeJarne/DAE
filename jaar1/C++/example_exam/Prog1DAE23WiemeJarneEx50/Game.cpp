#include "pch.h"
#include "Game.h"
#include "Tile.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	CreateTextures();
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	for (int index{}; index < g_AmountOfTiles; ++index)
	{
		g_DynnArrTiles[index]->Draw();
	}
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
	Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };

	for (int index{}; index < g_AmountOfTiles; ++index)
	{
		g_DynnArrTiles[index]->CheckActivation(mousePos);
	}
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };

	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		for (int index{}; index < g_AmountOfTiles; ++index)
		{
			g_DynnArrTiles[index]->CheckHit(mousePos);
		}
	}
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void CreateTextures()
{
	Rectf destinationRect{};
	destinationRect.height = 128;
	destinationRect.width = destinationRect.height;
	destinationRect.bottom = 0;
	destinationRect.left = 0;
	
	int rowNumber{ 1 };
	int columnNumber{};

	std::string fileLocation{ "Resources/Tiles" + std::to_string(rowNumber) + std::to_string(columnNumber) + ".png"};

	const int amountOfAnimals{ 6 };

	g_DynnArrTiles[0] = new Tile(destinationRect, fileLocation, amountOfAnimals);


	columnNumber = 1;
	destinationRect.left = destinationRect.width;

	fileLocation = "Resources/Tiles" + std::to_string(rowNumber) + std::to_string(columnNumber) + ".png";

	g_DynnArrTiles[1] = new Tile(destinationRect, fileLocation, amountOfAnimals);


	rowNumber = 0;
	destinationRect.bottom = destinationRect.height;

	fileLocation = "Resources/Tiles" + std::to_string(rowNumber) + std::to_string(columnNumber) + ".png";

	g_DynnArrTiles[2] = new Tile(destinationRect, fileLocation, amountOfAnimals);


	columnNumber = 0;
	destinationRect.left = 0;

	fileLocation = "Resources/Tiles" + std::to_string(rowNumber) + std::to_string(columnNumber) + ".png";

	g_DynnArrTiles[3] = new Tile(destinationRect, fileLocation, amountOfAnimals);
}
#pragma endregion ownDefinitions