#pragma once
#include <vector>
#include "Vector2f.h"

class Level;
class Avatar;
class Sprite;
class EnemyBulletManager;

class Enemy
{
public:
	explicit Enemy(const Point2f& bottomLeftStartPoint, float scale, int health, const Vector2f& velocity, const Vector2f& acceleration, const float distanceFromAvatarWhenAttacking);
	explicit Enemy(const Point2f& bottomLeftStartPoint, float scale, int health);
	Enemy(const Enemy& other) = delete;
	Enemy(Enemy&& other) = delete;
	~Enemy( );

	Enemy& operator=(const Enemy& rhs) = delete;
	Enemy& operator=(Enemy&& rhs) = delete;

	virtual void Update(float elapsedSec, const Level& level, Avatar& avatar);
	virtual void Draw( ) const;
	void Hit(int damage);
	Rectf GetShape( ) const;
	int GetHeath( ) const;

protected:
	Rectf m_Shape;
	Vector2f m_Velocity;
	Vector2f m_Acceleration;
	float m_LeftBoundary;
	float m_RightBoundary;
	const float m_Scale;
	float m_AccuSec;
	int m_Health;
	const int m_StartHealth;
	std::vector<Sprite*> m_pSprites;
	float m_SecondsAftherDeath;
	const Point2f m_StartPos;
	float m_AttackDelay;
	int m_FacingDirection;
	float m_DistanceFromAvatarWhenAttacking;
	EnemyBulletManager* m_pEnemyBulletManager;

	virtual void Attack( );
	void Respawn( );
	bool IsAvatarInAttackZone(const Point2f& avatarPos);
	virtual void CheckActionState(const Avatar& avatar);
	void Moving(const float elapsedSec);
	virtual void ChangeShapeDimensions( );

private:
	enum class ActionState
	{
		moving,
		attacking
	};

	ActionState m_ActionState;	
};