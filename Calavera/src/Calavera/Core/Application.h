#ifndef APPLICATION_H
#define APPLICATION_H

#include "Calavera/Core/Base.h"

#include "Window.h"
#include "Calavera/Core/LayerStack.h"
#include "Calavera/Events/Event.h"
#include "Calavera/Events/ApplicationEvent.h"

#include "Calavera/Core/Timestep.h"

#include "Calavera/ImGui/ImGuiLayer.h"

namespace Calavera {

	class Application
	{
		public:
			Application(const std::string& name = "Calavera App");
			virtual ~Application();

			void Run();

			void OnEvent(Event& e);

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* layer);

			Window& GetWindow() { return *m_Window; }

			void Close();

			ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

			static Application& Get() { return *s_Instance; }

		private:
			bool OnWindowClose(WindowCloseEvent& e);
			bool OnWindowResize(WindowResizeEvent& e);

			std::unique_ptr<Window> m_Window;
			ImGuiLayer* m_ImGuiLayer;
			bool m_Running = true;
			bool m_Minimized = false;
			LayerStack m_LayerStack;
			float m_LastFrameTime = 0.0f;

			static Application* s_Instance;
	};

	//To be defined in CLIENT
	Application* CreateApplication();

}

#endif // !APPLICATION_H
