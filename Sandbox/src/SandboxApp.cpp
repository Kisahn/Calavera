#include "Calavera.h"

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

			Calavera::Ref<Calavera::VertexBuffer> vertexBuffer;
			vertexBuffer.reset(Calavera::VertexBuffer::Create(vertices, sizeof(vertices)));
			Calavera::BufferLayout layout = {
				{ Calavera::ShaderDataType::Float3, "a_Position" },
				{ Calavera::ShaderDataType::Float4, "a_Color" }
			};
			vertexBuffer->SetLayout(layout);
			m_VertexArray->AddVertexBuffer(vertexBuffer);

			Calavera::Ref<Calavera::IndexBuffer> indexBuffer;
			uint32_t indices[3] = { 0, 1, 2 };
			indexBuffer.reset(Calavera::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
			m_VertexArray->SetIndexBuffer(indexBuffer);

			m_SquareVA.reset(Calavera::VertexArray::Create());

			float squareVertices[5 * 4] = {
				-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
				 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
				 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
				-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
			};

			Calavera::Ref<Calavera::VertexBuffer> squareVB;
			squareVB.reset(Calavera::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
			squareVB->SetLayout({
				{ Calavera::ShaderDataType::Float3, "a_Position" },
				{ Calavera::ShaderDataType::Float2, "a_TextCoord" }
				});
			m_SquareVA->AddVertexBuffer(squareVB);

			uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
			Calavera::Ref<Calavera::IndexBuffer> squareIB;
			squareIB.reset(Calavera::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
			m_SquareVA->SetIndexBuffer(squareIB);

			std::string vertexSrc = R"(
				#version 330 core

				layout(location = 0) in vec3 a_Position;
				layout(location = 1) in vec4 a_Color;

				uniform mat4 u_ViewProjection;
				uniform mat4 u_Transform;

				out vec3 v_Position;
				out vec4 v_Color;

				void main()
				{
					v_Position = a_Position;
					v_Color = a_Color;
					gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
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

				m_Shader = Calavera::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

				std::string flatColorShaderVertexSrc = R"(
				#version 330 core

				layout(location = 0) in vec3 a_Position;

				uniform mat4 u_ViewProjection;
				uniform mat4 u_Transform;

				out vec3 v_Position;

				void main()
				{
					v_Position = a_Position;
					gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
				}			
			)";

				std::string flatColorShaderFragmentSrc = R"(
				#version 330 core

				layout(location = 0) out vec4 color;

				in vec3 v_Position;

				uniform vec3 u_Color;

				void main()
				{
					color = vec4(u_Color, 1.0);
				}			
			)";

			m_FlatColorShader = Calavera::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

			auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

			m_Texture = Calavera::Texture2D::Create("assets/textures/Checkerboard.png");
			m_CalaveraLogoTexture = Calavera::Texture2D::Create("assets/textures/CalaveraLogo.png");

			std::dynamic_pointer_cast<Calavera::OpenGLShader>(textureShader)->Bind();
			std::dynamic_pointer_cast<Calavera::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
		}

		void OnUpdate(Calavera::Timestep ts) override
		{
			if (Calavera::Input::IsKeyPressed(CV_KEY_LEFT))
				m_CameraPosition.x -= m_CameraMoveSpeed * ts;
			else if (Calavera::Input::IsKeyPressed(CV_KEY_RIGHT))
				m_CameraPosition.x += m_CameraMoveSpeed * ts;

			if (Calavera::Input::IsKeyPressed(CV_KEY_UP))
				m_CameraPosition.y += m_CameraMoveSpeed * ts;
			else if (Calavera::Input::IsKeyPressed(CV_KEY_DOWN))
				m_CameraPosition.y -= m_CameraMoveSpeed * ts;

			if (Calavera::Input::IsKeyPressed(CV_KEY_A))
				m_CameraRotation += m_CameraRotationSpeed * ts;
			if (Calavera::Input::IsKeyPressed(CV_KEY_E))
				m_CameraRotation -= m_CameraRotationSpeed * ts;
			
			Calavera::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
			Calavera::RenderCommand::Clear();

			m_Camera.SetPosition(m_CameraPosition);
			m_Camera.SetRotation(m_CameraRotation);

			Calavera::Renderer::BeginScene(m_Camera);

			static glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

			glm::vec4 redColor(0.8f, 0.2f, 0.3f, 1.0f);
			glm::vec4 blueColor(0.2f, 0.3f, 0.8f, 1.0f);

			std::dynamic_pointer_cast<Calavera::OpenGLShader>(m_FlatColorShader)->Bind();
			std::dynamic_pointer_cast<Calavera::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

			for (int y = 0; y < 20; y++)
			{
				for (int x = 0; x < 20; x++)
				{
					glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
					glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
					Calavera::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
				}
			}

			auto textureShader = m_ShaderLibrary.Get("Texture");

			m_Texture->Bind();
			Calavera::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
			m_CalaveraLogoTexture->Bind();
			Calavera::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

			// Triangle
			// Calavera::Renderer::Submit(m_Shader, m_VertexArray);

			Calavera::Renderer::EndScene();
		}

		virtual void OnImGuiRender() override
		{
			ImGui::Begin("Settings");
			ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
			ImGui::End();
		}

		void OnEvent(Calavera::Event& event) override
		{
		}

	private:
		Calavera::ShaderLibrary m_ShaderLibrary;
		Calavera::Ref<Calavera::Shader> m_Shader;
		Calavera::Ref<Calavera::VertexArray> m_VertexArray;

		Calavera::Ref<Calavera::Shader> m_FlatColorShader;
		Calavera::Ref<Calavera::VertexArray> m_SquareVA;

		Calavera::Ref<Calavera::Texture2D> m_Texture, m_CalaveraLogoTexture;

		Calavera::OrthographicCamera m_Camera;
		glm::vec3 m_CameraPosition;
		float m_CameraMoveSpeed = 5.0f;

		float m_CameraRotation = 0.0f;
		float m_CameraRotationSpeed = 180.0f;

		glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };

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