#pragma once
#include "utils.h"
#include "Bullet.h"
#include <vector>

class Level;
class Texture;
class BulletManager;
class Sprite;

class Avatar final
{
public:
	explicit Avatar();

	~Avatar();
	Avatar(const Avatar& avatar) = delete;
	Avatar& operator=(const Avatar& rhs) = delete;
	Avatar(const Avatar&& avatar) = delete;
	Avatar& operator=(const Avatar&& rhs) = delete;

	void Update(float elapsedSec, const Level& level);
	void Draw() const;
	Rectf GetShape() const;

private:
	enum class ActionState
	{
		idle = 1,
		walking,
		sliding,
		jumping,
		shoot,
		shootDown,
		shootUp,
		shootUpDiagonal
	};

	std::vector<Sprite*> m_sprites;
	ActionState m_ActionState;
	const int m_NrOfIdleFrames;
	const int m_NrOfWalkFrames;
	const int m_NrOfSlideFrames;
	const int m_NrOfJumpFrames;
	const int m_NrOfShootFrames;
	float m_ClipHeight;
	float m_ClipWidth;
	int m_NrFramesPerSec;
	float m_AnimTime;
	int m_AnimFrame;
	Rectf m_Shape;
	float m_HorizontalSpeed;
	float m_JumpSpeed;
	Vector2f m_Velocity;
	Vector2f m_Acceleration;
	int m_Power;
	int m_IdleFrameDirection;
	int m_AvatarFacingDirection;
	std::vector<Bullet*> m_pBullets;
	float m_ShootDelay;
	float m_BulletVelocity;
	BulletManager* m_pBulletManager;

	void InitializeSprites( );
	void Moving(float elapsedSec, const Level& level);
	void UpdatePos(float elapsedSec);
	void MoveHorizontal(float elapsedSec);
	void CalculateFrame(float elapsedSec);
	void StayInLevelBoundaries(const Level& level);
	void ChangeClipWidthAndHeight(int nrOfFrames);
	void CheckActionState(const Level& level);
	void DrawAvatar() const;
	void Shoot(const Vector2f& bulletVelocity);
};

