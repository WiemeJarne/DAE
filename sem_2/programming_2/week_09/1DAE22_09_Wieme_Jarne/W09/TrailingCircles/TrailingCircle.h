#pragma once
#include "Vector2f.h"
#include <deque>

class TrailingCircle
{
public:
	TrailingCircle( float radius, const Point2f& center);
	void Update( float elapsedSec, const Rectf& boundingRect );
	void Draw( ) const;

private:
	const float m_Radius;
	const Color4f m_Color;
	Point2f m_Center;
	Vector2f m_Velocity;
	std::deque<Point2f> m_Trail;
	float m_AccumTime;

	Vector2f GetRandomVelocity( );
	Color4f GetRandomColor( );
	
	template <typename T>
	T Lerp(T min, T max, double alpha) const;
};

template <typename T>
T TrailingCircle::Lerp(T min, T max, double alpha) const
{
	return static_cast<T>((1 - alpha) * min + alpha * max);
}