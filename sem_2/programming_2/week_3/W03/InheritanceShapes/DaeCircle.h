#pragma once
#include "Vector2f.h"
#include "DaeEllipse.h"

class DaeCircle : public DaeEllipse
{
public:
	DaeCircle( const Point2f& center, float diameter, const Color4f& color, bool isFilled );

	void Draw( ) const;

private: 
	float m_Diameter;
};