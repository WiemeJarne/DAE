#include "stdafx.h"
#include "Flock.h"

#include "../SteeringAgent.h"
#include "../Steering/SteeringBehaviors.h"
#include "../CombinedSteering/CombinedSteeringBehaviors.h"
#include "../SpacePartitioning/SpacePartitioning.h"

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
	// TODO: initialize the flock and the memory pool
	m_Agents.resize(m_FlockSize);
	m_Neighbors.resize(m_FlockSize);

	m_CellSpace = new CellSpace(m_WorldSize, m_WorldSize, 20, 20, 100);

	m_pSeekBehavior = new Seek();
	m_pSeparationBehavior = new Separation(this);
	m_pCohesionBehavior = new Cohesion(this);
	m_pVelMatchBehavior = new VelocityMatch(this);
	m_pWanderBehavior = new Wander();

	m_pBlendedSteering = new BlendedSteering({{m_pSeekBehavior, 0.2f},
												 {m_pSeparationBehavior, 0.2f},
											     {m_pCohesionBehavior, 0.2f},
												 {m_pVelMatchBehavior, 0.2f},
											     {m_pWanderBehavior, 0.2f}	   });

	m_pEvadeBehavior = new Evade();
	m_pPrioritySteering = new PrioritySteering({ m_pEvadeBehavior, m_pBlendedSteering });
	
	Vector2 randomPos{};
	Vector2 randomLinearVelocity{};
	for (int index{}; index < m_FlockSize; ++index)
	{
		m_Agents[index] = new SteeringAgent();
		m_Agents[index]->SetSteeringBehavior(m_pPrioritySteering);
		m_Agents[index]->SetMaxLinearSpeed(15.f);
		m_Agents[index]->SetMass(0.f);
		m_Agents[index]->SetAutoOrient(true);
		randomPos.x = static_cast<float>(rand() % static_cast<int>(m_WorldSize));
		randomPos.y = static_cast<float>(rand() % static_cast<int>(m_WorldSize));
		m_Agents[index]->SetPosition(randomPos);
		randomLinearVelocity.x = static_cast<float>(rand() % static_cast<int>(m_Agents[index]->GetMaxLinearSpeed()));
		randomLinearVelocity.y = static_cast<float>(rand() % static_cast<int>(m_Agents[index]->GetMaxLinearSpeed()));
		m_Agents[index]->SetLinearVelocity(randomLinearVelocity);

		m_CellSpace->AddAgent(m_Agents[index]);
	}
	
	m_pAgentToEvade = new SteeringAgent();
	m_pAgentToEvade->SetSteeringBehavior(m_pSeekBehavior);
	m_pAgentToEvade->SetMaxLinearSpeed(15.f);
	m_pAgentToEvade->SetMass(0.f);
	m_pAgentToEvade->SetAutoOrient(true);
	m_pAgentToEvade->SetBodyColor({ 1.f, 0.f, 0.f });
	randomPos.x = static_cast<float>(rand() % static_cast<int>(m_WorldSize));
	randomPos.y = static_cast<float>(rand() % static_cast<int>(m_WorldSize));
	m_pAgentToEvade->SetPosition(randomPos);
}

Flock::~Flock()
{
	// TODO: clean up any additional data
	m_CellSpace->EmptyCells();
	SAFE_DELETE(m_CellSpace);

	SAFE_DELETE(m_pSeekBehavior);
	SAFE_DELETE(m_pSeparationBehavior);
	SAFE_DELETE(m_pCohesionBehavior);
	SAFE_DELETE(m_pVelMatchBehavior);
	SAFE_DELETE(m_pWanderBehavior);
	SAFE_DELETE(m_pEvadeBehavior);

	SAFE_DELETE(m_pBlendedSteering);
	SAFE_DELETE(m_pPrioritySteering);

	for(auto pAgent: m_Agents)
	{
		SAFE_DELETE(pAgent);
	}
	m_Agents.clear();

	SAFE_DELETE(m_pAgentToEvade);
}

void Flock::Update(float deltaT)
{
	m_pAgentToEvade->Update(deltaT);
	m_pEvadeBehavior->SetTarget(m_pAgentToEvade->GetPosition());

	// TODO: update the flock
	// loop over all the agents
		// register its neighbors	(-> memory pool is filled with neighbors of the currently evaluated agent)
		// update it				(-> the behaviors can use the neighbors stored in the pool, next iteration they will be the next agent's neighbors)
		// trim it to the world
	for (size_t index{}; index < m_Agents.size(); ++index)
	{
		if (m_SpatialPartitioning)
		{
			m_CellSpace->RegisterNeighbors(m_Agents[index], m_NeighborhoodRadius);
			m_Agents[index]->Update(deltaT);

			if (m_Agents[index]->GetPriviousPos() != Vector2{0, 0})
			{
				m_CellSpace->UpdateAgentCell(m_Agents[index], m_Agents[index]->GetPriviousPos());
			}

			m_Agents[index]->SetPreviousPos(m_Agents[index]->GetPosition());
		}
		else
		{
			RegisterNeighbors(m_Agents[index]);
			m_Agents[index]->Update(deltaT);
		}

		if (m_TrimWorld)
		{
			m_Agents[index]->TrimToWorld(m_WorldSize);
			m_pAgentToEvade->TrimToWorld(m_WorldSize);
		}
	}

	if(m_CanDebugRender)
	{
		if(m_SpatialPartitioning)
		{
			m_Agents[0]->SetRenderBehavior(true);
			m_Agents[0]->SetBodyColor({ 0.f, 0.f, 1.f });
		}
		else
		{
			const Vector2 agentPosition{ m_Agents[0]->GetPosition() };
			const Vector2 agentDirection{ m_Agents[0]->GetDirection() };

			//colors the first agent in the vector blue
			m_Agents[0]->SetBodyColor({ 0.f, 0.f, 1.f });

			//draws the current velocity vector
			DEBUGRENDERER2D->DrawDirection(agentPosition, agentDirection, m_Agents[0]->GetLinearVelocity().Magnitude(), { 1.f, 0.f, 1.f });

			//draws neighborhood circle
			DEBUGRENDERER2D->DrawCircle(agentPosition, m_NeighborhoodRadius, { 1.f, 1.f, 1.f }, 0.f);

			//draw the evading circle
			DEBUGRENDERER2D->DrawCircle(m_pAgentToEvade->GetPosition(), static_cast<float>(m_pEvadeBehavior->GetEvadeRadius()), { 1.f, 0.f, 0.f }, 0.f);
		}
	}
	else
	{
		m_Agents[0]->SetRenderBehavior(false);
		m_Agents[0]->SetBodyColor({ 1.f, 1.f, 0.f });
	}
}

