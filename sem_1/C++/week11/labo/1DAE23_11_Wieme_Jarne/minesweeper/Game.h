#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Minesweeper - Wieme, Jarne - Christiaan, Uyterhoeven - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_AmountOfNumberTextures{ 9 };

int g_AmountOfTilesChecked{};

int* g_TilesCheckedArr;
int* g_AmountOfRowsAndColumnsAndMines;
int* g_MineLocations;

float g_ScaleFactor{ 1.f };

Texture g_DefaultTileTexture{};
Texture g_FlagTexture{};
Texture g_MineTexture{};

Texture* g_GridArr;
Texture* g_MineGridArr;
Texture* g_NumbersTexturesArr;

// Declare your own functions here
void CreateNumbersTexturesArr(Texture*& textureArr, const int amountOfTextures);
void CreateTextures();
void DeleteTextures();
//void InitGridArr(Texture*& gridArr, const int size, Texture texture);
void InitArr(int*& gridArr, int number);
void InitArr(Texture*& textureArr, Texture texture);
void DrawGrid(Texture* gridArr, const int amountOfRows, const int amountOfcolumns);
void ClickedOnGrid(Point2f mousePos, Point2f bottomLeftCornerOfGrid);
void reset();
void RevealGrid();
void PrintInfo();
void ToggleTexture(Point2f mousePos, Point2f bottomLeftCornerOfGrid, Texture defaultTexture, Texture textureToToggle);
void ChangeTileTexture(const int tileIndex);
void RandomMinesPosGenerator(Texture*& MineGridArr);
void AskUserInput();

int CheckAdjacentTiles(const int tileIndex);
int CheckMousePos(Point2f mousePos, Point2f bottomLeftCornerOfGrid);
int GenerateRandomNumber(int topBoundary);

bool BInCheckedTilesArr(const int tileToCheck);
bool BCheckIfClickedPosIsMine(const int index);
bool CheckIfPlayerWon();
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
