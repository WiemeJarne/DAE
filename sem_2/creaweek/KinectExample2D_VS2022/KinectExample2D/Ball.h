#pragma once

class Ball final
{
public:
	enum class Type
	{
		neutral,
		danger,
		growHand
	};

	explicit Ball(const Point2f& pos, float radius, float velocityY);

	Ball& operator=(const Ball& rhs);

	void Update(float elapsedSec);
	void Draw( ) const;
	bool IsOverlapping(const Circlef& hand) const;
	bool IsOutOfWindow( ) const;
	Ellipsef GetShape( ) const;
	Type GetType( ) const;

private:
	Ellipsef m_Shape;
	Type m_Type;
	float m_VelocityY;
};