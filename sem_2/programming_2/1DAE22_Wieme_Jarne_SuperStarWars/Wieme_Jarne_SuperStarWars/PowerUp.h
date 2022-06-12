#pragma once
#include "Vector2f.h"

class Level;
class Texture;

class PowerUp final
{
public:
	enum class Type
	{
		heart,
		blaster
	};

	explicit PowerUp(const Point2f& bottomLeftPos, Type powerUpType);

	~PowerUp( );
	PowerUp(const PowerUp& powerUp) = delete;
	PowerUp& operator=(const PowerUp& rhs) = delete;
	PowerUp(PowerUp&& powerUp) = delete;
	PowerUp& operator=(PowerUp&& rhs) = delete;

	void Update(float elapsedSec, const Level& level);
	void Draw( ) const;
	bool IsOverlapping(const Rectf& rect) const;
	Type GetPowerUpType( ) const;

private:
	const Texture* m_pTexture;
	Rectf m_Shape;
	Vector2f m_Acceleration;
	Vector2f m_Velocity;
	Type m_Type;
};