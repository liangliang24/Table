#pragma once

#include "Asset.h"
#include "AssetMetadata.h"

#include "Table/Renderer/Texture.h"
namespace Table{

	class TextureImporter
	{
	public:
		static Ref<Texture2D> ImportTexture2D(AssetHandle handle, const AssetMetadata& metadata);
		static Ref<Texture2D> LoadTexture2D(const std::filesystem::path& path);
	};

}

