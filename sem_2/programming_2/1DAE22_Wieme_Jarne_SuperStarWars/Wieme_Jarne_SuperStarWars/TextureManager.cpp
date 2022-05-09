#include "pch.h"
#include "TextureManager.h"
#include "Texture.h"

TextureManager::TextureManager( )
	: m_TexturesMap{ }
{

}

TextureManager::~TextureManager()
{
	for (std::pair<std::string, Texture*> pair : m_TexturesMap)
	{
		delete pair.second;
	}
}

Texture* TextureManager::GetTexture(const std::string& filename)
{
	Texture* pTexture{ m_TexturesMap[filename] };

	if (!pTexture)
	{
		m_TexturesMap[filename] = new Texture(filename);
	}

	return m_TexturesMap[filename];
}