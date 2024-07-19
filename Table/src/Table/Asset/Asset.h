#pragma once
#include "Table/Core/UUID.h"

namespace Table {

	using AssetHandle = UUID;

	enum class AssetType
	{
		None = 0,
		Scene,
		Texture2D,
	};

	class Asset
	{
	public:
		AssetHandle Handle;

		virtual AssetType GetType() const = 0;
	};
}

