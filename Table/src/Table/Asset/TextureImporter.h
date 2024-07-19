#pragma once

#include "Asset.h"
#include "AssetMetadata.h"

namespace Table{

	class TextureImporter
	{
	public:
	};

	Ref<Asset> ImportTexture2D(AssetHandle handle, const AssetMetadata& metadata);
}

