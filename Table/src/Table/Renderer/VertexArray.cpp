#include "tpch.h"
#include "Table/Renderer/VertexArray.h"

#include "Table/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"
namespace Table
{

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			TABLE_CORE_ASSERT(false, "RendererAPI::None is currently not suppported!"); return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLVertexArray>();
		}

		TABLE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}