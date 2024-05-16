#pragma once

#include <filesystem>

#include "Table/Renderer/Texture.h"
#include "Table/Core/Core.h"

namespace Table
{
	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();

		void OnImGuiRender();

	private:
		std::filesystem::path m_CurrentDirectory;

		Ref<Texture2D> m_DirectoryIcon;
		Ref<Texture2D> m_FileIcon;
	};
}

