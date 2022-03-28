#pragma once
class Disk final
{
public:
	explicit Disk(const float width, const float height, const Color4f& color);

	void Draw( ) const;
	void Move(const Point2f& mousePos);
	void SetPosition(const Point2f& position);
	Rectf GetShape( ) const;
	bool IsMousePosInDisk(const Point2f& mousePos);
	void SetIsSelected(bool isSelected);
	bool GetIsSelected( ) const;

private:
	Rectf m_Shape;
	const Color4f m_Color;
	bool m_IsSelected;
};