#include "pch.h"
#include "TextureManager.h"
#include "Texture.h"

TextureManager::~TextureManager( )
{
	//destroy a;; textures
}

Texture* TextureManager::GetTexture(const std::string& filename)
{
	if (m_Map.find(filename) == m_Map.end( ))
	{
		//texture not found in map

		m_Map[filename] = new Texture(filename);
	}

	return m_Map[filename];

	//alternatief voor hierboven
	Texture* pTexture{ m_Map[filename] };

	if (!pTexture)
	{
		m_Map[filename] = new Texture(filename);
	}

	return m_Map[filename];
}