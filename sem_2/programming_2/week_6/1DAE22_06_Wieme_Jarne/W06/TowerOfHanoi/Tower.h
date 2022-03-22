#pragma once

class Disk;

class Tower final
{
public:
	explicit Tower(const Rectf& baseShape, const Rectf& stickShape, const Color4f& color);

	void Draw( ) const;
	void AddDisk(Disk* disk);
	void RemoveDisk(const int index);

private:
	Rectf m_BaseShape;
	Rectf m_StickShape;
	Color4f m_Color;
	std::vector<Disk*> m_Disks;
};