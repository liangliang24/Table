#include "tpch.h"
#include "Table/Renderer/GraphicsContext.h"
#include "Table/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"
#include "GLFW/glfw3.h"

namespace Table
{

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			TABLE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;

		case RendererAPI::API::OpenGL:
			return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		TABLE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}