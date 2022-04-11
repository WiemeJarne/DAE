#pragma once
#include <vector>
#include "Vector2f.h"

class Level;
class Enemy;
class BulletManager;
class Sprite;

class Avatar final
{
public:
	explicit Avatar();
	Avatar(const Avatar& avatar) = delete;
	Avatar(Avatar&& avatar) = delete;
	~Avatar( );

	Avatar& operator=(const Avatar& rhs) = delete;
	Avatar& operator=(Avatar&& rhs) = delete;

	void Update(float elapsedSec, const Level& level, std::vector<Enemy*> enemies);
	void Draw( ) const;
	void Hit( );
	void PowerupHit( );
	Rectf GetShape( ) const;

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
		jumpShootUpDiagonal,
		dead
	};

	ActionState m_ActionState;
	Rectf m_Shape;
	const float m_HorizontalSpeed;
	const float m_JumpSpeed;
	Vector2f m_Velocity;
	const Vector2f m_Acceleration;
	int m_FacingDirection;
	BulletManager* m_pBulletManager;
	float m_ShootDelay;
	const float m_BulletVelocity;
	std::vector<Sprite*> m_sprites;
	int m_Health;
	const int m_StartHealth;
	float m_AccuHitSec;
	bool m_BlasterPowerUpHit;

	void InitializeSprites( );
	void Moving(float elapsedSec);
	void UpdatePos(float elapsedSec);
	void StayInLevelBoundaries(const Level& level);
	void ChangeShapeDimensions(int nrOfFrames);
	void HandleInput(const Level& level);
	void DrawAvatar( ) const;
	void Shoot(const Vector2f& bulletVelocity);
	Point2f DetermineBulletPos() const;
	void HandleCollision(std::vector<Enemy*> enemies);
};