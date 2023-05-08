#pragma once

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
		crackedWall
	};

	Cell(GameScene* pGameScene, Grid* pOwnerGrid, XMFLOAT3 middlePos, int rowNr, int colNr, State state = State::empty);
	Cell(GameScene* pGameScene, Grid* pOwnerGrid, XMFLOAT3 middlePos, int rowNr, int colNr, State state, GameObject* pGameObjectInCell);

	void Update();
	void PlaceBomb(int range);
	void DestroyObjectInCell();
	XMFLOAT3 GetMiddlePos() const { return m_MiddlePos; }
	State GetState() const { return m_State; }

private:
	XMFLOAT3 m_MiddlePos{};
	float m_TimeSinceItemPlaceOnCell{};
	State m_State{};
	Grid* m_pOwnerGrid{};
	const int m_RowNr{};
	const int m_ColNr{};
	int m_BombRange{};
	GameObject* m_pGameObjectInCell{};
	bool m_ShouldAddColliderToGameObjectInCell{};

	static GameScene* m_spGameScene;
	static DiffuseMaterial* m_spBombMaterial;
	static DiffuseMaterial* m_spFlameMaterial;
	static PxMaterial* m_spPhysxMaterial;
	static float m_sSecUntilExplotion;
	static float m_sSecFireBurn;

	void ExplodeBomb();
	void PlaceFire(XMFLOAT3 pos);
	void AddColliderToGameObjectInCell();
};