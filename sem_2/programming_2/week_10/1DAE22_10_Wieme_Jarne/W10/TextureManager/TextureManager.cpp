#include "pch.h"
#include "TextureManager.h"
#include "Texture.h"

TextureManager::TextureManager()
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

Texture* TextureManager::GetTexture(const std::string& filename)
{
	if (m_TexturesMap.find(filename) == m_TexturesMap.end( ))
	{
		//texture not found in map

		m_TexturesMap[filename] = new Texture(filename);
	}

	return m_TexturesMap[filename];

	//alternatief voor hierboven
	Texture* pTexture{ m_TexturesMap[filename] };

	if (!pTexture)
	{
		m_TexturesMap[filename] = new Texture(filename);
	}

	return m_TexturesMap[filename];
}