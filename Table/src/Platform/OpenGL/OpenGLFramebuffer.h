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

		virtual void ClearAttachment(uint32_t attachmentIndex, int value) override;

		uint32_t GetColorAttachmentRendererID(uint32_t index = 0) const override 
		{ 
			TABLE_CORE_ASSERT(index < m_ColorAttachments.size());
			return m_ColorAttachments[index];
		};
		const FramebufferSpecification& GetSpecification() const override { return m_Specification; };


		void Resize(uint32_t width, uint32_t height) override;
		virtual int ReadPixel(uint32_t attachmentIndex, int x, int y) override;

	private:
		uint32_t m_RendererID = 0;
		FramebufferSpecification m_Specification;

		std::vector<FramebufferTextureSpecification> m_ColorAttachmentSpecifications;
		FramebufferTextureSpecification m_DepthAttachmentSpecification = FramebufferTextureFormat::None;

		std::vector<uint32_t> m_ColorAttachments;
		uint32_t m_DepthAttachment = 0;
	};
}

