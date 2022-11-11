#pragma once
#include <vector>
#include <iostream>
#include "framework/EliteMath/EMath.h"
#include "framework\EliteAI\EliteGraphs\ENavGraph.h"
#include "framework\EliteAI\EliteGraphs\EliteGraphAlgorithms\EAStar.h"

namespace Elite
{
	class NavMeshPathfinding
	{
	public:
		static std::vector<Vector2> FindPath(Vector2 startPos, Vector2 endPos, const NavGraph* pNavGraph, std::vector<Vector2>& debugNodePositions, std::vector<Portal>& debugPortals)
		{
			//Create the path to return
			std::vector<Vector2> finalPath{};

			//Get the start and endTriangle
			const Triangle* startTriangle{ pNavGraph->GetNavMeshPolygon()->GetTriangleFromPosition(startPos) };
			const Triangle* endTriangle{ pNavGraph->GetNavMeshPolygon()->GetTriangleFromPosition(endPos) };
		
			//We have valid start/end triangles and they are not the same
			if (startTriangle == nullptr || endTriangle == nullptr) return finalPath;
			if (startTriangle == endTriangle)
			{
				finalPath.push_back(endPos);
				return finalPath;
			}

			//=> Start looking for a path
			//Copy the graph
			const auto graph {pNavGraph->Clone()};
			
			const auto& lines{ pNavGraph->GetNavMeshPolygon()->GetLines() };

			//Create extra node for the Start Node (Agent's position
			const auto& startNode{ new NavGraphNode(graph->GetNextFreeNodeIndex(), -1, startPos) };
			graph->AddNode(startNode );
			for(const auto& lineIndex : startTriangle->metaData.IndexLines)
			{
				const Vector2 lineMiddle{ (lines[lineIndex]->p1 + lines[lineIndex]->p2) / 2.f };
				const auto& node{ graph->GetNodeAtWorldPos(lineMiddle) };
				if(node != nullptr)
				{
					graph->AddConnection(new GraphConnection2D(startNode->GetIndex(), node->GetIndex(), Distance(startPos, node->GetPosition())));
				}
			}

			//Create extra node for the endNode
			const auto& endNode{ new NavGraphNode(graph->GetNextFreeNodeIndex(), -1, endPos) };
			graph->AddNode(endNode);
			for (const auto& lineIndex : endTriangle->metaData.IndexLines)
			{
				const Vector2 lineMiddle{ (lines[lineIndex]->p1 + lines[lineIndex]->p2) / 2.f };
				const auto& node{ graph->GetNodeAtWorldPos(lineMiddle) };
				if (node != nullptr)
				{
					graph->AddConnection(new GraphConnection2D(node->GetIndex(), endNode->GetIndex(), Distance(endPos, node->GetPosition())));
				}
			}

			//Run A star on new graph
			auto pathfinder = AStar<NavGraphNode, GraphConnection2D>(graph.get(), HeuristicFunctions::Chebyshev);

			const auto path{ pathfinder.FindPath(startNode, endNode) };
			for (const auto& node : path)
			{
				finalPath.push_back(node->GetPosition());
			}

			//OPTIONAL BUT ADVICED: Debug Visualisation
			debugNodePositions = finalPath;

			//Run optimiser on new graph, MAKE SURE the A star path is working properly before starting this section and uncommenting this!!!
			//m_Portals = SSFA::FindPortals(nodes, m_pNavGraph->GetNavMeshPolygon());
			//finalPath = SSFA::OptimizePortals(m_Portals);

			return finalPath;
		}
	};
}
