#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Minesweeper - Wieme, Jarne - Christiaan, Uyterhoeven - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 200 };
float g_WindowHeight{ 200 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_AmountOfNumberTextures{ 8 };
const float g_ScaleFactor{ 25 / 20 };

Texture* g_NumbersTexturesArr;

const int g_AmountOfRows{ 10 };
const int g_AmountOfColumns{ 10 };
int* g_TilesCheckedArr;
Texture* g_GridArr;
Texture* g_MineGridArr;

Texture g_DefaultTileTexture{};
Texture g_TilePressedTexture{};
Texture g_FlagTexture{};
Texture g_MineTexture{};
// Declare your own functions here
void CreateNumbersTexturesArr(Texture*& textureArr, const int amountOfTextures);
void CreateTextures();
void DeleteTextures();
void InitGridArr(Texture*& gridArr, const int amountOfRows, const int amountOfColumns, Texture texture);
void InitGridArr(int*& gridArr, const int amountOfRows, const int amountOfColumns, Texture texture);
void DrawGrid(Texture* gridArr, const int amountOfRows, const int amountOfColumns);
void CheckMousePos(Point2f mousePos, Point2f bottomLeftCornerOfGrid);
int CheckAdjacentTiles(const int tileIndex);
void ChangeTileTexture(const int rowNumber, const int columnNumber);
void RandomMinesPosGenerator(Texture*& MineGridArr, const int amountOfRows, const int amountOfColumns, const int amountOfMines = 10);
bool BInCheckedTilesArr(const int tileToCheck);
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