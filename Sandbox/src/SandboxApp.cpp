#include "Calavera.h"

#include "imgui/imgui.h"

class ExampleLayer : public Calavera::Layer
{
	public:
		ExampleLayer()
			: Layer("Example"), m_Camera(-1.6, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
		{
			m_VertexArray.reset(Calavera::VertexArray::Create());

			float vertices[3 * 7] = {
				-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
				 0.5f, -0.5f, 0.0f, 0.2f, 0.2f, 0.8f, 1.0f,
				 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
			};

			std::shared_ptr<Calavera::VertexBuffer> vertexBuffer;
			vertexBuffer.reset(Calavera::VertexBuffer::Create(vertices, sizeof(vertices)));
			Calavera::BufferLayout layout = {
				{ Calavera::ShaderDataType::Float3, "a_Position" },
				{ Calavera::ShaderDataType::Float4, "a_Color" }
			};
			vertexBuffer->SetLayout(layout);
			m_VertexArray->AddVertexBuffer(vertexBuffer);

			std::shared_ptr<Calavera::IndexBuffer> indexBuffer;
			uint32_t indices[3] = { 0, 1, 2 };
			indexBuffer.reset(Calavera::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
			m_VertexArray->SetIndexBuffer(indexBuffer);

			m_SquareVA.reset(Calavera::VertexArray::Create());

			float squareVertices[3 * 4] = {
				-0.75f, -0.75f, 0.0f,
				 0.75f, -0.75f, 0.0f,
				 0.75f,  0.75f, 0.0f,
				-0.75f,  0.75f, 0.0f
			};

			std::shared_ptr<Calavera::VertexBuffer> squareVB;
			squareVB.reset(Calavera::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
			squareVB->SetLayout({
				{ Calavera::ShaderDataType::Float3, "a_Position" }
				});
			m_SquareVA->AddVertexBuffer(squareVB);

			uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
			std::shared_ptr<Calavera::IndexBuffer> squareIB;
			squareIB.reset(Calavera::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
			m_SquareVA->SetIndexBuffer(squareIB);

			std::string vertexSrc = R"(
				#version 330 core

				layout(location = 0) in vec3 a_Position;
				layout(location = 1) in vec4 a_Color;

				uniform mat4 u_ViewProjection;

				out vec3 v_Position;
				out vec4 v_Color;

				void main()
				{
					v_Position = a_Position;
					v_Color = a_Color;
					gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
				}			
			)";

				std::string fragmentSrc = R"(
				#version 330 core

				layout(location = 0) out vec4 color;

				in vec3 v_Position;
				in vec4 v_Color;

				void main()
				{
					color = vec4(v_Position * 0.5 + 0.5, 1.0);
					color = v_Color;
				}			
			)";

				m_Shader.reset(new Calavera::Shader(vertexSrc, fragmentSrc));

				std::string blueShaderVertexSrc = R"(
				#version 330 core

				layout(location = 0) in vec3 a_Position;

				uniform mat4 u_ViewProjection;

				out vec3 v_Position;

				void main()
				{
					v_Position = a_Position;
					gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
				}			
			)";

				std::string blueShaderFragmentSrc = R"(
				#version 330 core

				layout(location = 0) out vec4 color;

				in vec3 v_Position;

				void main()
				{
					color = vec4(0.2, 0.3, 0.8, 1.0);
				}			
			)";

			m_BlueShader.reset(new Calavera::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
		}

		void OnUpdate() override
		{
			if (Calavera::Input::IsKeyPressed(CV_KEY_LEFT))
				m_CameraPosition.x -= m_CameraMoveSpeed;
			else if (Calavera::Input::IsKeyPressed(CV_KEY_RIGHT))
				m_CameraPosition.x += m_CameraMoveSpeed;

			if (Calavera::Input::IsKeyPressed(CV_KEY_UP))
				m_CameraPosition.y += m_CameraMoveSpeed;
			else if (Calavera::Input::IsKeyPressed(CV_KEY_DOWN))
				m_CameraPosition.y -= m_CameraMoveSpeed;

			if (Calavera::Input::IsKeyPressed(CV_KEY_A))
				m_CameraRotation += m_CameraRotationSpeed;
			if (Calavera::Input::IsKeyPressed(CV_KEY_E))
				m_CameraRotation -= m_CameraRotationSpeed;
			
			Calavera::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
			Calavera::RenderCommand::Clear();

			m_Camera.SetPosition(m_CameraPosition);
			m_Camera.SetRotation(m_CameraRotation);

			Calavera::Renderer::BeginScene(m_Camera);

			Calavera::Renderer::Submit(m_BlueShader, m_SquareVA);
			Calavera::Renderer::Submit(m_Shader, m_VertexArray);

			Calavera::Renderer::EndScene();
		}

		virtual void OnImGuiRender() override
		{
		}

		void OnEvent(Calavera::Event& event) override
		{
		}

	private:
		std::shared_ptr<Calavera::Shader> m_Shader;
		std::shared_ptr<Calavera::VertexArray> m_VertexArray;

		std::shared_ptr<Calavera::Shader> m_BlueShader;
		std::shared_ptr<Calavera::VertexArray> m_SquareVA;

		Calavera::OrthographicCamera m_Camera;
		glm::vec3 m_CameraPosition;
		float m_CameraMoveSpeed = 0.1f;

		float m_CameraRotation = 0.0f;
		float m_CameraRotationSpeed = 2.0f;

};

class Sandbox : public Calavera::Application
{
	public:
		Sandbox()
		{
			PushLayer(new ExampleLayer());
		}

		~Sandbox()
		{

		}
};

Calavera::Application* Calavera::CreateApplication()
{
	return new Sandbox();
}