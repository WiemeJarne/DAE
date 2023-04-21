#include "stdafx.h"
#include "CameraComponent.h"

CameraComponent::CameraComponent() :
	m_FarPlane(2500.0f),
	m_NearPlane(0.1f),
	m_FOV(XM_PIDIV4),
	m_Size(25.0f),
	m_PerspectiveProjection(true)
{
	XMStoreFloat4x4(&m_Projection, XMMatrixIdentity());
	XMStoreFloat4x4(&m_View, XMMatrixIdentity());
	XMStoreFloat4x4(&m_ViewInverse, XMMatrixIdentity());
	XMStoreFloat4x4(&m_ViewProjection, XMMatrixIdentity());
	XMStoreFloat4x4(&m_ViewProjectionInverse, XMMatrixIdentity());
}

void CameraComponent::Update(const SceneContext& sceneContext)
{
	// see https://stackoverflow.com/questions/21688529/binary-directxxmvector-does-not-define-this-operator-or-a-conversion
	using namespace DirectX;

	XMMATRIX projection{};

	if (m_PerspectiveProjection)
	{
		projection = XMMatrixPerspectiveFovLH(m_FOV, sceneContext.aspectRatio, m_NearPlane, m_FarPlane);
	}
	else
	{
		const float viewWidth = (m_Size > 0) ? m_Size * sceneContext.aspectRatio : sceneContext.windowWidth;
		const float viewHeight = (m_Size > 0) ? m_Size : sceneContext.windowHeight;
		projection = XMMatrixOrthographicLH(viewWidth, viewHeight, m_NearPlane, m_FarPlane);
	}

	const XMVECTOR worldPosition = XMLoadFloat3(&GetTransform()->GetWorldPosition());
	const XMVECTOR lookAt = XMLoadFloat3(&GetTransform()->GetForward());
	const XMVECTOR upVec = XMLoadFloat3(&GetTransform()->GetUp());

	const XMMATRIX view = XMMatrixLookAtLH(worldPosition, worldPosition + lookAt, upVec);
	const XMMATRIX viewInv = XMMatrixInverse(nullptr, view);
	const XMMATRIX viewProjectionInv = XMMatrixInverse(nullptr, view * projection);

	XMStoreFloat4x4(&m_Projection, projection);
	XMStoreFloat4x4(&m_View, view);
	XMStoreFloat4x4(&m_ViewInverse, viewInv);
	XMStoreFloat4x4(&m_ViewProjection, view * projection);
	XMStoreFloat4x4(&m_ViewProjectionInverse, viewProjectionInv);
}

void CameraComponent::SetActive(bool active)
{
	if (m_IsActive == active) return;

	const auto pGameObject = GetGameObject();
	ASSERT_IF(!pGameObject, L"Failed to set active camera. Parent game object is null");

	if (!pGameObject) return; //help the compiler... (C6011)
	const auto pScene = pGameObject->GetScene();
	ASSERT_IF(!pScene, L"Failed to set active camera. Parent game scene is null");

	m_IsActive = active;
	pScene->SetActiveCamera(active?this:nullptr); //Switch to default camera if active==false
}

GameObject* CameraComponent::Pick(CollisionGroup ignoreGroups) const
{
	auto& sceneContex{ GetGameObject()->GetScene()->GetSceneContext() };

	const POINT& mousePos{ InputManager::GetMousePosition() };
	const float halfWindowWidth{ sceneContex.windowWidth / 2.f };
	const float halfWindowHeight{ sceneContex.windowHeight / 2.f };

	const XMFLOAT2 ndcPos
	{
		(static_cast<float>(mousePos.x) - halfWindowWidth) / halfWindowWidth,
		(halfWindowHeight - static_cast<float>(mousePos.y)) / halfWindowHeight
	};

	const auto& viewProjectionInverse{ XMLoadFloat4x4(&GetViewProjectionInverse()) };

	const XMVECTOR rayStartPosVector{ XMVector3TransformCoord(XMVECTOR{ndcPos.x, ndcPos.y, 0.f}, viewProjectionInverse) };
	const XMVECTOR rayEndPosVector{ XMVector3TransformCoord(XMVECTOR{ndcPos.x, ndcPos.y, 1.f}, viewProjectionInverse) };

	XMFLOAT3 rayStartPos{};
	XMStoreFloat3(&rayStartPos, rayStartPosVector);

	XMFLOAT3 rayEndPos{};
	XMStoreFloat3(&rayEndPos, rayEndPosVector);

	PxVec3 rayStartPosVec3{ rayStartPos.x, rayStartPos.y, rayStartPos.z };
	PxVec3 rayDirection{ rayEndPos.x - rayStartPos.x, rayEndPos.y - rayStartPos.y, rayEndPos.z - rayStartPos.z };
	rayDirection = rayDirection.getNormalized();

	PxQueryFilterData filterData{};
	filterData.data.word0 = ~static_cast<UINT>(ignoreGroups);

	PxRaycastBuffer hitCall{};
	if (GetGameObject()->GetScene()->GetPhysxProxy()->Raycast(rayStartPosVec3, rayDirection, PX_MAX_F32, hitCall, PxHitFlag::eDEFAULT, filterData))
		return static_cast<BaseComponent*>(hitCall.block.actor->userData)->GetGameObject();

	return nullptr;
}