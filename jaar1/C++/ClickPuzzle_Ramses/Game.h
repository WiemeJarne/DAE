#pragma once
using namespace utils;

#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "ClickPuzzle - Everaert, Ramses - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 420 };
float g_WindowHeight{ 420 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const float g_Margin{82};
Point2f g_MousePos{};

class Tile;

const int g_GridRows{ 2 };
const int g_GridColumns{ 2 };
const int g_AmountOfTiles{ g_GridRows * g_GridColumns };

Tile* g_pTileArr[g_AmountOfTiles]{nullptr};

const int g_TileSize{ 128 };
Rectf g_DstTile[g_AmountOfTiles]{  };

// Declare your own functions here

void CreateTiles();
void DrawTiles();

void CheckActivation(const Point2f& rMousePos);
void CheckHitregions(const Point2f& rMousePos);

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
