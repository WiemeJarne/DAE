#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Explosion - Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Point2f g_MousePos{};

const float g_RectAndBombWidth{ 100 };
const float g_RectAndBombHeight{ 100 };

float g_SpaceLeftFromBomb{200};
float g_SpaceBelowBomb{200};

//rectangles from the explosion are numbered from the top left clockwise
const float g_RectandBombWidth{ 100 };

float g_SpaceLeftFromRect1{ g_SpaceLeftFromBomb };
float g_SpaceBelowRect1{ g_SpaceBelowBomb };

float g_SpaceLeftFromRect2{ g_SpaceLeftFromBomb };
float g_SpaceBelowRect2{ g_SpaceBelowBomb };

float g_SpaceLeftFromRect3{ g_SpaceLeftFromBomb };
float g_SpaceBelowRect3{ g_SpaceBelowBomb };

float g_SpaceLeftFromRect4{ g_SpaceLeftFromBomb };
float g_SpaceBelowRect4{ g_SpaceBelowBomb };

bool g_BombsWasClicked{};
bool g_ExplosionIsOver{};

Color4f g_Black{};
Color4f g_TransparentBlack{};
Color4f g_Red{};
// Declare your own functions here
void ProcessMouseClick();
void UpdateExplosion();
void DrawExplosion();
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
