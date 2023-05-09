#pragma once
#include "Prefabs/Character.h"

class DiffuseMaterial;
class Grid;

class Cell final
{
public:
	enum class State
	{
		empty,
		bomb,
		wall,
		fire,
		crackedWall,
		pickUp
	};

	Cell(GameScene* pGameScene, Grid* pOwnerGrid, XMFLOAT3 middlePos, int rowNr, int colNr, State state = State::empty);
	Cell(GameScene* pGameScene, Grid* pOwnerGrid, XMFLOAT3 middlePos, int rowNr, int colNr, State state, GameObject* pGameObjectInCell);

	void Update();
	void PlaceBomb(CharacterDesc* pCharacterDesc);
	void DestroyObjectInCell();
	XMFLOAT3 GetMiddlePos() const { return m_MiddlePos; }
	State GetState() const { return m_State; }
	void SetShouldPlacePickUp(bool shouldPlacePickUp) { m_ShouldPlacePickUp = shouldPlacePickUp; }
	void SetShouldDestroyGameObjectInCell(bool shouldDestroyGameObjectInCell) { m_ShouldDestroyGameObjectInCell = shouldDestroyGameObjectInCell; }

private:
	XMFLOAT3 m_MiddlePos{};
	float m_TimeSinceItemPlaceOnCell{};
	State m_State{};
	Grid* m_pOwnerGrid{};
	const int m_RowNr{};
	const int m_ColNr{};
	GameObject* m_pGameObjectInCell{};
	int m_BombBlastRadius{};
	CharacterDesc* m_pCharacterDescPlacedBomb{};
	bool m_ShouldAddColliderToGameObjectInCell{};
	bool m_ShouldPlacePickUp{};
	bool m_ShouldDestroyGameObjectInCell{};

	static GameScene* m_spGameScene;
	static DiffuseMaterial* m_spBombMaterial;
	static DiffuseMaterial* m_spFlameMaterial;
	static DiffuseMaterial* m_spBombUpBonusMaterial;
	static DiffuseMaterial* m_spBombDownBonusMaterial;
	static DiffuseMaterial* m_spFireUpBonusMaterial;
	static DiffuseMaterial* m_spFireDownBonusMaterial;
	static DiffuseMaterial* m_spFullFireBonusMaterial;
	static DiffuseMaterial* m_spPierceBombBonusMaterial;
	static DiffuseMaterial* m_spSkateUpBonusMaterial;
	static DiffuseMaterial* m_spSkateDownBonusMaterial;
	static PxMaterial* m_spPhysxMaterial;
	static float m_sSecUntilExplotion;
	static float m_sSecFireBurn;
	static GameObject::PhysicsCallback m_sBombUpBonusCallBack;
	static GameObject::PhysicsCallback m_sBombDownBonusCallBack;
	static GameObject::PhysicsCallback m_sFireUpBonusCallBack;
	static GameObject::PhysicsCallback m_sFireDownBonusCallBack;
	static GameObject::PhysicsCallback m_sFullFireBonusCallBack;
	static GameObject::PhysicsCallback m_sPierceBombBonusCallBack;
	static GameObject::PhysicsCallback m_sSkateUpBonusCallBack;
	static GameObject::PhysicsCallback m_sSkateDownBonusCallBack;

	void ExplodeBomb();
	void PlaceFire(XMFLOAT3 pos);
	void AddColliderToGameObjectInCell();
	void PlaceRandomPickUp(XMFLOAT3 pos);
};