#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "OxoGame - Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Point2f g_BottomLeftCornerOfGrid{ 155, 55 };
const float g_SpaceBetweenCells{ 5.f };
const int g_AmountOfRows{ 3 };
const int g_AmountOfColumns{ 3 };
const int g_AmountOfCells{ g_AmountOfRows * g_AmountOfColumns };

const float g_ScaleFactor{ 1.f };

bool g_LeftPlayerTurn{ true };

Texture g_OxoGrid[g_AmountOfCells]{};

Texture g_LeftPlayerBoxTexture{};
Texture g_RightPlayerBoxTexture{};
Texture g_SelectedTexture{};
Texture g_FreeCell{};
Texture g_GreenO{};
Texture g_GreenX{};
Texture g_WhiteO{};
Texture g_WhiteX{};
Texture g_Win{};
// Declare your own functions here
void CreateOxoTextures();
void DeleteOxoTextures();
void DrawGrid();
void DrawPlayerBoxes(Point2f bottomLeftCornerOfLeftPlayer, Point2f bottomLeftCornerOfRightPlayer);
void SwitchLeftPlayerChoice();
void SwitchRightPlayerChoice();
void PrintGameInfo();
void CheckMousePos(Point2f mousePos);
void ChangeClickedCellTexture(const int rowNumber, const int columnNumber);
void ChangePlayerTurn();
void CheckIfPlayerWon();
void Reset();
int GenerateRandomNumber();
void ChooseRandomStartPlayer();
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
