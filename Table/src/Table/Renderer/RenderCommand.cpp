#include "tpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Table
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}