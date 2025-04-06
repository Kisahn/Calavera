#include <Calavera.h>

class ExampleLayer : public Calavera::Layer
{
	public:
		ExampleLayer()
			: Layer("Example")
		{
		}

		void OnUpdate() override
		{
			CV_INFO("ExampleLayer::Update");
		}

		void OnEvent(Calavera::Event& event) override
		{
			CV_TRACE("{0}", event);
		}

};

class Sandbox : public Calavera::Application
{
	public :
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