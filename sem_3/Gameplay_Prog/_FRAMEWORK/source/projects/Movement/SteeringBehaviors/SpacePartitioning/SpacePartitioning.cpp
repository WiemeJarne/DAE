#include "stdafx.h"
#include "SpacePartitioning.h"
#include "projects\Movement\SteeringBehaviors\SteeringAgent.h"

// --- Cell ---
// ------------
Cell::Cell(float left, float bottom, float width, float height)
{
	boundingBox.bottomLeft = { left, bottom };
	boundingBox.width = width;
	boundingBox.height = height;
}

std::vector<Elite::Vector2> Cell::GetRectPoints() const
{
	auto left = boundingBox.bottomLeft.x;
	auto bottom = boundingBox.bottomLeft.y;
	auto width = boundingBox.width;
	auto height = boundingBox.height;

	std::vector<Elite::Vector2> rectPoints =
	{
		{ left , bottom  },
		{ left , bottom + height  },
		{ left + width , bottom + height },
		{ left + width , bottom  },
	};

	return rectPoints;
}

// --- Partitioned Space ---
// -------------------------
CellSpace::CellSpace(float width, float height, int rows, int cols, int maxEntities)
	: m_SpaceWidth(width)
	, m_SpaceHeight(height)
	, m_NrOfRows(rows)
	, m_NrOfCols(cols)
	, m_Neighbors(maxEntities)
	, m_NrOfNeighbors(0)
	, m_CellWidth(width / cols)
	, m_CellHeight(height / rows)
{
	float left{};
	float bottom{};

	for (int rowNr{}; rowNr < rows; ++rowNr)
	{
		for (int colNr{}; colNr < cols; ++colNr)
		{
			m_Cells.push_back(Cell(left, bottom, m_CellWidth, m_CellHeight));
			left += m_CellWidth;
		}
		left = 0.f;
		bottom += m_CellHeight;
	}
}

void CellSpace::AddAgent(SteeringAgent* agent)
{
	
}

void CellSpace::UpdateAgentCell(SteeringAgent* agent, Elite::Vector2 oldPos)
{
	
}

void CellSpace::RegisterNeighbors(SteeringAgent* agent, float queryRadius)
{
	
}

void CellSpace::EmptyCells()
{
	for (Cell& c : m_Cells)
		c.agents.clear();
}

void CellSpace::RenderCells() const
{
	for (size_t index{}; index < m_Cells.size(); ++index)
	{
		Elite::Polygon* polygon{ new Elite::Polygon(m_Cells[index].GetRectPoints()) };
		DEBUGRENDERER2D->DrawPolygon(polygon, { 1.f, 0.f, 0.f });
		delete polygon;
	}
}

int CellSpace::PositionToIndex(const Elite::Vector2 pos) const
{
	for (size_t index{}; index < m_Cells.size(); ++index)
	{
		Elite::Rect boundingBox{ m_Cells[index].boundingBox };

		if (pos.x > boundingBox.bottomLeft.x && pos.x < boundingBox.bottomLeft.x + m_CellWidth
			&& pos.y > boundingBox.bottomLeft.y && pos.y < boundingBox.bottomLeft.y + m_CellHeight)
		{
			return index;
		}
	}
	return -1;
}