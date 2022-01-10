#pragma once
class Vehicle;

using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Ex58 - Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_TextSize{ 40 };
const std::string& g_FontPath{ "Resources/consola.ttf" };

bool g_Pause{};

Texture g_StreetTexture{};
const float g_PavementHeight{ 43 };

Texture g_ChickenTexture{};
const Point2f g_ChickenStartPos{ g_WindowWidth / 2, g_WindowHeight - 20 };
Point2f g_ChickenPos{ g_WindowWidth / 2, g_WindowHeight - 20 };
bool g_ChickenSurvived{};
bool g_ChickenIsDead{};

enum class GameState
{
	play,
	pause,
	win,
	lose,
	reset
}; GameState g_GameState{ GameState::reset };

const int g_AmountOfVehicles{ 5 };
Vehicle* g_PtrVehicles[g_AmountOfVehicles]{};

// Declare your own functions here
void PrintGameInfo();
void CreateTextures();
void DeleteTextures();
void DrawStreet(const Point2f& bottomLeftPointStreet);
void DrawChicken();
void ChickenSurvived();
void Reset();
void DrawCars();
void ChickenIsDead();

bool CheckIfChickenIsOnBottomPavement();
bool CheckCollisions();
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
