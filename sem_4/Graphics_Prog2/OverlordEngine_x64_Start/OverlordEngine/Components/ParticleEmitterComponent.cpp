#include "stdafx.h"
#include "ParticleEmitterComponent.h"
#include "Misc/ParticleMaterial.h"

ParticleMaterial* ParticleEmitterComponent::m_pParticleMaterial{};

ParticleEmitterComponent::ParticleEmitterComponent(const std::wstring& assetFile, const ParticleEmitterSettings& emitterSettings, UINT particleCount):
	m_ParticlesArray(new Particle[particleCount]),
	m_ParticleCount(particleCount), //How big is our particle buffer?
	m_MaxParticles(particleCount), //How many particles to draw (max == particleCount)
	m_AssetFile(assetFile),
	m_EmitterSettings(emitterSettings)
{
	m_enablePostDraw = true; //This enables the PostDraw function for the component
}

ParticleEmitterComponent::~ParticleEmitterComponent()
{
	delete m_ParticlesArray;
	m_pVertexBuffer->Release();
}

void ParticleEmitterComponent::Initialize(const SceneContext& sceneContext)
{
	if (!m_pParticleMaterial)
	{
		m_pParticleMaterial = MaterialManager::Get()->CreateMaterial<ParticleMaterial>();
	}

	CreateVertexBuffer(sceneContext);

	m_pParticleTexture = ContentManager::Load<TextureData>(L"Resources/Textures/Smoke.png");
}

void ParticleEmitterComponent::CreateVertexBuffer(const SceneContext& sceneContext)
{
	if (m_pVertexBuffer)
		m_pVertexBuffer->Release();

	D3D11_BUFFER_DESC vertexBuffer{};
	vertexBuffer.Usage = D3D11_USAGE_DYNAMIC;
	vertexBuffer.ByteWidth = sizeof(VertexParticle) * m_ParticleCount;
	vertexBuffer.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBuffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	HANDLE_ERROR(sceneContext.d3dContext.pDevice->CreateBuffer(&vertexBuffer, nullptr, &m_pVertexBuffer))
}

void ParticleEmitterComponent::Update(const SceneContext& sceneContext)
{
	float particleInterval{ ((m_EmitterSettings.maxEnergy + m_EmitterSettings.minEnergy) / 2.f) / m_ParticleCount };

	const float elapsedSec{ sceneContext.pGameTime->GetElapsed() };

	m_LastParticleSpawn += elapsedSec;

	m_ActiveParticles = 0u;

	D3D11_MAPPED_SUBRESOURCE* pData{};

	HANDLE_ERROR(sceneContext.d3dContext.pDeviceContext->Map(m_pVertexBuffer, 0u, D3D11_MAP_WRITE_DISCARD, 0u, pData));
	
	VertexParticle* pBuffer{};
	pBuffer = reinterpret_cast<VertexParticle*>(pData);

	for (UINT index{}; index < m_ParticleCount; ++index)
	{
		auto pParticle{ m_ParticlesArray + index };

		if (pParticle->isActive)
			UpdateParticle(*pParticle, elapsedSec);
		
		if (!pParticle->isActive && m_LastParticleSpawn > particleInterval)
		{
			SpawnParticle(*pParticle);
		}

		if (pParticle->isActive)
		{
			pBuffer[m_ActiveParticles] = pParticle->vertexInfo;
			++m_ActiveParticles;
		}
	}

	sceneContext.d3dContext.pDeviceContext->Unmap(m_pVertexBuffer, 0u);
}

void ParticleEmitterComponent::UpdateParticle(Particle& p, float elapsedTime) const
{
	if (!p.isActive)
		return;

	p.currentEnergy -= elapsedTime;

	auto pos{ XMLoadFloat3(&p.vertexInfo.Position) };
	auto velocity{ XMLoadFloat3(&p.vertexInfo.Position) };
	pos += elapsedTime * velocity;
	XMStoreFloat3(&p.vertexInfo.Position, pos);

	p.vertexInfo.Color = m_EmitterSettings.color;
	p.vertexInfo.Color.w = m_EmitterSettings.color.w * (p.currentEnergy / p.totalEnergy);

	p.vertexInfo.Size = p.initialSize * p.sizeChange * (p.currentEnergy / p.totalEnergy);
}

void ParticleEmitterComponent::SpawnParticle(Particle& p)
{
	p.isActive = true;
}

void ParticleEmitterComponent::PostDraw(const SceneContext& /*sceneContext*/)
{
	TODO_W9(L"Implement PostDraw")
}

void ParticleEmitterComponent::DrawImGui()
{
	if(ImGui::CollapsingHeader("Particle System"))
	{
		ImGui::SliderUInt("Count", &m_ParticleCount, 0, m_MaxParticles);
		ImGui::InputFloatRange("Energy Bounds", &m_EmitterSettings.minEnergy, &m_EmitterSettings.maxEnergy);
		ImGui::InputFloatRange("Size Bounds", &m_EmitterSettings.minSize, &m_EmitterSettings.maxSize);
		ImGui::InputFloatRange("Scale Bounds", &m_EmitterSettings.minScale, &m_EmitterSettings.maxScale);
		ImGui::InputFloatRange("Radius Bounds", &m_EmitterSettings.minEmitterRadius, &m_EmitterSettings.maxEmitterRadius);
		ImGui::InputFloat3("Velocity", &m_EmitterSettings.velocity.x);
		ImGui::ColorEdit4("Color", &m_EmitterSettings.color.x, ImGuiColorEditFlags_NoInputs);
	}
}