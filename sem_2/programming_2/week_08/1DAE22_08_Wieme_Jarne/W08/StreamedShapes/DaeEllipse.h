#pragma once
#include "Vector2f.h"
#include "DaeShape.h"

class DaeEllipse : public DaeShape
{
public:
	DaeEllipse( const Point2f& center, float width, float height, const Color4f& color, bool isFilled );

	virtual void Draw( ) const override;
	virtual std::string ToString( ) const override;

protected: 
	bool m_IsFilled;
};