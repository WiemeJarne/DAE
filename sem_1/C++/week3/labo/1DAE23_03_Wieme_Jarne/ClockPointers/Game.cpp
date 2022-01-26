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
	DrawClockPointers();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	g_hoekKleineWijzer += float(-(( 2 * M_PI / 240 ) / 12 ));
	g_kleineHoek1KleineWijzer += float(-((2 * M_PI / 240) / 12));
	g_kleineHoek2KleineWijzer += float(-((2 * M_PI / 240) / 12));
	g_hoekGroteWijzer += float(-( 2 * M_PI / 240 ));
	g_kleineHoek1GroteWijzer += float(-(2 * M_PI / 240));
	g_kleineHoek2GroteWijzer += float(-(2 * M_PI / 240));

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

void DrawClockPointers()
{
	float xMiddenScherm = g_WindowWidth / 2;
	float yMiddenscherm = g_WindowHeight / 2;

	int lengteKleineWijzer{ 100 };
	int lengteGroteWijzer{ 200 };

	float xAfstandKleineWijzer = lengteKleineWijzer * cosf(g_hoekKleineWijzer) + xMiddenScherm;
	float yAfstandKleineWijzer = lengteKleineWijzer * sinf(g_hoekKleineWijzer) + yMiddenscherm;
	float xAfstandGroteWijzer = lengteGroteWijzer * cosf(g_hoekGroteWijzer) + xMiddenScherm;
	float yAfstandGroteWijzer = lengteGroteWijzer * sinf(g_hoekGroteWijzer) + yMiddenscherm;

	float xKleineAfstand1KleineWijzer = lengteKleineWijzer / 3 * cosf(g_kleineHoek1KleineWijzer) + xMiddenScherm;
	float yKleineAfstand1KleineWijzer = lengteKleineWijzer / 3 * sinf(g_kleineHoek1KleineWijzer) + yMiddenscherm;
	float xKleineAfstand2KleineWijzer = lengteKleineWijzer / 3 * cosf(g_kleineHoek2KleineWijzer) + xMiddenScherm;
	float yKleineAfstand2KleineWijzer = lengteKleineWijzer / 3 * sinf(g_kleineHoek2KleineWijzer) + yMiddenscherm;

	float xKleineAfstand1GroteWijzer = lengteGroteWijzer / 3 * cosf(g_kleineHoek1GroteWijzer) + xMiddenScherm;
	float yKleineAfstand1GroteWijzer = lengteGroteWijzer / 3 * sinf(g_kleineHoek1GroteWijzer) + yMiddenscherm;
	float xKleineAfstand2GroteWijzer = lengteGroteWijzer / 3 * cosf(g_kleineHoek2GroteWijzer) + xMiddenScherm;
	float yKleineAfstand2GroteWijzer = lengteGroteWijzer / 3 * sinf(g_kleineHoek2GroteWijzer) + xMiddenScherm;
	
	DrawLine(xMiddenScherm, yMiddenscherm, xKleineAfstand1KleineWijzer, yKleineAfstand1KleineWijzer);
	DrawLine(xMiddenScherm, yMiddenscherm, xKleineAfstand2KleineWijzer, yKleineAfstand2KleineWijzer);
	DrawLine(xKleineAfstand1KleineWijzer, yKleineAfstand1KleineWijzer, xAfstandKleineWijzer, yAfstandKleineWijzer);
	DrawLine(xKleineAfstand2KleineWijzer, yKleineAfstand2KleineWijzer, xAfstandKleineWijzer, yAfstandKleineWijzer);

	DrawLine(xMiddenScherm, yMiddenscherm, xKleineAfstand1GroteWijzer, yKleineAfstand1GroteWijzer);
	DrawLine(xMiddenScherm, yMiddenscherm, xKleineAfstand2GroteWijzer, yKleineAfstand2GroteWijzer);
	DrawLine(xKleineAfstand1GroteWijzer, yKleineAfstand1GroteWijzer, xAfstandGroteWijzer, yAfstandGroteWijzer);
	DrawLine(xKleineAfstand2GroteWijzer, yKleineAfstand2GroteWijzer, xAfstandGroteWijzer, yAfstandGroteWijzer);

}