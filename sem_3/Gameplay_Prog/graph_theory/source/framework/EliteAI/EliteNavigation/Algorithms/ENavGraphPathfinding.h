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
		static std::vector<Vector2> FindPath(Vector2 startPos, Vector2 endPos, NavGraph* pNavGraph, std::vector<Vector2>& debugNodePositions, std::vector<Portal>& debugPortals)
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
			auto graph {pNavGraph->Clone()};
			
			//Create extra node for the Start Node (Agent's position
			graph->AddNode(new NavGraphNode( graph->GetNextFreeNodeIndex(), startPos ));

			//Create extra node for the endNode
			graph->AddNode(new NavGraphNode( graph->GetNextFreeNodeIndex(), endPos ));
			
			//Run A star on new graph
			auto pathfinder = AStar<NavGraphNode, GraphConnection2D>(graph.get(), Elite::HeuristicFunctions::Chebyshev);
			auto startNode = graph->GetNode(graph->GetNodeIdxAtWorldPos(startPos));
			auto endNode = graph->GetNode(graph->GetNodeIdxAtWorldPos(endPos));

			auto path{ pathfinder.FindPath(startNode, endNode) };
			for (auto& node : path)
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
