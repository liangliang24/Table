#include "tpch.h"
#include "Table/Renderer/Framebuffer.h"
#include "Table/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLFramebuffer.h"
namespace Table
{

	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			TABLE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLFramebuffer>(spec);
		}
		TABLE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}