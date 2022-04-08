#pragma once
#include "Vector2f.h"
#include <vector>

class Level;
class Texture;
class Sprite;
class EnemyBulletManager;
class Avatar;

class Enemy final
{
public:
	explicit Enemy(const Point2f& bottomLeftStartPoint, float scale, int health);
	Enemy(const Enemy& other) = delete;
	Enemy(Enemy&& other) = delete;
	~Enemy( );

	Enemy& operator=(const Enemy& rhs) = delete;
	Enemy& operator=(Enemy&& rhs) = delete;

	void Update(float elapsedSec, const Level& level, Avatar& avatar);
	void Draw( ) const;
	void Hit( );
	Rectf GetShape( ) const;
	int GetHeath( ) const;

private:
	enum class ActionState
	{
		walking,
		attacking
	};

	ActionState m_ActionState;
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
	float m_RespawnDelay;
	const Point2f m_StartPos;
	EnemyBulletManager* m_pEnemyBulletManager;
	float m_ShootDelay;
	int m_FacingDirection;

	void Shoot( );
};