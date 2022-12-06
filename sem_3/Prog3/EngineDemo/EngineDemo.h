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
class EngineDemo : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	EngineDemo();

	virtual ~EngineDemo();

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	EngineDemo(const EngineDemo& other) = delete;
	EngineDemo(EngineDemo&& other) noexcept = delete;
	EngineDemo& operator=(const EngineDemo& other) = delete;
	EngineDemo& operator=(EngineDemo&& other) noexcept = delete;

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

	std::unique_ptr<Button> m_pMainButton{};
	std::unique_ptr<TextBox> m_pTextBox{};
	std::vector<tstring> m_Strings{};
};
