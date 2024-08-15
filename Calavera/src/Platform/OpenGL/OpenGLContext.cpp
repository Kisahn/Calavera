#include "cvpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include "glad/glad.h"

namespace Calavera {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		CV_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		CV_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		CV_CORE_ASSERT(status, "Failed to initialize Glad!");

		CV_CORE_INFO("OpenGL Info:");
		CV_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		CV_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		CV_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));

		#ifdef CV_ENABLE_ASSERTS
			int versionMajor;
			int versionMinor;
			glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
			glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

			CV_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Calavera requires at lest OpenGL version 4.")
		#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		CV_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}