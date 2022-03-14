#pragma once
class Texture;

class Diamond
{
public:
	Diamond(const Point2f& position);

	void Draw() const;
	void GetIsSelected() const;

	void SetIsSelected( const bool selected);
	void SetPosition(const Point2f& position);
	void SetAngle(const float angle);
	void SetScale(const float scale);
	void ResetTransformations();

	static Texture* m_DiamondTexture;

private:
	Point2f m_Position;
	float m_Angle;
	float m_Scale;
	bool m_IsSelected;
};