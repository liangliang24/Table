#include "tpch.h"
#include "Table/Renderer/Texture.h"

#include "Table/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLTexture.h"
namespace Table
{

	Table::Ref<Table::Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:
			TABLE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLTexture2D>(path);
		}
		TABLE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Table::Ref<Table::Texture2D> Texture2D::Create(const TextureSpecification& specification)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:
			TABLE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLTexture2D>(specification);
		}
		TABLE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}