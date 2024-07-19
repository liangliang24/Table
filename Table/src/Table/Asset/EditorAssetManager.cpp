#include "tpch.h"
#include "EditorAssetManager.h"

namespace Table
{

	bool EditorAssetManager::IsAssetHandleValid(AssetHandle handle) const
	{
		return m_AssetRegistry.find(handle) != m_AssetRegistry.end();
	}

	bool EditorAssetManager::IsAssetLoaded(AssetHandle handle) const
	{
		return m_LoadedAssets.find(handle) != m_LoadedAssets.end();
	}

	const Table::AssetMetadata& EditorAssetManager::GetMetadata(AssetHandle handle) const
	{
		static AssetMetadata s_NullMetadata;
		auto it = m_AssetRegistry.find(handle);
		if (it == m_AssetRegistry.end())
		{
			return s_NullMetadata;
		}

		return it->second;
	}

	Ref<Asset> EditorAssetManager::GetAsset(AssetHandle handle) const
	{
		if (!IsAssetHandleValid(handle))
		{
			return nullptr;
		}

		Ref<Asset> asset;
		if (IsAssetLoaded(handle))
		{
			asset = m_LoadedAssets.at(handle);
		}
		else
		{
			const AssetMetadata& metadata = GetMetadata(handle);
			Ref<Asset> asset = AssetImporter::ImportAsset(handle, metadata);
			if (!asset)
			{
			}
		}
		return asset;
	}
}
