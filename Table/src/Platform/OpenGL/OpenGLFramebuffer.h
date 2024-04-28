#pragma once
#include "Table/Renderer/Framebuffer.h"
namespace Table
{
	class OpenGLFramebuffer :
		public Framebuffer
	{
	public:
		OpenGLFramebuffer(const FramebufferSpecification& spec);
		~OpenGLFramebuffer();

		void Invalidate();

		void Bind() override;
		void Unbind() override;


		uint32_t GetColorAttachmentRendererID() const override { return m_ColorAttachment; };
		const FramebufferSpecification& GetSpecification() const override { return m_Specification; };


		void Resize(uint32_t width, uint32_t height) override;

	private:
		uint32_t m_RendererID = 0;
		uint32_t m_ColorAttachment = 0, m_DepthAttachment = 0;
		FramebufferSpecification m_Specification;
	};
}

