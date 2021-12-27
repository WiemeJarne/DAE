#pragma once
using namespace utils;
class Tile;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Ex50 - Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 128 * 2 };
float g_WindowHeight{ 128 * 2 + 50 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_AmountOfAnimals{ 6 };

const int g_AmountOfRows{ 2 };
const int g_AmountOfColumns{ 2 };

const int g_AmountOfTiles{ g_AmountOfRows * g_AmountOfColumns };
Tile* g_DynnArrTiles[g_AmountOfTiles];

Texture g_AnimalNames;

Point2f g_MousePos{};
// Declare your own functions here
void CreateTiles();
void CreateTextures();
void DeleteTexturesAndObject();
void PuzzleIsSolved();
bool CheckIfPuzzleIsSolved();
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
