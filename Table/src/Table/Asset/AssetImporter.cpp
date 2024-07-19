#include "tpch.h"
#include "AssetImporter.h"

#include "TextureImporter.h"

#include "map"

namespace Table
{
	using AssetImportFunction = std::function<Ref<Asset>(AssetHandle handle, const AssetMetadata& metadata)>;
	static std::map<AssetType, AssetImportFunction> s_AssetImportFuncs =
	{
		{AssetType::Texture2D, TextureImporter::ImportTexture2D}
	};

	Ref<Asset> AssetImporter::ImportAsset(AssetHandle handle, const AssetMetadata& metadata)
	{
		if (s_AssetImportFuncs.find(metadata.Type) == s_AssetImportFuncs.end())
		{
			return nullptr;
		}

		return s_AssetImportFuncs.at(metadata.Type)(handle, metadata);
	}

}