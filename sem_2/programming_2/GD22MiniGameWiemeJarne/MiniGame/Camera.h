#pragma once
class Camera
{
public:
	Camera(float width, float height);

	void SetLevelBoundaries(const Rectf& levelBoundaries);
	void Draw(const Rectf& target) const;

private:
	float m_Width;
	float m_Height;
	Rectf m_LevelBoundaries;

	Point2f Track(const Rectf& target) const;
	void Clamp(Point2f bottomLeftPos) const;
};