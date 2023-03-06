#pragma once
class TorusPrefab;

class MinionScene final : public GameScene
{
public:
	MinionScene();
	~MinionScene() override = default;

	MinionScene(const MinionScene& other) = delete;
	MinionScene(MinionScene&& other) noexcept = delete;
	MinionScene& operator=(const MinionScene& other) = delete;
	MinionScene& operator=(MinionScene&& other) noexcept = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void OnGUI() override;

private:
	TorusPrefab* m_pTorusBig{};
	TorusPrefab* m_pTorusMedium{};
	TorusPrefab* m_pTorusSmall{};
};


