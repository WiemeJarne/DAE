#include "stdafx.h"
#include "AudioTestScene.h"
#include "PhysxManager.h"

#include "SpherePosColorNorm.h"
#include "SoundManager.h"
#include "Logger.h"

void AudioTestScene::Initialize()
{
	EnablePhysxDebugRendering(true);

	const auto pPhysX{ PhysxManager::GetInstance()->GetPhysics() };
	const auto pDefaultMat{ pPhysX->createMaterial(0.5f, 0.5f, 0.2f) };

	//ground plane
	const auto pGroundActor = pPhysX->createRigidStatic(PxTransform({ PxPiDivTwo, {0, 0, 1} }));

	PxRigidActorExt::createExclusiveShape(*pGroundActor, PxPlaneGeometry(), *pDefaultMat);
	m_pPhysxScene->addActor(*pGroundActor);

	//Sphere
	m_pSphere = new SpherePosColorNorm(1.f, 10, 10, XMFLOAT4{ Colors::Gray });
	AddGameObject(m_pSphere);

	const auto pSphereActor{ pPhysX->createRigidDynamic(PxTransform(PxIdentity)) };
	PxRigidActorExt::createExclusiveShape(*pSphereActor, PxSphereGeometry(1.f), *pDefaultMat);
	m_pSphere->AttachRigidActor(pSphereActor);

	m_pSphere->Translate(0.f, 2.f, 0.f);

	//INPUT
	const auto pInput{ m_SceneContext.GetInput() };
	pInput->AddInputAction({InputIds::Play2D, InputTriggerState::pressed, VK_SPACE });
	pInput->AddInputAction({ InputIds::Play3D, InputTriggerState::pressed, 'B'});
	pInput->AddInputAction({ InputIds::IncreaseVolume, InputTriggerState::pressed, VK_UP });
	pInput->AddInputAction({ InputIds::DecreaseVolume, InputTriggerState::pressed, VK_DOWN });

	const auto pFmod{ SoundManager::GetInstance()->GetSystem() };

	//SOUND 2D
	FMOD::Sound* pSound2D{ nullptr };
	FMOD_RESULT result{ pFmod->createStream("Resources/Sounds/wave.mp3", FMOD_2D | FMOD_LOOP_NORMAL, nullptr, &pSound2D) };
	SoundManager::GetInstance()->ErrorCheck(result);

	result = pFmod->playSound(pSound2D, nullptr, true, &m_pChannel2D);
	SoundManager::GetInstance()->ErrorCheck(result);

	//SOUND 3D
	FMOD::Sound* pSound3D{ nullptr };
	result = pFmod->createStream("Resources/Sounds/Thrones.mp3", FMOD_3D | FMOD_LOOP_NORMAL | FMOD_3D_LINEARROLLOFF, nullptr, &pSound3D);
	SoundManager::GetInstance()->ErrorCheck(result);

	result = pFmod->playSound(pSound3D, nullptr, true, &m_pChannel3D);
	SoundManager::GetInstance()->ErrorCheck(result);

	m_pChannel3D->set3DMinMaxDistance(0.f, 20.f);
}

inline FMOD_VECTOR ToFmod(XMFLOAT3 v)
{
	return (FMOD_VECTOR(v.x, v.y, v.z));
}

inline FMOD_VECTOR ToFmod(PxVec3 v)
{
	return (FMOD_VECTOR(v.x, v.y, v.z));
}

void AudioTestScene::Update()
{
	//Sphere
	constexpr float force{ 5.f };

	if (m_SceneContext.GetInput()->IsKeyboardKey(InputTriggerState::down, VK_LEFT))
	{
		m_pSphere->GetRigidActor()->is<PxRigidDynamic>()->addTorque({ 0,0,force });
	}
	else if (m_SceneContext.GetInput()->IsKeyboardKey(InputTriggerState::down, VK_RIGHT))
	{
		m_pSphere->GetRigidActor()->is<PxRigidDynamic>()->addTorque({ 0,0,-force });
	}

	//Sound Input
	if (m_SceneContext.GetInput()->IsActionTriggered(InputIds::Play2D))
	{
		bool isPaused{ };
		m_pChannel2D->getPaused(&isPaused);
		m_pChannel2D->setPaused(!isPaused);
	}

	if (m_SceneContext.GetInput()->IsActionTriggered(InputIds::Play3D))
	{
		bool isPaused{ };
		m_pChannel3D->getPaused(&isPaused);
		m_pChannel3D->setPaused(!isPaused);
	}
	 
	if (m_SceneContext.GetInput()->IsActionTriggered(InputIds::IncreaseVolume))
	{
		float volume{};
		m_pChannel2D->getVolume(&volume);

		volume += 0.1f;
		Clamp(volume, 10.f, 0.f);

		m_pChannel2D->setVolume(volume);

		Logger::GetInstance()->LogFormat(LogLevel::Info, L"Volume changed >> %f", volume);
	}

	if (m_SceneContext.GetInput()->IsActionTriggered(InputIds::IncreaseVolume))
	{
		float volume{};
		m_pChannel2D->getVolume(&volume);

		volume -= 0.1f;
		Clamp(volume, 10.f, 0.f);

		m_pChannel2D->setVolume(volume);

		Logger::GetInstance()->LogFormat(LogLevel::Info, L"Volume changed >> %f", volume);
	}

	//3D SOUND ATTRIBUTES
	auto pCam{ m_SceneContext.GetCamera() };
	auto pos{ ToFmod(pCam->GetPosition()) };
	auto forward{ ToFmod(pCam->GetForward()) };
	auto up{ ToFmod(pCam->GetUp()) };

	FMOD_VECTOR velocity{};
	const float deltaT{ m_SceneContext.GetGameTime()->GetElapsed() };
	velocity.x = (pos.x - m_PrevCamPos.x) / deltaT;
	velocity.y = (pos.y - m_PrevCamPos.y) / deltaT;
	velocity.z = (pos.z - m_PrevCamPos.z) / deltaT;
	
	m_PrevCamPos = pos;

	SoundManager::GetInstance()->GetSystem()->set3DListenerAttributes(0, &pos, &velocity, &forward, &up);

	auto spherePos{ ToFmod(m_pSphere->GetPosition()) };
	auto sphereVelocity{ ToFmod(m_pSphere->GetRigidActor()->is<PxRigidDynamic>()->getLinearVelocity()) };

	m_pChannel3D->set3DAttributes(&spherePos, &sphereVelocity);
}

void AudioTestScene::Draw() const
{

}

void AudioTestScene::OnSceneActivated()
{

}

void AudioTestScene::OnSceneDeactivated()
{
}