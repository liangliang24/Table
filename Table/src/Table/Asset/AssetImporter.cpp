#include "tpch.h"
#include "AssetImporter.h"

#include "TextureImporter.h"
#include "SceneImporter.h"

#include "map"


namespace Table
{
	using AssetImportFunction = std::function<Ref<Asset>(AssetHandle handle, const AssetMetadata& metadata)>;
	static std::map<AssetType, AssetImportFunction> s_AssetImportFuncs =
	{
		{AssetType::Texture2D, TextureImporter::ImportTexture2D},
		{AssetType::Scene, SceneImporter::ImportScene}
	};

	Ref<Asset> AssetImporter::ImportAsset(AssetHandle handle, const AssetMetadata& metadata)
	{
		if (s_AssetImportFuncs.find(metadata.Type) == s_AssetImportFuncs.end())
		{
			TABLE_CORE_ERROR("No importer available for asset type: {}", (uint16_t)metadata.Type);
			return nullptr;
		}

		return s_AssetImportFuncs.at(metadata.Type)(handle, metadata);
	}

}