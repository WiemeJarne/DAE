#pragma once
class Camera final
{
public:
	Camera(float width, float height);

	void SetLevelBoundaries(const Rectf& levelBoundaries);
	void Transform(const Rectf& target, float scale, Point2f& translation) const;

private:
	Point2f m_BottomLeftPoint;
	float m_Width;
	float m_Height;
	Rectf m_LevelBoundaries;

	Point2f Track(const Rectf& target, float scale) const;
	void Clamp(Point2f& bottomLeftPos, float scale) const;
};