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
	const int index{ PositionToIndex(agent->GetPosition()) };
	m_Cells[index].agents.push_back(agent);
}

void CellSpace::UpdateAgentCell(SteeringAgent* agent, Elite::Vector2 oldPos)
{
	const int newIndex{ PositionToIndex(agent->GetPosition()) };
	const int previousIndex{ PositionToIndex(oldPos) };

	if(newIndex != previousIndex)
	{
		for(const SteeringAgent* otherAgent : m_Cells[previousIndex].agents)
		{
			if(otherAgent == agent)
			{
				m_Cells[previousIndex].agents.remove(agent);
			}
		}
		m_Cells[newIndex].agents.push_back(agent);
	}
}

void CellSpace::RegisterNeighbors(SteeringAgent* agent, float queryRadius)
{
	m_NrOfNeighbors = 0;
	const int agentCellIndex{ PositionToIndex(agent->GetPosition()) };

	Elite::Rect agentBoundingBox{};
	agentBoundingBox.bottomLeft.x = agent->GetPosition().x - queryRadius;
	agentBoundingBox.bottomLeft.y = agent->GetPosition().y - queryRadius;
	agentBoundingBox.width = queryRadius * 2;
	agentBoundingBox.height = queryRadius * 2;

	int topAndBottomLeftCellColNr = static_cast<int>(agentBoundingBox.bottomLeft.x / m_CellWidth);
	int topLeftAndRightCellRowNr = static_cast<int>((agentBoundingBox.bottomLeft.y + agentBoundingBox.height) / m_CellHeight);
	int topAndBottomRightCellColNr = static_cast<int>((agentBoundingBox.bottomLeft.x + agentBoundingBox.width) / m_CellWidth);
	int bottomLeftAndRightCellRowNr = static_cast<int>(agentBoundingBox.bottomLeft.y / m_CellHeight);

	if (topAndBottomLeftCellColNr < 0)
	{
		topAndBottomLeftCellColNr = 0;
	}

	if(topLeftAndRightCellRowNr > m_NrOfRows)
	{
		topLeftAndRightCellRowNr = m_NrOfRows;
	}

	if(topAndBottomRightCellColNr > m_NrOfCols)
	{
		topAndBottomRightCellColNr = m_NrOfCols;
	}

	if(bottomLeftAndRightCellRowNr < 0)
	{
		bottomLeftAndRightCellRowNr = 0;
	}

	for (int rowNr{ bottomLeftAndRightCellRowNr }; rowNr < topLeftAndRightCellRowNr; ++rowNr)
	{
		for (int colNr{ topAndBottomLeftCellColNr }; colNr < topAndBottomRightCellColNr; ++colNr)
		{
			for (SteeringAgent* otherAgent : m_Cells[rowNr * m_NrOfCols + colNr].agents)
			{
				if (otherAgent != agent)
				{
					if ((otherAgent->GetPosition() - agent->GetPosition()).Magnitude() <= queryRadius)
					{
						m_Neighbors[m_NrOfNeighbors] = otherAgent;
						if(agent->CanRenderBehavior())
						{
							DEBUGRENDERER2D->DrawCircle(otherAgent->GetPosition(), otherAgent->GetRadius() + 1, { 0.f, 1.f, 0.f }, 0);
						}
						++m_NrOfNeighbors;
					}
				}
			}
		}
	}
	
	if (agent->CanRenderBehavior())
	{
		const std::vector<Elite::Vector2> points{ agentBoundingBox.bottomLeft,
			Elite::Vector2{agentBoundingBox.bottomLeft.x + agentBoundingBox.width, agentBoundingBox.bottomLeft.y},
			Elite::Vector2{agentBoundingBox.bottomLeft.x + agentBoundingBox.width, agentBoundingBox.bottomLeft.y + agentBoundingBox.height},
			Elite::Vector2{agentBoundingBox.bottomLeft.x, agentBoundingBox.bottomLeft.y + agentBoundingBox.height} };

		const auto polygon = new Elite::Polygon{ points };
		DEBUGRENDERER2D->DrawPolygon(polygon, { 1.f, 1.f, 1.f }, 0.f);
		delete polygon;
		DEBUGRENDERER2D->DrawCircle(agent->GetPosition(), queryRadius, { 1.f, 1.f, 1.f }, -1.f);
	}
}

void CellSpace::EmptyCells()
{
	for (Cell& c : m_Cells)
		c.agents.clear();
}

void CellSpace::RenderCells() const
{
	Elite::Vector2 textPos{ 0, m_CellHeight };
	for (size_t index{}; index < m_Cells.size(); ++index)
	{
		Elite::Polygon* polygon{ new Elite::Polygon(m_Cells[index].GetRectPoints()) };
		DEBUGRENDERER2D->DrawPolygon(polygon, { 1.f, 0.f, 0.f });
		delete polygon;

		const int amountOfAgentsInCell{ static_cast<int>(m_Cells[index].agents.size()) };
		DEBUGRENDERER2D->DrawString( textPos, std::to_string(amountOfAgentsInCell).c_str());
		textPos.x += m_CellWidth;
		if((index + 1) % m_NrOfCols == 0 && index != 0)
		{
			textPos.x = 0;
			textPos.y += m_CellHeight;
		}
	}
}

int CellSpace::PositionToIndex(const Elite::Vector2 pos) const
{
	for (size_t index{}; index < m_Cells.size(); ++index)
	{
		const Elite::Rect boundingBox{ m_Cells[index].boundingBox };

		if (pos.x >= boundingBox.bottomLeft.x && pos.x <= boundingBox.bottomLeft.x + m_CellWidth
			&& pos.y >= boundingBox.bottomLeft.y && pos.y <= boundingBox.bottomLeft.y + m_CellHeight)
		{
			return static_cast<int>(index);
		}
	}
	return 0;
}