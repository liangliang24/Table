#include "tpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"
namespace Table
{

	Table::VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			TABLE_CORE_ASSERT(false, "RendererAPI::None is currently not suppported!"); return nullptr;
		case RendererAPI::OpenGL:
			return new OpenGLVertexArray();
		default:
			break;
		}
	}

}