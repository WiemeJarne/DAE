#include "stdafx.h"
#include "TestScene.h"

#include "Logger.h"

void TestScene::Initialize()
{

}

void TestScene::Update()
{

}

void TestScene::Draw() const
{

}

void TestScene::OnSceneActivated()
{
	Logger::GetInstance()->LogFormat(LogLevel::Info, L"Scene Activated > \"%ls\"", GetName().c_str());
}

void TestScene::OnSceneDeactivated()
{
}
