#pragma once
#include "Table/Core/UUID.h"

namespace Table {

	using AssetHandle = UUID;

	enum class AssetType : uint16_t
	{
		None = 0,
		Scene,
		Texture2D,
	};

	std::string_view AssetTypeToString(AssetType type);
	AssetType AssetTypeFromString(std::string_view assettype);

	class Asset
	{
	public:
		AssetHandle Handle = 0;

		virtual AssetType GetType() const = 0;
	};
}

