#include "stdafx.h"
#include "Flock.h"

#include "../SteeringAgent.h"
#include "../Steering/SteeringBehaviors.h"
#include "../CombinedSteering/CombinedSteeringBehaviors.h"

using namespace Elite;

//Constructor & Destructor
Flock::Flock(
	int flockSize /*= 50*/, 
	float worldSize /*= 100.f*/, 
	SteeringAgent* pAgentToEvade /*= nullptr*/, 
	bool trimWorld /*= false*/)

	: m_WorldSize{ worldSize }
	, m_FlockSize{ flockSize }
	, m_TrimWorld { trimWorld }
	, m_pAgentToEvade{pAgentToEvade}
	, m_NeighborhoodRadius{ 15 }
	, m_NrOfNeighbors{0}
{
	m_Agents.resize(m_FlockSize);

	// TODO: initialize the flock and the memory pool
	for (int index{}; index < m_Agents.size(); ++index)
	{
		m_Agents[index] = new SteeringAgent();
	}
}

Flock::~Flock()
{
	// TODO: clean up any additional data

	SAFE_DELETE(m_pBlendedSteering);
	SAFE_DELETE(m_pPrioritySteering);

	for(auto pAgent: m_Agents)
	{
		SAFE_DELETE(pAgent);
	}
	m_Agents.clear();
}

void Flock::Update(float deltaT)
{
	// TODO: update the flock
	// loop over all the agents
		// register its neighbors	(-> memory pool is filled with neighbors of the currently evaluated agent)
		// update it				(-> the behaviors can use the neighbors stored in the pool, next iteration they will be the next agent's neighbors)
		// trim it to the world
	for (int index{}; index < m_Agents.size(); ++index)
	{
		RegisterNeighbors(m_Agents[index]);
		m_Agents[index]->Update(deltaT);
		m_Agents[index]->TrimToWorld(m_WorldSize);
	}
}

void Flock::Render(float deltaT)
{
	// TODO: render the flock
	for (int index{}; index < m_Agents.size(); ++index)
	{
		m_Agents[index]->Render(deltaT);
	}
}

void Flock::UpdateAndRenderUI()
{
	//Setup
	int menuWidth = 235;
	int const width = DEBUGRENDERER2D->GetActiveCamera()->GetWidth();
	int const height = DEBUGRENDERER2D->GetActiveCamera()->GetHeight();
	bool windowActive = true;
	ImGui::SetNextWindowPos(ImVec2((float)width - menuWidth - 10, 10));
	ImGui::SetNextWindowSize(ImVec2((float)menuWidth, (float)height - 20));
	ImGui::Begin("Gameplay Programming", &windowActive, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
	ImGui::PushAllowKeyboardFocus(false);

	//Elements
	ImGui::Text("CONTROLS");
	ImGui::Indent();
	ImGui::Text("LMB: place target");
	ImGui::Text("RMB: move cam.");
	ImGui::Text("Scrollwheel: zoom cam.");
	ImGui::Unindent();

	ImGui::Spacing();
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::Spacing();

	ImGui::Text("STATS");
	ImGui::Indent();
	ImGui::Text("%.3f ms/frame", 1000.0f / ImGui::GetIO().Framerate);
	ImGui::Text("%.1f FPS", ImGui::GetIO().Framerate);
	ImGui::Unindent();

	ImGui::Spacing();
	ImGui::Separator();
	ImGui::Spacing();

	ImGui::Text("Flocking");
	ImGui::Spacing();

	// TODO: Implement checkboxes for debug rendering and weight sliders here
	//ImGui::Checkbox("Debug Rendering", &m_CanDebugRender);
	//ImGui::Checkbox("Trim World", &m_TrimWorld);
	//if (m_TrimWorld)
	//{
	//	ImGui::SliderFloat("Trim Size", &m_TrimWorldSize, 0.f, 500.f, "%1.");
	//}
	//
	//ImGui::SliderFloat("Cohesion", &m_pBlendedSteering->GetWeightedBehaviorsRef()[0].weight, 0.f, 1.f, "%.2");
	//ImGui::SliderFloat("Seperation", &m_pBlendedSteering->GetWeightedBehaviorsRef()[1].weight, 0.f, 1.f, "%.2");
	//ImGui::SliderFloat("Alignment", &m_pBlendedSteering->GetWeightedBehaviorsRef()[2].weight, 0.f, 1.f, "%.2");
	//ImGui::SliderFloat("Seek", &m_pBlendedSteering->GetWeightedBehaviorsRef()[3].weight, 0.f, 1.f, "%.2");
	//ImGui::SliderFloat("Wander", &m_pBlendedSteering->GetWeightedBehaviorsRef()[4].weight, 0.f, 1.f, "%.2");
	
	//End
	ImGui::PopAllowKeyboardFocus();
	ImGui::End();
	
}

void Flock::RegisterNeighbors(SteeringAgent* pAgent)
{
	m_NrOfNeighbors = 0;

	for (int index{}; index < m_Agents.size(); ++index)
	{
		if (m_Agents[index] && (pAgent != m_Agents[index]) )
		{
			float distance{ ( m_Agents[index]->GetPosition() - pAgent->GetPosition() ).Magnitude() };
			if (distance <= m_NeighborhoodRadius)
			{
				m_Neighbors.push_back(m_Agents[index]);
				++m_NrOfNeighbors;
			}
		}
	}
}

Elite::Vector2 Flock::GetAverageNeighborPos() const
{
	Vector2 averageNeighborPos{};

	for (int index{}; index < m_NrOfNeighbors; ++index)
	{
		averageNeighborPos += m_Neighbors[index]->GetPosition();
	}

	averageNeighborPos /= m_NrOfNeighbors;

	return Vector2{averageNeighborPos};
}

Elite::Vector2 Flock::GetAverageNeighborVelocity() const
{
	Vector2 averageNeighborVelocity{};

	for (int index{}; index < m_NrOfNeighbors; ++index)
	{
		averageNeighborVelocity += m_Neighbors[index]->GetLinearVelocity();
	}

	averageNeighborVelocity /= m_NrOfNeighbors;

	return Vector2{ averageNeighborVelocity };
}

void Flock::SetTarget_Seek(TargetData target)
{
	m_pSeekBehavior->SetTarget(target);
}


float* Flock::GetWeight(ISteeringBehavior* pBehavior) 
{
	if (m_pBlendedSteering)
	{
		auto& weightedBehaviors = m_pBlendedSteering->GetWeightedBehaviorsRef();
		auto it = find_if(weightedBehaviors.begin(),
			weightedBehaviors.end(),
			[pBehavior](BlendedSteering::WeightedBehavior el)
			{
				return el.pBehavior == pBehavior;
			}
		);

		if(it!= weightedBehaviors.end())
			return &it->weight;
	}

	return nullptr;
}
