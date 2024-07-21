#include "tpch.h"
#include "Asset.h"

namespace Table
{
	std::string_view AssetTypeToString(AssetType type)
	{
		switch (type)
		{
		case AssetType::None: return "AssetType::None";
		case AssetType::Scene: return "AssetType::Scene";
		case AssetType::Texture2D: return "AssetType::Texture2D";
		}

		return "AssetType:<Invalid>";
	}

	AssetType AssetTypeFromString(std::string_view assettype)
	{
		if (assettype == "AssetType::None") return AssetType::None;
		if (assettype == "AssetType::Scene") return AssetType::Scene;
		if (assettype == "AssetType::Texture2D") return AssetType::Texture2D;

		return AssetType::None;
	}
}
