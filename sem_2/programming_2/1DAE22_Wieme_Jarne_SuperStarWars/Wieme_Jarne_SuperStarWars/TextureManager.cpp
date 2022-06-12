#include "pch.h"
#include "TextureManager.h"
#include "Texture.h"

TextureManager::TextureManager( )
	: m_TexturesMap{ }
{
}

TextureManager::~TextureManager( )
{
	for (std::pair<std::string, Texture*> pair : m_TexturesMap)
	{
		delete pair.second;
	}
}

Texture* TextureManager::GetTexture(const std::string& fileName)
{
	Texture* pTexture{ m_TexturesMap[fileName] };

	if (!pTexture)
	{
		m_TexturesMap[fileName] = new Texture(fileName);
	}

	return m_TexturesMap[fileName];
}

void TextureManager::DeleteTexture(const std::string& fileName)
{
	delete m_TexturesMap[fileName];
	m_TexturesMap[fileName] = nullptr;
}