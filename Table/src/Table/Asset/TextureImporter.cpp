#include "tpch.h"
#include "TextureImporter.h"
#include "Table/Project/Project.h"

#include "stb_image.h"
#include <filesystem>


namespace Table
{

	Ref<Texture2D> TextureImporter::ImportTexture2D(AssetHandle handle, const AssetMetadata& metadata)
	{

		return LoadTexture2D(Project::GetAssetDirectory() / metadata.FilePath);
	}

	Ref<Texture2D> TextureImporter::LoadTexture2D(const std::filesystem::path& path)
	{
		int width, height, channels;
		stbi_set_flip_vertically_on_load(1);
		Buffer data;
		{
			TABLE_PROFILE_SCOPE("stbi_load - TextureImporter::ImportTexture2D");
			std::string pathStr = path.string();
			data.Data = stbi_load(pathStr.c_str(), &width, &height, &channels, 0);
		}

		if (data.Data == nullptr)
		{
			TABLE_CORE_ERROR("TextureImporter::ImporterTexture2D - Could not load texture from filepath {}", path.string());
			return nullptr;
		}

		data.Size = width * height * channels;

		TextureSpecification spec;
		spec.Width = width;
		spec.Height = height;
		switch (channels)
		{
		case 3:
			spec.Format = ImageFormat::RGB8;
			break;
		case 4:
			spec.Format = ImageFormat::RGBA8;
			break;
		}

		Ref<Texture2D> texture = Texture2D::Create(spec, data);
		data.Release();

		return texture;
	}

}