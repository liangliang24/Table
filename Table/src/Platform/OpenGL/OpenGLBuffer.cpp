#include "tpch.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

#include "glad/glad.h"

namespace Table
{

	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size)
	{
		TABLE_PROFILE_FUNCTION();
		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		TABLE_PROFILE_FUNCTION();
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		TABLE_PROFILE_FUNCTION();
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLVertexBuffer::UnBind() const
	{
		TABLE_PROFILE_FUNCTION();
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count)
		:m_Count(count)
	{
		TABLE_PROFILE_FUNCTION();
		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, count*sizeof(uint32_t), indices, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		TABLE_PROFILE_FUNCTION();
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLIndexBuffer::Bind() const
	{
		TABLE_PROFILE_FUNCTION();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLIndexBuffer::UnBind() const
	{
		TABLE_PROFILE_FUNCTION();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}
