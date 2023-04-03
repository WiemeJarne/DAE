#include "stdafx.h"
#include "ModelAnimator.h"

ModelAnimator::ModelAnimator(MeshFilter* pMeshFilter):
	m_pMeshFilter{pMeshFilter}
{
	SetAnimation(0);
}

void ModelAnimator::Update(const SceneContext& sceneContext)
{
	//We only update the transforms if the animation is running and the clip is set
	if (m_IsPlaying && m_ClipSet)
	{
		//1. 
		//Calculate the passedTicks (see the lab document)
		auto passedTicks = sceneContext.pGameTime->GetElapsed() * m_CurrentClip.ticksPerSecond * m_AnimationSpeed;

		//Make sure that the passedTicks stay between the m_CurrentClip.Duration bounds (fmod)
		if (passedTicks > m_CurrentClip.duration)
			passedTicks = fmodf(passedTicks, m_CurrentClip.duration);

		//2. 
		//IF m_Reversed is true
		if (m_Reversed)
		{
			// Subtract passedTicks from m_TickCount
			m_TickCount -= passedTicks;
			
			// If m_TickCount is smaller than zero, add m_CurrentClip.Duration to m_TickCount
			if (m_TickCount < 0)
				m_TickCount += m_CurrentClip.duration;
		}
		//ELSE
		else
		{
			// Add passedTicks to m_TickCount
			m_TickCount += passedTicks;

			// if m_TickCount is bigger than the clip duration, subtract the duration from m_TickCount
			if (m_TickCount > m_CurrentClip.duration)
				m_TickCount -= m_CurrentClip.duration;
		}
		
		//3.
		//Find the enclosing keys
		AnimationKey keyA{}, keyB{};
		//Iterate all the keys of the clip and find the following keys:
		//keyA > Closest Key with Tick before/smaller than m_TickCount
		//keyB > Closest Key with Tick after/bigger than m_TickCount

		for (int index{}; index < m_CurrentClip.keys.size(); ++index)
		{
			if (m_CurrentClip.keys[index].tick > m_TickCount)
			{
				keyA = m_CurrentClip.keys[index - 1];
				keyB = m_CurrentClip.keys[index];
				break;
			}
		}

		//4.
		//Interpolate between keys
		//Figure out the BlendFactor (See lab document)
		const float blendFactor{ 1 - (keyB.tick - m_TickCount) / (m_CurrentClip.duration / (m_CurrentClip.keys.size() - 1)) };

		//Clear the m_Transforms vector
		//FOR every boneTransform in a key (So for every bone)
		for (int index{}; index < m_pMeshFilter->m_BoneCount; ++index)
		{
			// Retrieve the transform from keyA (transformA)
			const auto& transformA{ keyA.boneTransforms[index] };

			// Retrieve the transform from keyB (transformB)
			const auto& transformB{ keyB.boneTransforms[index] };

			// Decompose both transforms
			XMVECTOR scaleA{};
			XMVECTOR rotationA{};
			XMVECTOR translationA{};
			XMMatrixDecompose(&scaleA, &rotationA, &translationA, XMLoadFloat4x4(&transformA));

			XMVECTOR scaleB{};
			XMVECTOR rotationB{};
			XMVECTOR translationB{};
			XMMatrixDecompose(&scaleB, &rotationB, &translationB, XMLoadFloat4x4(&transformB));

			// Lerp between all the transformations (Position, Scale, Rotation)
			const XMVECTOR lerpedScale{ XMVectorLerp(scaleA, scaleB, blendFactor) };
			const XMVECTOR slerpedRotation{ XMQuaternionSlerp(rotationA, rotationB, blendFactor) };
			const XMVECTOR lerpedTranslation{ XMVectorLerp(translationA, translationB, blendFactor) };

			// Compose a transformation matrix with the lerp-results
			const XMMATRIX transform{ XMMatrixScalingFromVector(lerpedScale) * XMMatrixRotationQuaternion(slerpedRotation) * XMMatrixTranslationFromVector(lerpedTranslation) };

			// Add the resulting matrix to the m_Transforms vector
			XMStoreFloat4x4(&m_Transforms[index], transform);
		}
	}
}

void ModelAnimator::SetAnimation(const std::wstring& clipName)
{
	// Set m_ClipSet to false
	m_ClipSet = false;

	// Iterate the m_AnimationClips vector 
	for (auto& animationClip : m_pMeshFilter->GetAnimationClips())
	{
		// search for an AnimationClip with the given name (clipName)
		// If found,
		if (animationClip.name == clipName)
		{
			// Call SetAnimation(Animation Clip) with the found clip
			SetAnimation(animationClip);
			return;
		}
	}
	
	// if no animation found call Reset
	Reset();

	// Log a warning with an appropriate message
	Logger::LogWarning(L"there is no animationClip named " + clipName);
}

void ModelAnimator::SetAnimation(UINT clipNumber)
{
	//Set m_ClipSet to false
	m_ClipSet = false;

	//Check if clipNumber is smaller than the actual m_AnimationClips vector size
	if (!(clipNumber < m_pMeshFilter->GetAnimationClips().size()))
	{
		//If not,
		// Call Reset
		Reset();
		// Log a warning with an appropriate message
		Logger::LogWarning(L"there is no animationClip with index " + clipNumber);
		// return
		return;
	}
	
	//else
		// Retrieve the AnimationClip from the m_AnimationClips vector based on the given clipNumber
		// Call SetAnimation(AnimationClip clip)
	SetAnimation(m_pMeshFilter->GetAnimationClips()[clipNumber]);
}

void ModelAnimator::SetAnimation(const AnimationClip& clip)
{
	//Set m_ClipSet to true
	m_ClipSet = true;

	//Set m_CurrentClip
	m_CurrentClip = clip;

	//Call Reset(false)
	Reset(false);
}

void ModelAnimator::Reset(bool pause)
{
	//If pause is true, set m_IsPlaying to false
	if (pause)
		m_IsPlaying = false;

	//Set m_TickCount to zero
	m_TickCount = 0.f;

	//Set m_AnimationSpeed to 1.0f
	m_AnimationSpeed = 1.f;

	//If m_ClipSet is true
	if (m_ClipSet)
	{
		// Retrieve the BoneTransform from the first Key from the current clip (m_CurrentClip)
		// Refill the m_Transforms vector with the new BoneTransforms (have a look at vector::assign)
		m_Transforms = m_CurrentClip.keys[0].boneTransforms;
	}
	//Else
	else
	{
		// Create an IdentityMatrix 
		const XMFLOAT4X4 indentity
		{
			1.f, 0.f, 0.f, 0.f,
			0.f, 1.f, 0.f, 0.f,
			0.f, 0.f, 1.f, 0.f,
			0.f, 0.f, 0.f, 1.f
		};

		// Refill the m_Transforms vector with this IdenityMatrix (Amount = BoneCount) (have a look at vector::assign)
		m_Transforms = std::vector<XMFLOAT4X4>(m_pMeshFilter->m_BoneCount, indentity);
	}
}
