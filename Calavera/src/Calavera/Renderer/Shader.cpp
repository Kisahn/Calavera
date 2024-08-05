#include "cvpch.h"
#include "Shader.h"

#include "glad/glad.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Calavera {

	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:       CV_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:     return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		CV_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}