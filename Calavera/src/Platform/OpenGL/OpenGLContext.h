#pragma once

#include "Calavera/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Calavera {

	class OpenGLContext : public GraphicsContext
	{
		public:
			OpenGLContext(GLFWwindow* windowHandle);

			virtual void Init() override;
			virtual void SwapBuffers() override;

		private:
			GLFWwindow* m_WindowHandle;
	};

}
