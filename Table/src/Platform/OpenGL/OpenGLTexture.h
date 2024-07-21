#pragma once
#include "Table/Renderer/Texture.h"
#include <string>

#include <glad/glad.h>
namespace Table
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(const TextureSpecification& specification,  Buffer data = Buffer());
		virtual ~OpenGLTexture2D();

		virtual const TextureSpecification& GetSpecification() const override { return m_Specification; }

		virtual uint32_t GetWidth() const override { return m_Width; }
		virtual uint32_t GetHeight() const override { return m_Height; }

		void Bind(uint32_t slot = 0) const override;

		virtual bool IsLoaded() const override { return m_IsLoaded; }

		void SetData(Buffer data) override;

		virtual bool operator==(const Texture& other) const override
		{
			return m_RendererID == other.GetRendererID();
		}

		uint32_t GetRendererID() const override { return m_RendererID; }

	private:
		TextureSpecification m_Specification;

		bool m_IsLoaded = false;
		uint32_t m_Width, m_Height;
		uint32_t m_RendererID;
		GLenum m_InternalFormat = 0, m_DataFormat = 0;
	};
}

