#ifndef OPENGLCONTEXT_H
#define OPENGLCONTEXT_H

#include "Calavera/Renderer/GraphicsContext.h"
#include "Calavera/Log.h"

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

#endif // !OPENGLCONTEXT_H
