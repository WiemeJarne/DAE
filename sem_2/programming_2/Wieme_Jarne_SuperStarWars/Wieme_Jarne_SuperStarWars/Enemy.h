#pragma once
#include <vector>
#include "Vector2f.h"

class Level;
class Avatar;
class Sprite;

class Enemy
{
public:
	explicit Enemy(const Point2f& bottomLeftStartPoint, float scale, int health, const Vector2f& velocity, const Vector2f& acceleration, const float distanceFromAvatarWhenAttacking);
	
	virtual ~Enemy( );
	Enemy(const Enemy& other) = delete;
	Enemy& operator=(const Enemy& rhs) = delete;
	Enemy(Enemy&& other) = delete;
	Enemy& operator=(Enemy&& rhs) = delete;

	virtual void Update(float elapsedSec, const Level& level, const Avatar& avatar) = 0;
	virtual void Draw( ) const;
	void Hit(int damage);
	Rectf GetShape( ) const;
	int GetHeath( ) const;

protected:
	Rectf m_Shape;
	const Point2f m_StartPos;
	const float m_Scale;
	int m_Health;
	const int m_StartHealth;
	Vector2f m_Velocity;
	Vector2f m_Acceleration;
	float m_DistanceFromAvatarWhenAttacking;
	float m_AccuSec;
	float m_SecondsAftherDeath;
	float m_SecondsAfterAttack;
	int m_FacingDirection;
	float m_LeftBoundary;
	float m_RightBoundary;
	std::vector<Sprite*> m_pSprites;

	void Respawn( );
	bool IsAvatarInAttackZone(const Point2f& avatarPos);
	void Moving(float elapsedSec);
	virtual void CheckActionState(const Avatar& avatar) = 0;
	virtual void ChangeShapeDimensions( ) = 0;
};