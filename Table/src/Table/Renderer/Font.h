#pragma once


#include <filesystem>

#include "Table/Core/Core.h"
#include "Table/Renderer/Texture.h"

namespace Table
{
	struct MSDFData;

	class Font
	{
	public:
		Font(const std::filesystem::path& font);
		~Font();
		
		Ref<Texture2D> GetAtlasTexture() const { return m_AtlasTexture; }

	private:
		MSDFData* m_Data;
		Ref<Texture2D> m_AtlasTexture;
	};
}

