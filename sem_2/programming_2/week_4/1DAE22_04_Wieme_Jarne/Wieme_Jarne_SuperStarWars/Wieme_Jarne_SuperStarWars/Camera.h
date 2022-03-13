#pragma once
class Camera
{
public:
	Camera(float width, float height);

	void SetLevelBoundaries(const Rectf& levelBoundaries);
	void Transform(const Rectf& target, const float scaleFactor) const;

private:
	float m_Width;
	float m_Height;
	Rectf m_LevelBoundaries;

	Point2f Track(const Rectf& target, const float scaleFactor) const;
	void Clamp(Point2f& bottomLeftPos) const;
};