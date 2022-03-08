#pragma once
#include "utils.h"

class DaeShape
{
public:
	DaeShape(const Point2f& center, float width, float height, const Color4f& color);
	virtual ~DaeShape( );

	virtual void Draw( ) const;
	void Translate(const Vector2f& tr);

protected:
	Point2f m_Center;
	float m_Width;
	float m_Height;
	Color4f m_Color;
};