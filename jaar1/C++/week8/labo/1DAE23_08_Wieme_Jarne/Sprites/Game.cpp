#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	InitKnight();
	InitTibo();
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawKnight();
	DrawTibo();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	UpdateKnight(elapsedSec);
	UpdateTibo(elapsedSec);
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
	FreeTextures();
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
void InitKnight()
{
	TextureFromFile("Recources/RunningKnight.png", g_KnightSprite.texture);
	g_KnightSprite.amountOfColumns = 8;
	g_KnightSprite.amountOfRows = 1;
	g_KnightSprite.frames = 8;
	g_KnightSprite.currentFrame = 0;
	g_KnightSprite.accumulatedTime = 0.f;
	g_KnightSprite.frameTime = 1 / 10.f;
}

void InitTibo()
{
	TextureFromFile("Recources/Tibo.png", g_TiboSprite.texture);
	g_TiboSprite.amountOfColumns = 5;
	g_TiboSprite.amountOfRows = 5;
	g_TiboSprite.frames = 25;
	g_TiboSprite.currentFrame = 0;
	g_TiboSprite.accumulatedTime = 0.f;
	g_TiboSprite.frameTime = 1 / 15.f;
}

void FreeTextures()
{
	DeleteTexture(g_KnightSprite.texture);
	DeleteTexture(g_TiboSprite.texture);
}

void UpdateKnight(float elapsedSec)
{
	g_KnightSprite.accumulatedTime += elapsedSec;

	if (g_KnightSprite.accumulatedTime > g_KnightSprite.frameTime)
	{
		//determine next frame number
		++g_KnightSprite.currentFrame %= g_KnightSprite.frames;
		g_KnightSprite.accumulatedTime -= g_KnightSprite.frameTime;
	}

	if (g_HorizontalKnightPos > g_WindowWidth)
	{
		g_HorizontalKnightPos = 0 - (g_KnightSprite.texture.width / 2);
	}

	g_HorizontalKnightPos += g_KnightSpeed * elapsedSec;
}

void UpdateTibo(float elapsedSec)
{
	g_TiboSprite.accumulatedTime += elapsedSec;

	if (g_TiboSprite.accumulatedTime < g_TiboSprite.frameTime)
	{
		//determine next frame number
		++g_TiboSprite.currentFrame %= g_TiboSprite.frames;
		g_TiboSprite.accumulatedTime -= g_TiboSprite.frameTime;
	}
}

void DrawKnight()
{
	//part of texture that corresponds with the current frame
	Rectf srcRect{};
	srcRect.width = g_KnightSprite.texture.width / g_KnightSprite.amountOfColumns;
	srcRect.height = g_KnightSprite.texture.height;
	srcRect.left = g_KnightSprite.currentFrame * srcRect.width;
	srcRect.bottom = srcRect.height;

	//draw it at the top of the window
	const float scaleFactor{ 5.f };
	const float border{ 10.f };

	Rectf destRect{};
	destRect.left = g_HorizontalKnightPos;
	destRect.bottom = g_WindowHeight - border - (g_KnightSprite.texture.height * scaleFactor);
	destRect.width = srcRect.width * scaleFactor;
	destRect.height = srcRect.height * scaleFactor;

	DrawTexture(g_KnightSprite.texture, destRect, srcRect);
}

void DrawTibo()
{
	//part of texture that corresponds with the current frame
	Rectf srcRect{};
	srcRect.width = g_TiboSprite.texture.width / g_TiboSprite.amountOfColumns;
	srcRect.height = g_TiboSprite.texture.height / g_TiboSprite.amountOfRows;
	if (g_TiboSprite.currentFrame == 0)
	{
		srcRect.left = srcRect.width;
		srcRect.bottom = srcRect.height;
	}
	else
	{
		srcRect.left = (g_TiboSprite.currentFrame % g_TiboSprite.amountOfColumns) * srcRect.width;
		srcRect.bottom = (g_TiboSprite.currentFrame / g_TiboSprite.amountOfRows + 1) * srcRect.height;
	}
	

	//draw it at the bottom of the window
	const float scaleFactor{ 1.f };
	const float border{ 10.f };

	Rectf destRect{};
	destRect.left = border;
	destRect.bottom = border;
	destRect.width = srcRect.width * scaleFactor;
	destRect.height = srcRect.height * scaleFactor;

	DrawTexture(g_TiboSprite.texture, destRect, srcRect);
}
#pragma endregion ownDefinitions