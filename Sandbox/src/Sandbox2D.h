#ifndef SANDBOX2D_H
#define SANDBOX2D_H

#include "Calavera.h"

class Sandbox2D : public Calavera::Layer
{
	public:
		Sandbox2D();
		virtual ~Sandbox2D() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Calavera::Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Calavera::Event& e) override;

private:
	Calavera::OrthographicCameraController m_CameraController;

	// Temp
	Calavera::Ref<Calavera::VertexArray> m_SquareVA;
	Calavera::Ref<Calavera::Shader> m_FlatColorShader;

	Calavera::Ref<Calavera::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

};

#endif // !SANDBOX2D_H

