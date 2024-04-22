#include "tpch.h"
#include "VertexArray.h"

#include "Renderer.h"
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
			return std::make_shared<OpenGLVertexArray>();
		}

		TABLE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}