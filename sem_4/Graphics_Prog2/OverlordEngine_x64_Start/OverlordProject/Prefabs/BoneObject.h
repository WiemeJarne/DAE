#pragma once

class BoneObject final : public GameObject
{
public:
	BoneObject(BaseMaterial* pMaterial, float lenght = 5.f);
	~BoneObject() override = default;

	BoneObject(const BoneObject& other) = delete;
	BoneObject(BoneObject&& other) noexcept = delete;
	BoneObject& operator=(const BoneObject& other) = delete;
	BoneObject& operator=(BoneObject&& other) noexcept = delete;

	void AddBone(BoneObject* pBone);
	void CalculateBindPose();
	const XMFLOAT4X4& GetBindPose() const { return m_BindPose; }

protected:
	void Initialize(const SceneContext&) override;

private:
	float m_Lenght{};
	BaseMaterial* m_pMaterial{};
	XMFLOAT4X4 m_BindPose{};
};