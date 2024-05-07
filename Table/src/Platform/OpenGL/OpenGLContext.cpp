#include "tpch.h"
#include "Platform/OpenGL/OpenGLContext.h"


#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>


namespace Table
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		TABLE_CORE_ASSERT(windowHandle,"Window handle is null!!!!!")
	}

	void OpenGLContext::Init()
	{
		TABLE_PROFILE_FUNCTION();
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		TABLE_CORE_ASSERT(status, "Failed to initialize Glad!");
		glGetString(GL_VENDOR);
		TABLE_CORE_INFO("OpenGL Info:");
		TABLE_CORE_INFO(" Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		TABLE_CORE_INFO(" Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		TABLE_CORE_INFO(" Version: {0}", (const char*)glGetString(GL_VERSION));

		TABLE_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Table requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		TABLE_PROFILE_FUNCTION();
		glfwSwapBuffers(m_WindowHandle);
	}
}
