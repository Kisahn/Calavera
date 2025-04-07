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
			if (Calavera::Input::IsKeyPressed(CV_KEY_TAB))
				CV_TRACE("Tab key is pressed (poll) !");
		}

		void OnEvent(Calavera::Event& event) override
		{
			if (event.GetEventType() == Calavera::EventType::KeyPressed)
			{
				Calavera::KeyPressedEvent& e = (Calavera::KeyPressedEvent&)event;
				if (e.GetKeyCode() == CV_KEY_TAB)
					CV_TRACE("Tab key is pressed (event) !");
				CV_TRACE("{0}", (char)e.GetKeyCode());
			}
		}

};

class Sandbox : public Calavera::Application
{
	public :
		Sandbox()
		{
			PushLayer(new ExampleLayer());
			PushOverlay(new Calavera::ImGuiLayer());
		}

		~Sandbox()
		{

		}
};

Calavera::Application* Calavera::CreateApplication()
{
	return new Sandbox();
}