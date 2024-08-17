#include "cvpch.h"
#include "Framebuffer.h"

#include "Calavera/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace Calavera {

	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch(Renderer::GetAPI())
		{
			case RendererAPI::API::None:       CV_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:     return CreateRef<OpenGLFramebuffer>(spec);
		}

		CV_CORE_ASSERT(false, "Uknown RendererAPI");
		return nullptr;
	}

}