#include "cvpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

namespace Calavera{

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		CV_CORE_ASSERT(windowHandle, "Window handle is null !");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		CV_CORE_ASSERT(status, "Failed to initialize Glad !");

		CV_CORE_INFO("OpenGL Info:");
		CV_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		CV_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		CV_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}
