#include "tpch.h"
#include "Shader.h"


#include "RendererAPI.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Table
{
	Shader* Shader::create(const std::string& vertexSrc, const std::string fragmentSrc)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:
			TABLE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return new OpenGLShader(vertexSrc, fragmentSrc);
		}
		TABLE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
