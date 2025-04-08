#include <Calavera.h>

#include "imgui/imgui.h"

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
			CV_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Calavera::Event& event) override
	{
		if (event.GetEventType() == Calavera::EventType::KeyPressed)
		{
			Calavera::KeyPressedEvent& e = (Calavera::KeyPressedEvent&)event;
			if (e.GetKeyCode() == CV_KEY_TAB)
				CV_TRACE("Tab key is pressed (event)!");
			CV_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

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