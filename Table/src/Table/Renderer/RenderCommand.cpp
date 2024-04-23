#include "tpch.h"
#include "Table/Renderer/RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Table
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}