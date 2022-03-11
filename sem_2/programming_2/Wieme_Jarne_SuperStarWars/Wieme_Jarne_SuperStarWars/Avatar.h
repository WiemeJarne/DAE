#pragma once
#include "utils.h"

class Level;
class Texture;

class Avatar
{
public:
	Avatar();
	~Avatar();

	void Update(float elapsedSec, const Level& level);
	void Draw() const;
	Rectf GetShape() const;

private:
	enum class ActionState
	{
		waiting = 1,
		walking,
		jumping
	};

	Texture* m_pWalkTexture;
	Texture* m_pIdleTexture;
	Texture* m_pJumpTexture;
	float m_ClipHeight;
	float m_ClipWidth;
	int m_NrOfWalkFrames;
	int m_NrOfIdleFrames;
	int m_NrOfJumpFrames;
	int m_NrFramesPerSec;
	float m_AnimTime;
	int m_AnimFrame;
	Rectf m_Shape;
	float m_HorizontalSpeed;
	float m_JumpSpeed;
	Vector2f m_Velocity;
	Vector2f m_Acceleration;
	ActionState m_ActionState;
	int m_Power;
	int m_FrameDirection;

	void Moving(float elapsedSec, const Level& level);
	void UpdatePos(float elapsedSec);
	void MoveHorizontal(float elapsedSec);
	void CalculateFrame(float elapsedSec);
	void StayInLevelBoundaries(const Level& level);
	void ChangeClipWidthAndHeight(const Texture* texture, int nrOfFrames);
	void CheckActionState(const Level& level);
	void CheckAndChangeWalkDirection() const;
	void DrawAvatar() const;
};

