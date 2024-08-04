#ifndef OPENGLRENDERERAPI_H
#define OPENGLRENDERERAPI_H

#include "Calavera/Renderer/RendererAPI.h"

namespace Calavera {

	class OpenGLRendererAPI : public RendererAPI
	{
		public:
			virtual void SetClearColor(const glm::vec4& color) override;
			virtual void Clear() override;

			virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;

	};

}

#endif // !OPENGLRENDERERAPI_H
