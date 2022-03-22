#pragma once
class Disk final
{
public:
	explicit Disk(const Rectf& Shape, const Color4f& color);

	void Draw(const Point2f& bottomleftPos) const;
	void Move(const Point2f& mousePos);
	Rectf GetShape( ) const;

private:
	Rectf m_Shape;
	const Color4f m_Color;
};