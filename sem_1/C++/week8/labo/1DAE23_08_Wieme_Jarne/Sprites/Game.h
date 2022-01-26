#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Sprites - Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
struct Sprite
{
	Texture texture;
	int frames;
	int amountOfColumns;
	int amountOfRows;
	float frameTime;
	int currentFrame;
	float accumulatedTime;
};
Sprite g_KnightSprite{};
Sprite g_TiboSprite{};

float g_HorizontalKnightPos{};
float g_KnightSpeed{ 100.f };
// Declare your own functions here
void InitKnight();
void InitTibo();
void FreeTextures();
void UpdateKnight(float elapsedSec);
void UpdateTibo(float elapsedSec);
void DrawKnight();
void DrawTibo();
#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
