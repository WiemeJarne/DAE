#pragma once
#include <vector>
#include "Vector2f.h"

class Texture;

class Diamond
{
public:
	Diamond(const Point2f& position);
	~Diamond();

	void Draw() const;
	bool GetIsSelected() const;
	Point2f GetPosition() const;
	float GetAngle() const;
	float GetScale() const;

	void SetIsSelected( const bool selected);
	void SetPosition(const Vector2f& position);
	void SetAngle(const float angle);
	void SetScale(const float scale);
	void Reset();
	bool IsPointInDiamond(const Point2f& point);

private:
	Texture* m_DiamondTexture;
	const Point2f m_StartPos;
	std::vector<Point2f> m_Vertices;
	Vector2f m_Position;
	float m_Angle;
	float m_Scale;
	bool m_IsSelected;
	
	std::vector<Point2f> CalculateTransformedDiamond() const;
};