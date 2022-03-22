#include "pch.h"
#include "Tower.h"
#include "utils.h"
#include "Disk.h"

Tower::Tower(const Rectf& baseShape, const Rectf& stickShape, const Color4f& color)
	:m_BaseShape{baseShape}
	,m_StickShape{stickShape}
	,m_Color{color}
{
	//no code
}

void Tower::Draw( ) const
{
	utils::SetColor(m_Color);

	utils::FillRect(m_StickShape);
	utils::FillRect(m_BaseShape);

	Point2f diskPos{m_BaseShape.left + 10.f, m_BaseShape.height};

	for (Disk* disk : m_Disks)
	{
		disk->Draw(diskPos);

		diskPos.y += disk->GetShape().height;
	}
}

void Tower::AddDisk(Disk* disk)
{
	m_Disks.push_back(disk);
}

void Tower::RemoveDisk(const int index)
{
	delete m_Disks[index];
	m_Disks[index] = m_Disks.back( );
	m_Disks.pop_back( );
}