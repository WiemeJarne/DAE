#include "pch.h"
#include "Box.h"
#include"BouncingCircle.h"

Box::Box(const Rectf boundingRect)
	:m_BoundingRect{ boundingRect }
{
	for (int index{}; index < m_AmountOfCircles; ++index)
	{
		m_PtrCircles[index] = new BouncingCircle{ m_BoundingRect, rand() % 15 + 5.f,
			Point2f{m_BoundingRect.left + m_BoundingRect.width / 2,
			m_BoundingRect.bottom + m_BoundingRect.height / 2} };
	}
}

Box::~Box()
{
	for (int index{}; index < m_AmountOfCircles; ++index)
	{
		delete m_PtrCircles[index];
		m_PtrCircles[index] = nullptr;
	}
}

void Box::Draw()
{
	utils::SetColor(0.f, 0.f, 0.f);
	utils::DrawRect(m_BoundingRect);

	for (int index{}; index < m_AmountOfCircles; ++index)
	{
		m_PtrCircles[index]->DrawCircle();
	}
}

void Box::Update(float elapsedSec)
{
	for (int index{}; index < m_AmountOfCircles; ++index)
	{
		if (m_PtrCircles[index] != nullptr)
		{
			m_PtrCircles[index]->UpdateCircle(elapsedSec);
		}
	}
}
