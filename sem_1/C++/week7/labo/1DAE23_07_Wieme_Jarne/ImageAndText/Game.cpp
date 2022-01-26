#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	if ( !TextureFromFile("Resources/DAE.png", g_ImgDAELogo) )
	{
		std::cout << "File not found.";
	}

	bool isTextImageLoaded{ TextureFromString(g_TextForImage, g_FontName, g_TextSize, g_TextColor, g_ImgText) };

	if (isTextImageLoaded == false)
	{
		std::cout << "Promblem generating image from text.";
	}
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	
<<<<<<< HEAD
	const float scaleFactor{ 2.0f };
	DrawTexture(g_ImgDAELogo, Point2f(10, 10) , g_DAESourceRectangle);
	//DrawTexture(g_ImgDAELogo,	Rectf{ 30, 10, g_ImgDAELogo.width * scaleFactor, g_ImgDAELogo.height * scaleFactor } );
=======
	const float scaleFactor{ 1.0f };
	DrawTexture(g_ImgDAELogo,	Rectf{ 30, 10, g_ImgDAELogo.width * scaleFactor, g_ImgDAELogo.height * scaleFactor } );
>>>>>>> d8f5aafeafdb3e0b2a218d90a982a20da3bd197b
	DrawTexture(g_ImgText,		Point2f{ 10,200 } );
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