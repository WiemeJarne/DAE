#pragma once
class PongScene final : public GameScene
{
public:
	PongScene() : GameScene(L"PongScene") {}
	~PongScene() override = default;

	PongScene(const PongScene& other) = delete;
	PongScene(PongScene&& other) noexcept = delete;
	PongScene& operator=(const PongScene& other) = delete;
	PongScene& operator=(PongScene&& other) noexcept = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Reset();

private:
	FixedCamera* m_pFixedCamera{ nullptr };

	const float m_PeddleLenght{ 5.f };
	GameObject* m_pPeddleLeft{ nullptr };
	GameObject* m_pPeddleRight{ nullptr };
	GameObject* m_pBall{ nullptr };
};