#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "ArrayApplications- Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Point2f g_MousePos{};

const int g_MaxNumberOfClickedPoints{ 5 };
Point2f g_PointsClicked[g_MaxNumberOfClickedPoints]{};
int g_IndexNextPoint{};
int g_amountOfPointsInPointsClicked{};
const int g_AmountOfPentagrams{ 5 };
struct AngleSpeed
{
	float previousAngle{5*(g_Pi/180)};
	float newAngle{};
	float speed{};
};
AngleSpeed g_AngleSpeedArray[g_AmountOfPentagrams]{};

const int			 g_AmountOfRandomNumbers				{ 6 };
float				 g_AmountOfRandomNumbersCount[g_AmountOfRandomNumbers]{};

const int			 g_AmountOfImages						{ g_AmountOfRandomNumbers };
Texture				 g_ImagesNumbers[g_AmountOfImages]		{};
std::string			 g_NumbersForImage[g_AmountOfImages]	{};
const std::string	 g_FontName								{ "Resources/DIN-Light.otf" };
const int			 g_TextSize								{ 15};
const Color4f		 g_TextColor							{ 186 / 255.f, 186 / 255.f, 0.f, 1.f };

const int			g_AmountOfLastMousePos{ 10 };
int					g_AmountOfLastMousePosInArray{};
Point2f				g_LastMousePosArray[g_AmountOfLastMousePos]{};


Point2f				g_BottomLeftCorner{ 5,5 };
float				g_CellSideLenght{ 35.f };
float			    g_SpaceBetweenCells{ 3.f };
const int			g_AmountOfRows{ 3 };
const int			g_AmountOfColumns{ 4 };
bool				g_CellsSelected[g_AmountOfRows * g_AmountOfColumns]{};
const Color4f		g_SelectedCellColor{ 1.f, 100 / 255.f, 50 / 255.f, 1.f };
// Declare your own functions here
void AddClickedPoint(Point2f mousePos);
void DrawClickedPoints();
void ConnectClickedPoints();

void DrawRotationPentagrams();
void UpdatePentagramsRotation(float elapsedSec);

void UpdateRandStats();
void DrawRandStats();

void AddMousePos(Point2f mousePos);
void DrawMousePoints();

void ToggleCell(const Point2f bottomleftCorner, const float cellSideLenght, const float spaceBetweenCells);
void CheckCellState(int index, Color4f cellColor);
void DrawGrid(const Point2f bottomleftCorner, const float cellSideLenght, const float spaceBetweenCells, const Color4f cellColor = Color4f( 204 / 255.f, 204 / 255.f, 204 / 255.f, 1.f ));
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
