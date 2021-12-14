#include "pch.h"
#include "Game.h"
#include "BouncingCircle.h"
#include "Box.h"

//Basic game functions
#pragma region gameFunctions											

void Start()
{
	// initialize game resources here
	/*g_pCircle = new BouncingCircle{ Rectf{50, 50, 200, 200} };

	for (int index{}; index < g_AmountOfcircles; ++index)
	{
		g_PtrManyCircles[index] = new BouncingCircle{ Rectf{50, 50, 200, 200}, rand() % 30 + 10.f, Point2f{float(rand() % int(g_WindowWidth)), float(rand() % int(g_WindowHeight))} };
	}*/

	g_PtrBox1 = new Box{ Rectf{ 10,150,100,100 } };
	g_PtrBox2 = new Box{ Rectf{ 210,150,100,100 } };
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	g_pCircle->DrawCircle();

	for (int index{}; index < g_AmountOfcircles; ++index)
	{
		g_PtrManyCircles[index]->DrawCircle();
	}

	g_PtrBox1->Draw();
	g_PtrBox2->Draw();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	g_pCircle->UpdateCircle(elapsedSec);
	
	for (int index{}; index < g_AmountOfcircles; ++index)
	{
		g_PtrManyCircles[index]->UpdateCircle(elapsedSec);
	}

	g_PtrBox1->Update(elapsedSec);
	g_PtrBox2->Update(elapsedSec);
	//g_pCircle->CheckCollisionCircle();
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
	delete g_pCircle;
	g_pCircle = nullptr;

	for (int index{}; index < g_AmountOfcircles; ++index)
	{
		delete g_PtrManyCircles[index];
		g_PtrManyCircles[index] = nullptr;
	}

	delete g_PtrBox1;
	delete g_PtrBox2;
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