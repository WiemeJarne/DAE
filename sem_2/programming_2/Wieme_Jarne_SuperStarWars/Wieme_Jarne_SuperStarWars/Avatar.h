#pragma once
#include "utils.h"
#include "Bullet.h"
#include <vector>

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
	std::vector<Bullet*>& GetBullets();
	void DeleteBullet(Bullet* bullet);

private:
	enum class ActionState
	{
		waiting = 1,
		walking,
		jumping,
		shoot,
		shootDown,
		shootUp,
		shootUpDiagonal
	};

	const Texture* m_pWalkTexture;
	const Texture* m_pIdleTexture;
	const Texture* m_pJumpTexture;
	const Texture* m_pShootTexture;
	const Texture* m_pShootDownTexture;
	const Texture* m_pShootUpTexture;
	const Texture* m_pShootUpDiagonalTexture;
	float m_ClipHeight;
	float m_ClipWidth;
	const int m_NrOfWalkFrames;
	const int m_NrOfIdleFrames;
	const int m_NrOfJumpFrames;
	const int m_NrOfShootFrames;
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
	int m_AvatarFacingDirection;
	std::vector<Bullet*> m_pBullets;
	float m_ShootDelay;
	float m_BulletVelocity;

	void Moving(float elapsedSec, const Level& level);
	void UpdatePos(float elapsedSec);
	void MoveHorizontal(float elapsedSec);
	void CalculateFrame(float elapsedSec);
	void StayInLevelBoundaries(const Level& level);
	void ChangeClipWidthAndHeight(const Texture* texture, int nrOfFrames);
	void CheckActionState(const Level& level);
	void DrawAvatar() const;
	void Shoot(const Bullet::BulletState& bulletState, const Vector2f& bulletVelocity);
	void DrawBullets() const;
	void UpdateBullets(const float elapsedSec);
	void DeleteBullets();
};

