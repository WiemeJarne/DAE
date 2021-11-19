#include "pch.h"
#include "Game.h"
#include <iostream>
#include<string>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	g_Red.r = 1.f;
	g_Red.g = 102.f / 255.f;
	g_Red.b = 102.f / 255.f;

	g_Yellow.r = 1.f;
	g_Yellow.g = 1.f;
	g_Yellow.b = 102.f / 255.f;

	
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawMainPile();

	DrawPlayerPile();

	DrawPCPile();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	if (g_PlayerWon)
	{
		std::cout << g_PCMoves << '\n' << g_PlayerMoves << "\nYou won";
		g_PlayerWon = false;
	}

	if (g_PlayerLost)
	{
		std::cout << g_PCMoves << '\n' << g_PlayerMoves << "\nYou lost";
		g_PlayerLost = false;
	}
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
	switch (key)
	{
	case SDLK_1:
	case SDLK_KP_1:

		++g_PlayerPile;

		g_NumberOfMatchesTakenByPlayer = 1;

		CheckIfSomeoneWon();

		g_MainPile -= g_NumberOfMatchesTakenByPlayer;

		g_PlayerMoves += std::to_string(int{ g_NumberOfMatchesTakenByPlayer }) + ' ';

		g_PCTurn = true;

		break;

	case SDLK_2:
	case SDLK_KP_2:

		g_PlayerPile += 2;

		g_NumberOfMatchesTakenByPlayer = 2;

		CheckIfSomeoneWon();

		g_MainPile -= g_NumberOfMatchesTakenByPlayer;

		g_PlayerMoves += std::to_string(int{ g_NumberOfMatchesTakenByPlayer }) + ' ';

		g_PCTurn = true;

		break;

	case SDLK_3:
	case SDLK_KP_3:

		g_PlayerPile += 3;

		g_NumberOfMatchesTakenByPlayer = 3;

		CheckIfSomeoneWon();

		g_MainPile -= g_NumberOfMatchesTakenByPlayer;

		g_PlayerMoves += std::to_string(int{ g_NumberOfMatchesTakenByPlayer }) + ' ';

		g_PCTurn = true;

		break;
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
void DrawMainPile()
{
	float spaceLeftFromMatch{ 30 };
	float spaceBelowMatch{ g_WindowHeight - 70 };
	const float matchWitdh{ 4 };
	const float yellowPartHeight{ 10 };
	const float redPartHeight{ 40 };
	const float spaceBetweenMatches{ 10 };

	for (int matchNumber{}; matchNumber < g_MainPile; ++matchNumber)
	{
		SetColor(g_Yellow);
		FillRect(spaceLeftFromMatch, spaceBelowMatch + redPartHeight, matchWitdh, yellowPartHeight);

		SetColor(g_Red);
		FillRect(spaceLeftFromMatch, spaceBelowMatch, matchWitdh, redPartHeight);

		spaceLeftFromMatch += matchWitdh + spaceBetweenMatches;
	}
}

void DrawPlayerPile()
{
	float spaceLeftFromMatch{ 30 };
	float spaceBelowMatch{ 20 };
	const float matchWitdh{ 4 };
	const float yellowPartHeight{ 10 };
	const float redPartHeight{ 40 };
	const float spaceBetweenMatches{ 10 };

	for (int matchNumber{}; matchNumber < g_PlayerPile; ++matchNumber)
	{
		SetColor(g_Yellow);
		FillRect(spaceLeftFromMatch, spaceBelowMatch + redPartHeight, matchWitdh, yellowPartHeight);

		SetColor(g_Red);
		FillRect(spaceLeftFromMatch, spaceBelowMatch, matchWitdh, redPartHeight);

		spaceLeftFromMatch += matchWitdh + spaceBetweenMatches;
	}
}

void DrawPCPile()
{
	if (g_PCTurn)
	{
		GenerateRandomNumberOfMatches();

		g_PCPile += g_NumberOfMatchesTakenByPC;

		CheckIfSomeoneWon();

		g_MainPile -= g_NumberOfMatchesTakenByPC;

		g_PCMoves += std::to_string(int{ g_NumberOfMatchesTakenByPC }) + ' ';

		g_NumberOfMatchesTakenByPC = 0;
	}

	float spaceLeftFromMatch{ 300 };
	float spaceBelowMatch{ 20 };
	const float matchWitdh{ 4 };
	const float yellowPartHeight{ 10 };
	const float redPartHeight{ 40 };
	const float spaceBetweenMatches{ 10 };

	for (int matchNumber{}; matchNumber < g_PCPile; ++matchNumber)
	{
		SetColor(g_Yellow);
		FillRect(spaceLeftFromMatch, spaceBelowMatch + redPartHeight, matchWitdh, yellowPartHeight);

		SetColor(g_Red);
		FillRect(spaceLeftFromMatch, spaceBelowMatch, matchWitdh, redPartHeight);

		spaceLeftFromMatch += matchWitdh + spaceBetweenMatches;
	}

	g_PCTurn = false;
}

void GenerateRandomNumberOfMatches()
{
	g_NumberOfMatchesTakenByPC = rand() % 3 + 1;

	if (g_MainPile == 1)
	{
		g_NumberOfMatchesTakenByPC = 1;
	}

	if (g_MainPile == 2 && g_NumberOfMatchesTakenByPC == 3)
	{
		g_NumberOfMatchesTakenByPC = rand() % 2 + 1;
	}
}

void CheckIfSomeoneWon()
{
	if (g_NumberOfMatchesTakenByPlayer == g_MainPile)
	{
		g_PlayerLost = true;
		g_PCTurn = false;
	}

	if (g_NumberOfMatchesTakenByPC == g_MainPile)
	{
		g_PlayerWon = true;
	}
}
#pragma endregion ownDefinitions