#include "tpch.h"
#include "Platform/OpenGL/OpenGLTexture.h"

#include <stb_image.h>
#include "glad/glad.h"
namespace Table
{
	namespace Utils {

		static GLenum TableImageFormatToGLDataFormat(ImageFormat format)
		{
			switch (format)
			{
			case ImageFormat::RGB8:  return GL_RGB;
			case ImageFormat::RGBA8: return GL_RGBA;
			}

			TABLE_CORE_ASSERT(false);
			return 0;
		}

		static GLenum TableImageFormatToGLInternalFormat(ImageFormat format)
		{
			switch (format)
			{
			case ImageFormat::RGB8:  return GL_RGB8;
			case ImageFormat::RGBA8: return GL_RGBA8;
			}

			TABLE_CORE_ASSERT(false);
			return 0;
		}

	}

	OpenGLTexture2D::OpenGLTexture2D(const TextureSpecification& specification, Buffer data)
		: m_Specification(specification), m_Width(m_Specification.Width), m_Height(m_Specification.Height)
	{
		TABLE_PROFILE_FUNCTION();
		m_InternalFormat = Utils::TableImageFormatToGLInternalFormat(m_Specification.Format);;
		m_DataFormat = Utils::TableImageFormatToGLDataFormat(m_Specification.Format);;

		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, m_InternalFormat, m_Width, m_Height);

		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);

		if (data)
		{
			SetData(data);
		}
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		TABLE_PROFILE_FUNCTION();
		glDeleteTextures(1, &m_RendererID);
	}

	void OpenGLTexture2D::Bind(uint32_t slot /*= 0*/) const
	{
		TABLE_PROFILE_FUNCTION();
		glBindTextureUnit(slot, m_RendererID);
	}

	void OpenGLTexture2D::SetData(Buffer data)
	{
		TABLE_PROFILE_FUNCTION();
		uint32_t bpp = m_DataFormat == GL_RGBA ? 4 : 3;
		TABLE_CORE_ASSERT(data.Size == m_Width * m_Height * bpp, "Data must be entire texture");

		glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, m_DataFormat, GL_UNSIGNED_BYTE, data.Data);
	}

}