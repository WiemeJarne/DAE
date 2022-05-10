#pragma once
#include <unordered_map>

class Texture;

using unorderedMap = std::unordered_map<std::string, Texture*>;

class TextureManager final
{
public:
	TextureManager( );

	~TextureManager( );
	TextureManager(const TextureManager& other) = delete;
	TextureManager& operator=(const TextureManager& other) = delete;
	TextureManager(TextureManager&& other) = delete;
	TextureManager& operator=(TextureManager&& other) = delete;

	Texture* GetTexture(const std::string& filename);

private:
	unorderedMap m_TexturesMap;
};