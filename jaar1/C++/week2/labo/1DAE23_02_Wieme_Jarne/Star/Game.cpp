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
	DrawStar();
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

void DrawStar()
{
	const float outerRadius{ 200 };

	//15 degrees
	const double angle{ 0.261799388f };

	//the numbering of the points start at the most right point and go counterclockwise
	const float point1x{ float(outerRadius + (g_WindowWidth / 2)) }, point1y{ float(g_WindowHeight / 2) };
	const float point2x{ float(1 / 3.f * outerRadius * cos(2 * angle) + (g_WindowWidth / 2)) }, point2y{ float(1 / 3.f * outerRadius * sin(2 * angle) + (g_WindowHeight / 2)) };
	const float point3x{ float(2 / 3.f * outerRadius * cos(3 * angle) + (g_WindowWidth / 2)) }, point3y{ float(2 / 3.f * outerRadius * sin(3 * angle) + (g_WindowHeight / 2)) };
	const float point4x{ float(1 / 3.f * outerRadius * cos(4 * angle) + (g_WindowWidth / 2)) }, point4y{ float(1 / 3.f * outerRadius * sin(4 * angle) + (g_WindowHeight / 2)) };
	const float point5x{ float(g_WindowWidth / 2) }, point5y{ float(outerRadius + (g_WindowHeight / 2)) };
	const float point6x{ float(1 / 3.f * outerRadius * cos(8 * angle) + (g_WindowWidth / 2)) }, point6y{ float(1 / 3.f * outerRadius * sin(8 * angle) + (g_WindowHeight / 2)) };
	const float point7x{ float(2 / 3.f * outerRadius * cos(9 * angle) + (g_WindowWidth / 2)) }, point7y{ float(2 / 3.f * outerRadius * sin(9 * angle) + (g_WindowHeight / 2)) };
	const float point8x{ float(1 / 3.f * outerRadius * cos(10 * angle) + (g_WindowWidth / 2)) }, point8y{ float(1 / 3.f * outerRadius * sin(10 * angle) + (g_WindowHeight / 2)) };
	const float point9x{ float(-outerRadius + (g_WindowWidth / 2)) }, point9y{ float(g_WindowHeight / 2) };
	const float point10x{ float(1 / 3.f * outerRadius * cos(14 * angle) + (g_WindowWidth / 2)) }, point10y{ float(1 / 3.f * outerRadius * sin(14 * angle) + (g_WindowHeight / 2)) };
	const float point11x{ float(2 / 3.f * outerRadius * cos(15 * angle) + (g_WindowWidth / 2)) }, point11y{ float(2 / 3.f * outerRadius * sin(15 * angle) + (g_WindowHeight / 2)) };
	const float point12x{ float(1 / 3.f * outerRadius * cos(16 * angle) + (g_WindowWidth / 2)) }, point12y{ float(1 / 3.f * outerRadius * sin(16 * angle) + (g_WindowHeight / 2)) };
	const float point13x{ float(g_WindowWidth / 2) }, point13y{ -outerRadius + (g_WindowHeight / 2) };
	const float point14x{ float(1 / 3.f * outerRadius * cos(20 * angle) + (g_WindowWidth / 2)) }, point14y{ float(1 / 3.f * outerRadius * sin(20 * angle) + (g_WindowHeight / 2)) };
	const float point15x{ float(2 / 3.f * outerRadius * cos(21 * angle) + (g_WindowWidth / 2)) }, point15y{ float(2 / 3.f * outerRadius * sin(21 * angle) + (g_WindowHeight / 2)) };
	const float point16x{ float(1 / 3.f * outerRadius * cos(22 * angle) + (g_WindowWidth / 2)) }, point16y{ float(1 / 3.f * outerRadius * sin(22 * angle) + (g_WindowHeight / 2)) };

	SetColor(1.f, 0.f, 0.f, 1.f);

	DrawLine(point1x, point1y, point2x, point2y);
	DrawLine(point2x, point2y, point3x, point3y);
	DrawLine(point3x, point3y, point4x, point4y);
	DrawLine(point4x, point4y, point5x, point5y);
	DrawLine(point5x, point5y, point6x, point6y);
	DrawLine(point6x, point6y, point7x, point7y);
	DrawLine(point7x, point7y, point8x, point8y);
	DrawLine(point8x, point8y, point9x, point9y);
	DrawLine(point9x, point9y, point10x, point10y);
	DrawLine(point10x, point10y, point11x, point11y);
	DrawLine(point11x, point11y, point12x, point12y);
	DrawLine(point12x, point12y, point13x, point13y);
	DrawLine(point13x, point13y, point14x, point14y);
	DrawLine(point14x, point14y, point15x, point15y);
	DrawLine(point15x, point15y, point16x, point16y);
	DrawLine(point16x, point16y, point1x, point1y);
}