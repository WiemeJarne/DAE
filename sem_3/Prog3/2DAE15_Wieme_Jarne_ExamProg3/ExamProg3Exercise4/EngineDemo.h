//-----------------------------------------------------------------
// Main Game  File
// C++ Header - EngineDemo.h - version v7_01					
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "Resource.h"	
#include "GameEngine.h"
#include "AbstractGame.h"

//-----------------------------------------------------------------
// EngineDemo Class																
//-----------------------------------------------------------------
class ExamProg3Exercise4 : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	ExamProg3Exercise4();

	virtual ~ExamProg3Exercise4();

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	ExamProg3Exercise4(const ExamProg3Exercise4& other) = delete;
	ExamProg3Exercise4(ExamProg3Exercise4&& other) noexcept = delete;
	ExamProg3Exercise4& operator=(const ExamProg3Exercise4& other) = delete;
	ExamProg3Exercise4& operator=(ExamProg3Exercise4&& other) noexcept = delete;

	//---------------------------
	// General Methods
	//---------------------------
	void Initialize(HINSTANCE hInstance) override;
	void Start() override;
	void End() override;
	void MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam) override;
	void MouseWheelAction(int x, int y, int distance, WPARAM wParam) override;
	void MouseMove(int x, int y, WPARAM wParam) override;
	void CheckKeyboard() override;
	void KeyPressed(TCHAR cKey) override;
	void Paint(RECT rect) override;
	void Tick() override;
	
	void CallAction(Caller* callerPtr) override;

private:
	// -------------------------
	// Datamembers
	// -------------------------

	std::unique_ptr<Button> m_pUniqueButton{};
	std::unique_ptr<Button> m_pGreaterButton{};
	std::unique_ptr<TextBox> m_pTextBox{};
	std::vector<int> m_Numbers{};
};
