#include "pch.h"
#include "Tower.h"
#include "utils.h"
#include "Disk.h"

Tower::Tower(const Rectf& shape, const Color4f& color)
	:m_Shape{shape}
	,m_Color{color}
{
	m_BaseShape.left = m_Shape.left;
	m_BaseShape.bottom = m_Shape.bottom;
	m_BaseShape.width = m_Shape.width;
	m_BaseShape.height = 20.f;

	m_StickShape.width = 10.f;
	m_StickShape.height = m_Shape.height;
	m_StickShape.left = m_Shape.left + m_Shape.width / 2.f - m_StickShape.width / 2.f;
	m_StickShape.bottom = m_Shape.bottom;
}

Tower::~Tower()
{
	for (Disk* disk : m_Disks)
	{
		if (disk != nullptr)
		{
			delete disk;
		}
	}
}

void Tower::Draw( ) const
{
	utils::SetColor(m_Color);
	utils::FillRect(m_StickShape);

	utils::SetColor(Color4f{ 0.f, 0.f, 0.f, 1.f });
	utils::DrawRect(m_StickShape);

	utils::SetColor(m_Color);
	utils::FillRect(m_BaseShape);

	utils::SetColor(Color4f{ 0.f, 0.f, 0.f, 1.f });
	utils::DrawRect(m_BaseShape);
}

void Tower::DrawDisks() const
{
	Point2f diskPos{ m_BaseShape.left + 10.f, m_BaseShape.bottom + m_BaseShape.height };

	for (Disk* disk : m_Disks)
	{
		if (disk != nullptr)
		{
			if (disk->GetIsSelected() == false)
			{
				disk->SetPosition(diskPos);
			}
			
			disk->Draw();

			diskPos.x += 10.f;
			diskPos.y += disk->GetShape().height;
		}
	}
}

void Tower::AddDisk(const float width, const float height, const Color4f& color)
{
	m_Disks.push_back(new Disk{width, height, color});
}

void Tower::RemoveDisk(const int index)
{
	if (m_Disks[index] != nullptr)
	{
		delete m_Disks[index];
		m_Disks[index] = m_Disks.back();
		m_Disks.pop_back();
	}
}

Rectf Tower::GetShape() const
{
	return m_Shape;
}

void Tower::CheckMousePos(const Point2f& mousePos) const
{
	for (Disk* disk : m_Disks)
	{
		if (disk->IsMousePosInDisk(mousePos))
		{
			disk->SetIsSelected(true);
		}
	}
}

void Tower::OnMouseMotion(const Point2f& mousePos) const
{
	for (Disk* disk : m_Disks)
	{
		if (disk->GetIsSelected())
		{
			disk->Move(mousePos);
		}
	}
}

void Tower::OnMouseRelease() const
{
	for (Disk* disk : m_Disks)
	{
		disk->SetIsSelected(false);
	}
}