void Flock::Render(float deltaT)
{
	// TODO: render the flock
	/*for (size_t index{}; index < m_Agents.size(); ++index)
	{
		m_Agents[index]->Render(deltaT);
	}

	m_pAgentToEvade->Render(deltaT);*/

	if(m_CanDebugRender && m_SpatialPartitioning)
	{
		m_CellSpace->RenderCells();
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
	ImGui::Checkbox("Spatial Partitioning", &m_SpatialPartitioning);
	ImGui::Checkbox("Debug Rendering", &m_CanDebugRender);

	ImGui::SliderFloat("Seek", &m_pBlendedSteering->GetWeightedBehaviorsRef()[0].weight, 0.f, 1.f, "%.2");
	ImGui::SliderFloat("Separation", &m_pBlendedSteering->GetWeightedBehaviorsRef()[1].weight, 0.f, 1.f, "%.2");
	ImGui::SliderFloat("Cohesion", &m_pBlendedSteering->GetWeightedBehaviorsRef()[2].weight, 0.f, 1.f, "%.2");
	ImGui::SliderFloat("VelocityMatch", &m_pBlendedSteering->GetWeightedBehaviorsRef()[3].weight, 0.f, 1.f, "%.2");
	ImGui::SliderFloat("Wander", &m_pBlendedSteering->GetWeightedBehaviorsRef()[4].weight, 0.f, 1.f, "%.2");

	//End
	ImGui::PopAllowKeyboardFocus();
	ImGui::End();
}

void Flock::RegisterNeighbors(SteeringAgent* pAgent)
{
	m_NrOfNeighbors = 0;

	for (size_t index{}; index < m_Agents.size(); ++index)
	{
		if (m_Agents[index] && (pAgent != m_Agents[index]) )
		{
			const float distance{ ( m_Agents[index]->GetPosition() - pAgent->GetPosition() ).Magnitude() };
			if (distance <= m_NeighborhoodRadius)
			{
				m_Neighbors[m_NrOfNeighbors] = m_Agents[index];
				++m_NrOfNeighbors;

				//colors the neighbors of the first agent in the vector green
				if (m_CanDebugRender && pAgent == m_Agents[0])
				{
					m_Agents[index]->SetBodyColor({ 0.f, 1.f, 0.f });
				}
			}
			else if (m_CanDebugRender && pAgent == m_Agents[0])
			{
				//colors the not neighbors yellow
				m_Agents[index]->SetBodyColor({ 1.f, 1.f, 0.f });
			}
		}
	}
}

int Flock::GetNrOfNeighbors() const
{
	if (m_SpatialPartitioning)
	{
		return m_CellSpace->GetNrOfNeighbors();
	}

	return m_NrOfNeighbors;
}

const std::vector<SteeringAgent*>& Flock::GetNeighbors() const
{
	if (m_SpatialPartitioning)
	{
		return m_CellSpace->GetNeighbors();
	}

	return m_Neighbors;
}

Elite::Vector2 Flock::GetAverageNeighborPos() const
{
	Vector2 averageNeighborPos{};
	int nrOfNeighbours{};
	std::vector<SteeringAgent*> neighbors{};

	if (m_SpatialPartitioning)
	{
		nrOfNeighbours = m_CellSpace->GetNrOfNeighbors();
		neighbors = m_CellSpace->GetNeighbors();
	}
	else
	{
		nrOfNeighbours = m_NrOfNeighbors;
		neighbors = m_Neighbors;
	}

	for (int index{}; index < nrOfNeighbours; ++index)
	{
		if (index < neighbors.size())
		{
			averageNeighborPos += neighbors[index]->GetPosition();
		}
	}

	averageNeighborPos /= static_cast<float>(nrOfNeighbours);

	return averageNeighborPos;
}

Elite::Vector2 Flock::GetAverageNeighborVelocity() const
{
	Vector2 averageNeighborVelocity{};
	int nrOfNeighbours{};
	std::vector<SteeringAgent*> neighbors{};

	if (m_SpatialPartitioning)
	{
		nrOfNeighbours = m_CellSpace->GetNrOfNeighbors();
		neighbors = m_CellSpace->GetNeighbors();
	}
	else
	{
		nrOfNeighbours = m_NrOfNeighbors;
		neighbors = m_Neighbors;
	}

	for (int index{}; index < nrOfNeighbours; ++index)
	{
		if (index < neighbors.size())
		{
			averageNeighborVelocity += neighbors[index]->GetLinearVelocity();
		}
	}

	averageNeighborVelocity /= static_cast<float>(nrOfNeighbours);
	averageNeighborVelocity.Normalize();

	return averageNeighborVelocity;
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