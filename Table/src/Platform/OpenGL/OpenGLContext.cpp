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
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		TABLE_CORE_ASSERT(status, "Failed to initialize Glad!");
		glGetString(GL_VENDOR);
		TABLE_CORE_INFO("OpenGL Info:");
		TABLE_CORE_INFO(" Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		TABLE_CORE_INFO(" Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		TABLE_CORE_INFO(" Version: {0}", (const char*)glGetString(GL_VERSION));

#ifdef TABLE_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		TABLE_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Table requires at least OpenGL version 4.5!");
#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
