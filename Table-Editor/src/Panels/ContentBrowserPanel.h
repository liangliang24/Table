#pragma once

#include <filesystem>

#include "Table/Renderer/Texture.h"
#include "Table/Core/Core.h"
#include "Table/Scene/Scene.h"

namespace Table
{
	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();

		void OnImGuiRender();

		void SetContext(const Ref<Scene>& context);
	private:
		std::filesystem::path m_BaseDirectory;
		std::filesystem::path m_CurrentDirectory;

		Ref<Texture2D> m_DirectoryIcon;
		Ref<Texture2D> m_FileIcon;
		
		Ref<Scene> m_Context;
	};
}

