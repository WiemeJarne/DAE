#include "stdafx.h"
#include "SpriteFontLoader.h"

SpriteFont* SpriteFontLoader::LoadContent(const ContentLoadInfo& loadInfo)
{
	const auto pReader = new BinaryReader();
	pReader->Open(loadInfo.assetFullPath);

	if (!pReader->Exists())
	{
		Logger::LogError(L"Failed to read the assetFile!\nPath: \'{}\'", loadInfo.assetSubPath);
		return nullptr;
	}

	//See BMFont Documentation for Binary Layout

	//Parse the Identification bytes (B,M,F)
	//If Identification bytes doesn't match B|M|F,
	if (pReader->Read<char>() != 'B' || pReader->Read<char>() != 'M' || pReader->Read<char>() != 'F')
	{
		//Log Error (SpriteFontLoader::LoadContent > Not a valid .fnt font) &
		Logger::LogError(L"SpriteFontLoader::LoadContent > Not a valid .fnt font\nPath: \'{}\'", loadInfo.assetSubPath);
		//return nullptr
		return nullptr;
	}

	//Parse the version (version 3 required)
	//If version is < 3,
	if (pReader->Read<char>() < 3)
	{
		//Log Error (SpriteFontLoader::LoadContent > Only .fnt version 3 is supported)
		Logger::LogError(L"SpriteFontLoader::LoadContent > Only .fnt version 3 is supported\nPath: \'{}\'", loadInfo.assetSubPath);
		//return nullptr
		return nullptr;
	}

	//Valid .fnt file >> Start Parsing!
	//use this SpriteFontDesc to store all relevant information (used to initialize a SpriteFont object)
	SpriteFontDesc fontDesc{};

	//**********
	// BLOCK 0 *
	//**********
	//Retrieve the blockId and blockSize
	//char blockId{ pReader->Read<char>() };
	//int blockSize{ pReader->Read<int>() };
	pReader->MoveBufferPosition(5);
	//Retrieve the FontSize [fontDesc.fontSize]
	fontDesc.fontSize = pReader->Read<short>();
	//Move the binreader to the start of the FontName [BinaryReader::MoveBufferPosition(...) or you can set its position using BinaryReader::SetBufferPosition(...))
	pReader->MoveBufferPosition(12);
	//Retrieve the FontName [fontDesc.fontName]
	fontDesc.fontName = pReader->ReadNullString();

	//**********
	// BLOCK 1 *
	//**********
	//Retrieve the blockId and blockSize
	//blockId = pReader->Read<char>();
	//blockSize = pReader->Read<int>();
	pReader->MoveBufferPosition(5);
	//Retrieve Texture Width & Height [fontDesc.textureWidth/textureHeight]
	pReader->MoveBufferPosition(4);
	fontDesc.textureWidth = pReader->Read<short>();
	fontDesc.textureHeight = pReader->Read<short>();
	//Retrieve PageCount
	short pageCount{ pReader->Read<short>() };
	//> if pageCount > 1
	if (pageCount > 1)
	{
		//	> Log Error (Only one texture per font is allowed!)
		Logger::LogError(L"SpriteFontLoader::LoadContent > Only one texture per font is allowed!\nPath: \'{}\'", loadInfo.assetSubPath);
	}
	
	//Advance to Block2 (Move Reader)
	pReader->MoveBufferPosition(5);

	//**********
	// BLOCK 2 *
	//**********
	//Retrieve the blockId and blockSize
	//blockId = pReader->Read<char>();
	//blockSize = pReader->Read<int>();
	pReader->MoveBufferPosition(5);
	//Retrieve the PageName (BinaryReader::ReadNullString)
	auto pageName{ pReader->ReadNullString() };
	//Construct the full path to the page texture file
	//	>> page texture should be stored next to the .fnt file, pageName contains the name of the texture file
	//	>> full texture path = asset parent_path of .fnt file (see loadInfo.assetFullPath > get parent_path) + pageName (filesystem::path::append)
	auto parentPath = std::filesystem::path(loadInfo.assetFullPath).parent_path();
	const auto& texturePath = parentPath.append(pageName);
	//	>> Load the texture (ContentManager::Load<TextureData>) & Store [fontDesc.pTexture]
	fontDesc.pTexture = ContentManager::Load<TextureData>(texturePath);

	//**********
	// BLOCK 3 *
	//**********
	//Retrieve the blockId and blockSize
	//blockId = pReader->Read<char>();
	pReader->MoveBufferPosition(1);
	auto blockSize = pReader->Read<int>();
	//Retrieve Character Count (see documentation)
	int characterCount{ blockSize / static_cast<int>(sizeof(FontMetric)) };
	//Create loop for Character Count, and:
	for (int index{}; index < characterCount; ++index)
	{
		//> Retrieve CharacterId (store Local) and cast to a 'wchar_t'
		wchar_t charId = static_cast<wchar_t>(pReader->Read<int>());
		//> Create instance of FontMetric (struct)
		FontMetric fontMetric{};
		//	> Set Character (CharacterId) [FontMetric::character]
		fontMetric.character = charId;
		//	> Retrieve Xposition (store Local)
		auto xPos{ pReader->Read<short>() };
		//	> Retrieve Yposition (store Local)
		auto yPos{ pReader->Read<short>() };
		//	> Retrieve & Set Width [FontMetric::width]
		fontMetric.width = pReader->Read<short>();
		//	> Retrieve & Set Height [FontMetric::height]
		fontMetric.height = pReader->Read<short>();
		//	> Retrieve & Set OffsetX [FontMetric::offsetX]
		fontMetric.offsetX = pReader->Read<short>();
		//	> Retrieve & Set OffsetY [FontMetric::offsetY]
		fontMetric.offsetY = pReader->Read<short>();
		//	> Retrieve & Set AdvanceX [FontMetric::advanceX]
		fontMetric.advanceX = pReader->Read<short>();
		//	> Retrieve & Set Page [FontMetric::page]
		fontMetric.page = pReader->Read<unsigned char>();
		//	> Retrieve Channel (BITFIELD!!!) 
		//		> See documentation for BitField meaning [FontMetrix::channel]
		switch (const unsigned char channelBitField{ pReader->Read<unsigned char>() })
		{
		case 1:
			fontMetric.channel = 2; //blue channel
			break;
		case 2:
			fontMetric.channel = 1; //green channel
			break;
		case 4:
			fontMetric.channel = 0; //red channel
			break;
		case 8:
			fontMetric.channel = 4; //alpha channel
			break;
		case 15:
			fontMetric.channel = 0; //is in all channels so channel number can be [0-4]
			break;
		}
		//	> Calculate Texture Coordinates using Xposition, Yposition, fontDesc.TextureWidth & fontDesc.TextureHeight [FontMetric::texCoord]
		const float texCoordX = static_cast<float>(xPos) / fontDesc.textureWidth;
		const float texCoordY = static_cast<float>(yPos) / fontDesc.textureHeight;
		fontMetric.texCoord = DirectX::XMFLOAT2(texCoordX, texCoordY);
		//> Insert new FontMetric to the metrics [font.metrics] map
		//	> key = (wchar_t) charId
		//	> value = new FontMetric
		fontDesc.metrics[charId] = fontMetric;
		//(loop restarts till all metrics are parsed)
	}

	//Done!
	delete pReader;
	return new SpriteFont(fontDesc);
}

void SpriteFontLoader::Destroy(SpriteFont* objToDestroy)
{
	SafeDelete(objToDestroy);
}
