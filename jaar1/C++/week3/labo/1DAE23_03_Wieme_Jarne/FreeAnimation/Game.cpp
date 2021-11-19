#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawVerticalMovingRect();
	DrawDiagnalMovingRect();
	DrawHorizontalMovingRect();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	angle += float(M_PI / 180);
	g_SpaceBelowRect1 = (100 * sinf(angle) + 110 );

	g_SpaceLeftFromRect2 = (100 * sinf(angle) + 105);
	g_SpaceBelowRect2 = (100 * sinf(angle) + 110);

	g_SpaceLeftFromRect3 = (140 * sinf(angle) + 150);
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

#pragma endregion ownDefinitions

void DrawVerticalMovingRect()
{
	float spaceLeftFromRect{ 390 };
	const float rectWidth{ 75 };
	const float rectHeight{ 25 };

	SetColor(0.f, 1.f, 0.25f, 1.f);
	FillRect(spaceLeftFromRect, g_SpaceBelowRect1, rectWidth, rectHeight);

	SetColor(0.f, 0.f, 0.f, 1.f);
	DrawRect(spaceLeftFromRect, g_SpaceBelowRect1, rectWidth, rectHeight);
}

void DrawDiagnalMovingRect()
{
	const float rectWidth{ 75 };
	const float rectHeight{ 25 };

	SetColor(0.f, 1.f, 0.25f, 1.f);
	FillRect(g_SpaceLeftFromRect2, g_SpaceBelowRect2, rectWidth, rectHeight);

	SetColor(0.f, 0.f, 0.f, 1.f);
	DrawRect(g_SpaceLeftFromRect2, g_SpaceBelowRect2, rectWidth, rectHeight);
}

void DrawHorizontalMovingRect()
{
	const float spaceBelowRect{ 250 };
	const float rectWidth{ 75 };
	const float rectHeight{ 25 };

	SetColor(0.f, 1.f, 0.25f, 1.f);
	FillRect(g_SpaceLeftFromRect3, spaceBelowRect, rectWidth, rectHeight);

	SetColor(0.f, 0.f, 0.f, 1.f);
	DrawRect(g_SpaceLeftFromRect3, spaceBelowRect, rectWidth, rectHeight);
}