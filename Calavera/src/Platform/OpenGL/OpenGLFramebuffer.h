#ifndef OPENGLFRAMEBUFFER_H
#define OPENGLFRAMEBUFFER_H

#include "Calavera/Renderer/Framebuffer.h"

namespace Calavera {

	class OpenGLFramebuffer : public Framebuffer
	{

		public:
			OpenGLFramebuffer(const FramebufferSpecification& spec);
			virtual ~OpenGLFramebuffer();

			void Invalidate();

			virtual void Bind() override;
			virtual void Unbind() override;

			virtual uint32_t GetcolorAttachmentRendererID() const override { return m_ColorAttachment; }

			virtual const FramebufferSpecification& GetSpecification() const override { return m_Specification; }

		private:
			uint32_t m_RendererID;
			uint32_t m_ColorAttachment, m_DepthAttachment;
			FramebufferSpecification m_Specification;

	};

}

#endif // !OPENGLFRAMEBUFFER_H
