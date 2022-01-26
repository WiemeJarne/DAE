#pragma once
#include "structs.h"

class DaeEllipse
{
public:
	DaeEllipse(const Point2f& center, float radX, float radY, const Color4f& fillcolor);
	
	void Draw();
	void ActivateTests(const Point2f& pos);

private:
	float GetArea();

	Point2f m_Center;
	float m_RadX;
	float m_RadY;
	float m_Area;
	Color4f m_FillColor;
	bool m_IsActive;
};