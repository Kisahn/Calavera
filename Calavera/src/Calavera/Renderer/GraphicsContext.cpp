#include "cvpch.h"
#include "Calavera/Renderer/GraphicsContext.h"

#include "Calavera/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Calavera {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    CV_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		CV_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}