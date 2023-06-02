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
	delete[] m_ParticlesArray;
	m_pVertexBuffer->Release();
}

void ParticleEmitterComponent::Initialize(const SceneContext& sceneContext)
{
	if (!m_pParticleMaterial)
	{
		m_pParticleMaterial = MaterialManager::Get()->CreateMaterial<ParticleMaterial>();
	}

	CreateVertexBuffer(sceneContext);

	m_pParticleTexture = ContentManager::Load<TextureData>(m_AssetFile);
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
	float particleInterval{ ((m_EmitterSettings.minEnergy + m_EmitterSettings.maxEnergy) / 2.f) / m_ParticleCount };

	const float elapsedSec{ sceneContext.pGameTime->GetElapsed() };

	m_LastParticleSpawn += elapsedSec;

	m_ActiveParticles = 0u;

	D3D11_MAPPED_SUBRESOURCE subResource{};
	sceneContext.d3dContext.pDeviceContext->Map(m_pVertexBuffer, 0u, D3D11_MAP_WRITE_DISCARD, 0u, &subResource);
	
	VertexParticle* pBuffer{};
	pBuffer = reinterpret_cast<VertexParticle*>(subResource.pData);

	for (UINT index{}; index < m_ParticleCount; ++index)
	{
		Particle& pParticle{ m_ParticlesArray[index] };

		if (pParticle.isActive)
			UpdateParticle(pParticle, elapsedSec);
		
		if (!pParticle.isActive && m_LastParticleSpawn >= particleInterval)
		{
			SpawnParticle(pParticle);
			m_LastParticleSpawn -= particleInterval;
		}

		if (pParticle.isActive)
		{
			pBuffer[m_ActiveParticles] = pParticle.vertexInfo;
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

	if (p.currentEnergy <= 0.f)
	{
		p.isActive = false;
		return;
	}

	auto pos{ XMLoadFloat3(&p.vertexInfo.Position) };
	auto velocity{ XMLoadFloat3(&p.velocity) };
	pos += velocity * elapsedTime;
	XMStoreFloat3(&p.vertexInfo.Position, pos);

	p.vertexInfo.Color = m_EmitterSettings.color;

	const float lifePercentage{ p.currentEnergy / p.totalEnergy };
	const float fadeDelay{ 2.f };
	p.vertexInfo.Color.w = m_EmitterSettings.color.w * lifePercentage * fadeDelay;

	p.vertexInfo.Size = p.initialSize * ( 1.f + (p.sizeChange - 1.f) * (1.f - lifePercentage));
}

void ParticleEmitterComponent::SpawnParticle(Particle& p)
{
	p.isActive = true;

	p.totalEnergy = MathHelper::randF(m_EmitterSettings.minEnergy, m_EmitterSettings.maxEnergy);
	p.currentEnergy = p.totalEnergy;

	XMVECTOR randomDirection{ 1.f, 0.f, 0.f };
	auto randomRotationMatrix{ DirectX::XMMatrixRotationRollPitchYaw(MathHelper::randF(-XM_PI, XM_PI), MathHelper::randF(-XM_PI, XM_PI), MathHelper::randF(-XM_PI, XM_PI)) };
	XMVector2TransformNormal(randomDirection, randomRotationMatrix);

	XMStoreFloat3(&p.vertexInfo.Position, XMLoadFloat3(&GetTransform()->GetWorldPosition()) + randomDirection * MathHelper::randF(m_EmitterSettings.minEmitterRadius, m_EmitterSettings.maxEmitterRadius));
	
	p.initialSize = MathHelper::randF(m_EmitterSettings.minSize, m_EmitterSettings.maxSize);
	p.vertexInfo.Size = p.initialSize;

	p.sizeChange = MathHelper::randF(m_EmitterSettings.minScale, m_EmitterSettings.maxScale);

	p.vertexInfo.Rotation = MathHelper::randF(-XM_PI, XM_PI);

	p.vertexInfo.Color = m_EmitterSettings.color;

	p.velocity.x = MathHelper::randF(m_EmitterSettings.minVelocity.x, m_EmitterSettings.maxVelocity.x);
	p.velocity.y = MathHelper::randF(m_EmitterSettings.minVelocity.y, m_EmitterSettings.maxVelocity.y);
	p.velocity.z = MathHelper::randF(m_EmitterSettings.minVelocity.z, m_EmitterSettings.maxVelocity.z);
}

void ParticleEmitterComponent::PostDraw(const SceneContext& sceneContext)
{
	m_pParticleMaterial->SetVariable_Matrix(L"gWorldViewProj", sceneContext.pCamera->GetViewProjection());
	m_pParticleMaterial->SetVariable_Matrix(L"gViewInverse", sceneContext.pCamera->GetViewInverse());
	m_pParticleMaterial->SetVariable_Texture(L"gParticleTexture", m_pParticleTexture->GetShaderResourceView());

	auto pDeviceContext{ sceneContext.d3dContext.pDeviceContext };
	const auto& pTechniqueContext{ m_pParticleMaterial->GetTechniqueContext() };

	//set the InputLayout
	pDeviceContext->IASetInputLayout(pTechniqueContext.pInputLayout);

	//set the PrimitiveTopology
	pDeviceContext->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_POINTLIST);

	//set the VertexBuffer
	const UINT stride{ sizeof(VertexParticle) };
	const UINT offset{};
	pDeviceContext->IASetVertexBuffers(0u, 1u, &m_pVertexBuffer, &stride, &offset);

	D3DX11_TECHNIQUE_DESC techniqueDesc;
	pTechniqueContext.pTechnique->GetDesc(&techniqueDesc);
	
	for (uint32_t index{}; index < techniqueDesc.Passes; ++index)
	{
		//Apply the pass
		pTechniqueContext.pTechnique->GetPassByIndex(0)->Apply(0, pDeviceContext);

		//Draw the vertices
		pDeviceContext->Draw(m_ActiveParticles, 0u);
	}
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
		ImGui::InputFloat3("MinVelocity", &m_EmitterSettings.minVelocity.x);
		ImGui::InputFloat3("MaxVelocity", &m_EmitterSettings.maxVelocity.x);
		ImGui::ColorEdit4("Color", &m_EmitterSettings.color.x, ImGuiColorEditFlags_NoInputs);
	}
}