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
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawLines();
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
	switch (key)
	{
	case SDLK_RIGHT:
		SwitchColor();
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);
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
void DrawLines()
{
	const int spaceBetweenLines{ 9 };

	if (g_Color == Color::red)
	{
		SetColor(1.f, 0.f, 0.f);
	}

	if (g_Color == Color::green)
	{
		SetColor(0.f, 1.f, 0.f);
	}

	if (g_Color == Color::blue)
	{
		SetColor(0.f, 0.f, 1.f);
	}

	for (float x{}; x <= g_WindowWidth; x += spaceBetweenLines)
	{
		Point2f xPos(x, 0);
		DrawLine(xPos, g_MousePos);

		xPos.y = g_WindowHeight;
		DrawLine(xPos, g_MousePos);
	}

	for (float y{}; y <= g_WindowHeight; y += spaceBetweenLines)
	{
		Point2f yPos{ 0, y };
		DrawLine(yPos, g_MousePos);

		yPos.x = g_WindowWidth;
		DrawLine(yPos, g_MousePos);
	}
}
void SwitchColor()
{
	if (g_Color == Color::blue)
	{
		g_Color = Color::red;
	}
	else if(g_Color == Color::green)
	{
		g_Color = Color::blue;
	}
	else
	{
		g_Color = Color::green;
	}
}
#pragma endregion ownDefinitions