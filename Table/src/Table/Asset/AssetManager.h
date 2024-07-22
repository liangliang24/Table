#pragma once

#include "AssetManagerBase.h"

#include "Table/Project/Project.h"

namespace Table{
	class AssetManager
	{
	public:
		
		template<typename T>
		static Ref<T> GetAsset(AssetHandle handle)
		{
			return std::static_pointer_cast<T>(Project::GetActive()->GetAssetManager()->GetAsset(handle));
		}
		static bool IsAssetHandleValid(AssetHandle handle) { return Project::GetActive()->GetAssetManager()->IsAssetHandleValid(handle); }
		static bool IsAssetLoaded(AssetHandle handle) { return Project::GetActive()->GetAssetManager()->IsAssetLoaded(handle); }
		static AssetType GetAssetType(AssetHandle handle) { return Project::GetActive()->GetAssetManager()->GetAssetType(handle); }
	};
}

