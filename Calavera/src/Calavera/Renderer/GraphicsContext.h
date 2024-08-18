#ifndef GRAPHICSCONTEXT_H
#define GRAPHICSCONTEXT_H

namespace Calavera {

	class GraphicsContext
	{
	public:
		virtual ~GraphicsContext() = default;

		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;

		static Scope<GraphicsContext> Create(void* window);
	};

}

#endif // !GRAPHICSCONTEXT_H
