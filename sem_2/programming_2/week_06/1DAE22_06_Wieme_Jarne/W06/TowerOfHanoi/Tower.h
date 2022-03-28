#pragma once
#include <vector>

class Disk;

class Tower final
{
public:
	explicit Tower(const Rectf& shape, const Color4f& color);
	Tower(const Tower& tower) = delete;
	Tower& operator=(const Tower& rhs) = delete;
	~Tower();

	void Draw( ) const;
	void DrawDisks( ) const;
	void AddDisk(const float width, const float height, const Color4f& color);
	void RemoveDisk(const int index);
	Rectf GetShape( ) const;
	void CheckMousePos(const Point2f& mousePos) const;
	void OnMouseMotion(const Point2f& mousePos) const;
	void OnMouseRelease() const;

private:
	Rectf m_BaseShape;
	Rectf m_StickShape;
	Rectf m_Shape;
	Color4f m_Color;
	std::vector<Disk*> m_Disks;
};