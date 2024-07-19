#pragma once

#include <string>
#include <filesystem>

#include "Table/Core/Core.h"
#include "Table/Asset/AssetManagerBase.h"
#include "Table/Asset/EditorAssetManager.h"
#include "Table/Asset/RuntimeAssetManager.h"

namespace Table {

	struct ProjectConfig
	{
		std::string Name = "Untitled";

		std::filesystem::path StartScene;

		std::filesystem::path AssetDirectory;
		std::filesystem::path ScriptModulePath;
	};

	class Project
	{
	public:
		static const std::filesystem::path& GetProjectDirectory()
		{
			TABLE_CORE_ASSERT(s_ActiveProject);
			return s_ActiveProject->m_ProjectDirectory;
		}

		static std::filesystem::path GetAssetDirectory()
		{
			TABLE_CORE_ASSERT(s_ActiveProject);
			return GetProjectDirectory() / s_ActiveProject->m_Config.AssetDirectory;
		}

		static void RemoveProjectDirectory(std::filesystem::path& path)
		{
			TABLE_CORE_ASSERT(s_ActiveProject);
			path = path.lexically_relative(s_ActiveProject->m_ProjectDirectory);
		}

		static void RemoveAssetDirectory(std::filesystem::path& path)
		{
			TABLE_CORE_ASSERT(s_ActiveProject);
			path = path.lexically_relative(s_ActiveProject->m_Config.AssetDirectory);
		}

		static void TranslateToRelativePath(std::filesystem::path& path)
		{
			TABLE_CORE_ASSERT(s_ActiveProject);
			RemoveProjectDirectory(path);
			RemoveAssetDirectory(path);
		}

		// TODO(Yan): move to asset manager when we have one
		static std::filesystem::path GetAssetFileSystemPath(const std::filesystem::path& path)
		{
			TABLE_CORE_ASSERT(s_ActiveProject);
			return GetAssetDirectory() / path;
		}

		ProjectConfig& GetConfig() { return m_Config; }

		static Ref<Project> GetActive() { return s_ActiveProject; }
		std::shared_ptr<AssetManagerBase> GetAssetManager() { return m_AssetManager; }
		std::shared_ptr<RuntimeAssetManager> GetEditorAssetManager() { return std::static_pointer_cast<RuntimeAssetManager>(m_AssetManager); }
		std::shared_ptr<EditorAssetManager> GetRuntimeAssetManager() { return std::static_pointer_cast<EditorAssetManager>(m_AssetManager); }

		static Ref<Project> New();
		static Ref<Project> Load(const std::filesystem::path& path);
		static bool SaveActive(const std::filesystem::path& path);
	private:
		ProjectConfig m_Config;
		std::filesystem::path m_ProjectDirectory;
		std::shared_ptr<AssetManagerBase> m_AssetManager;

		inline static Ref<Project> s_ActiveProject;
	};

}
