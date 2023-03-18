//-----------------------------------------------------------------
// Main Game File
// C++ Source - EngineDemo.cpp - version v7_01
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "EngineDemo.h"					
#include <fstream>

//-----------------------------------------------------------------
// EngineDemo methods																					
//-----------------------------------------------------------------

ExamProg3Exercise4::ExamProg3Exercise4() 																	
{
	// nothing to create
}

ExamProg3Exercise4::~ExamProg3Exercise4()																						
{
	// nothing to destroy
}


void ExamProg3Exercise4::Initialize(HINSTANCE hInstance)			
{
	// Set the required values
	AbstractGame::Initialize(hInstance);
	GAME_ENGINE->SetTitle(_T("Engine Demo"));					
	GAME_ENGINE->RunGameLoop(true);		
	
	// Set the optional values
	GAME_ENGINE->SetWidth(1024);
	GAME_ENGINE->SetHeight(768);
    GAME_ENGINE->SetFrameRate(50);

	// Set the keys that the project needs to listen to
	//tstringstream buffer;
	//buffer << _T("KLMO");
	//buffer << (TCHAR) VK_LEFT;
	//buffer << (TCHAR) VK_RIGHT;
	//GAME_ENGINE->SetKeyList(buffer.str());
}

void ExamProg3Exercise4::Start()
{
	// Insert the code that needs to be executed at the start of the project
	m_pUniqueButton = std::make_unique<Button>(_TEXT("Unique"));
	m_pUniqueButton->SetBounds(20, 20, 150, 30);
	m_pUniqueButton->Show();
	m_pUniqueButton->AddActionListener(this);

	m_pGreaterButton = std::make_unique<Button>(_TEXT("Greater"));
	m_pGreaterButton->SetBounds(180, 20, 150, 30);
	m_pGreaterButton->Show();
	m_pGreaterButton->AddActionListener(this);

	m_pTextBox = std::make_unique<TextBox>(_TEXT(""));
	m_pTextBox->SetBounds(20, 55, 500, 500);
	m_pTextBox->Show();

	std::string fileName{ "input.txt" };

	std::ifstream inputStream{ fileName };

	int number{};

	if (inputStream)
	{
		while (inputStream)
		{
			inputStream >> number;

			if (inputStream.bad())
			{
				inputStream.clear();
			}
			else
			{
				m_Numbers.push_back(number);
			}
		}
	}
}

void ExamProg3Exercise4::End()
{
	// Insert the code that needs to be executed at the closing of the project
}

void ExamProg3Exercise4::MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the project registers a mouse button action

	/* Example:
	if (isLeft == true && isDown == true) // is it a left mouse click?
	{	
		if ( x > 261 && x < 261 + 117 ) // check if click lies within x coordinates of choice
		{
			if ( y > 182 && y < 182 + 33 ) // check if click also lies within y coordinates of choice
			{
				GAME_ENGINE->MessageBox(_T("Clicked."));
			}
		}
	}
	*/
}


void ExamProg3Exercise4::MouseWheelAction(int x, int y, int distance, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the project registers a mouse wheel action
}

void ExamProg3Exercise4::MouseMove(int x, int y, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the mouse pointer moves across the project window

	/* Example:
	if ( x > 261 && x < 261 + 117 ) // check if mouse position is within x coordinates of choice
	{
		if ( y > 182 && y < 182 + 33 ) // check if mouse position also is within y coordinates of choice
		{
			GAME_ENGINE->MessageBox(_T("Da mouse wuz here."));
		}
	}
	*/
}

void ExamProg3Exercise4::CheckKeyboard()
{	
	// Here you can check if a key of choice is held down
	// Is executed once per frame if the Project Loop is running 

	/* Example:
	if (GAME_ENGINE->IsKeyDown(_T('K'))) xIcon -= xSpeed;
	if (GAME_ENGINE->IsKeyDown(_T('L'))) yIcon += xSpeed;
	if (GAME_ENGINE->IsKeyDown(_T('M'))) xIcon += xSpeed;
	if (GAME_ENGINE->IsKeyDown(_T('O'))) yIcon -= ySpeed;
	*/
}

void ExamProg3Exercise4::KeyPressed(TCHAR cKey)
{	
	// DO NOT FORGET to use SetKeyList() !!

	// Insert the code that needs to be executed when a key of choice is pressed
	// Is executed as soon as the key is released
	// You first need to specify the keys that the research engine needs to watch by using the SetKeyList() method

	/* Example:
	switch (cKey)
	{
	case _T('K'): case VK_LEFT:
		GAME_ENGINE->MessageBox(_T("Moving left."));
		break;
	case _T('L'): case VK_DOWN:
		GAME_ENGINE->MessageBox(_T("Moving down."));
		break;
	case _T('M'): case VK_RIGHT:
		GAME_ENGINE->MessageBox(_T("Moving right."));
		break;
	case _T('O'): case VK_UP:
		GAME_ENGINE->MessageBox(_T("Moving up."));
		break;
	case VK_ESCAPE:
		GAME_ENGINE->MessageBox(_T("Escape menu."));
	}
	*/
}

void ExamProg3Exercise4::Paint(RECT rect)
{
	// Insert paint code 
	GAME_ENGINE->DrawSolidBackground(RGB(191, 191, 191));

	int height_counter{};

	
		//GAME_ENGINE->DrawString(element, 400, 20 + height_counter++ * 30);
	
}

void ExamProg3Exercise4::Tick()
{
	// Insert non-paint code that needs to be executed each tick 
}

void ExamProg3Exercise4::CallAction(Caller* callerPtr)
{
	// Insert the code that needs to be executed when a Caller has to perform an action
	if (callerPtr == m_pUniqueButton.get())
	{
		if (!m_pTextBox->GetText().empty())
		{
			tstringstream buffer;
			buffer << _TEXT("\'") << m_pTextBox->GetText() << _TEXT("\'");

			m_pTextBox->SetText(_TEXT(""));
		}
	}

	if (callerPtr == m_pGreaterButton.get())
	{

	}
}