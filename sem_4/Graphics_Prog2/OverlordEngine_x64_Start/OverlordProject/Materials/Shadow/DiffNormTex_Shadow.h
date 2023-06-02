#pragma once
class DiffNormTex_Shadow final : public Material<DiffNormTex_Shadow>
{
public:
	DiffNormTex_Shadow();
	~DiffNormTex_Shadow() override = default;

	DiffNormTex_Shadow(const DiffNormTex_Shadow& other) = delete;
	DiffNormTex_Shadow(DiffNormTex_Shadow&& other) noexcept = delete;
	DiffNormTex_Shadow& operator=(const DiffNormTex_Shadow& other) = delete;
	DiffNormTex_Shadow& operator=(DiffNormTex_Shadow&& other) noexcept = delete;

	void SetDiffuseTexture(const std::wstring& assetFile);
	void SetNormalMap(const std::wstring& assetFile);

protected:
	void InitializeEffectVariables() override;
	void OnUpdateModelVariables(const SceneContext&, const ModelComponent*) const override;

private:
	TextureData* m_pDiffuseTexture{};
	TextureData* m_pSpecularTexture{};
	TextureData* m_pNormalMap{};
};