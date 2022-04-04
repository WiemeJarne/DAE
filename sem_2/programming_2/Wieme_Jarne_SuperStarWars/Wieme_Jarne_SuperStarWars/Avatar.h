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
	Avatar(const Avatar& avatar) = delete;
	Avatar(const Avatar&& avatar) = delete;
	~Avatar();

	Avatar& operator=(const Avatar& rhs) = delete;
	Avatar& operator=(const Avatar&& rhs) = delete;

	void Update(float elapsedSec, const Level& level);
	void Draw() const;
	Rectf GetShape() const;

private:
	enum class ActionState
	{
		idle,
		walking,
		sliding,
		jumping,
		shoot,
		shootDown,
		shootUp,
		shootUpDiagonal,
		jumpShoot,
		jumpShootDown,
		jumpShootUp,
		jumpShootUpDiagonal
	};

	ActionState m_ActionState;
	Rectf m_Shape;
	float m_HorizontalSpeed;
	float m_JumpSpeed;
	Vector2f m_Velocity;
	const Vector2f m_Acceleration;
	int m_FacingDirection;
	BulletManager* m_pBulletManager;
	std::vector<Bullet*> m_pBullets;
	float m_ShootDelay;
	const float m_BulletVelocity;
	std::vector<Sprite*> m_sprites;

	void InitializeSprites( );
	void Moving(float elapsedSec);
	void UpdatePos(float elapsedSec);
	void StayInLevelBoundaries(const Level& level);
	void ChangeShapeDimensions(int nrOfFrames);
	void HandleInput(const Level& level);
	void DrawAvatar() const;
	void Shoot(const Vector2f& bulletVelocity);
	Point2f DetermineBulletPos() const;
};