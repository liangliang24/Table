#pragma once

#include "AssetMetadata.h"

namespace Table 
{
	class AssetImporter
	{
	public:
		static Ref<Asset> ImportAsset(AssetHandle handle, const AssetMetadata& metadata);
	};
}

