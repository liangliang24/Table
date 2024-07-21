#pragma once

#include <filesystem>

#include "Table/Renderer/Texture.h"
#include "Table/Core/Core.h"
#include "Table/Scene/Scene.h"

#include "map"
#include "set"

namespace Table
{
	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();

		void OnImGuiRender();

		void SetContext(const Ref<Scene>& context);
	private:
		void RefreshAssetTree();

		std::filesystem::path m_BaseDirectory;
		std::filesystem::path m_CurrentDirectory;

		Ref<Texture2D> m_DirectoryIcon;
		Ref<Texture2D> m_FileIcon;
		
		Ref<Scene> m_Context;

		struct TreeNode
		{
			std::filesystem::path Path;
			
			uint32_t Parent = (uint32_t)-1;

			std::map<std::filesystem::path, uint32_t> Children;

			TreeNode(const std::filesystem::path& path)
				: Path(path) {}
		};

		std::vector<TreeNode> m_TreeNodes;

		std::map<std::filesystem::path, std::vector<std::filesystem::path>> m_AssetTree;

		enum class Mode
		{
			Asset = 0, FileSystem = 1
		};

		Mode m_Mode = Mode::Asset;
	};
}

