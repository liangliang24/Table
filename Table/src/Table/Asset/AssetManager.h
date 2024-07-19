#pragma once

#include "AssetManagerBase.h"

#include "Table/Project/Project.h"

namespace Table{
	class AssetManager
	{
	public:
		static bool IsAssetHandleValid(AssetHandle handle) { return Project::GetActive()->GetAssetManager()->IsAssetHandleValid(handle); }
		template<typename T>
		static Ref<T> GetAsset(AssetHandle handle)
		{
			return std::static_pointer_cast<T>(Project::GetActive()->GetAssetManager()->GetAsset(handle));
		}
	};
}

