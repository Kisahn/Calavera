#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H

#include "Calavera/Core/Window.h"
#include "Calavera/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace Calavera {

	class WindowsWindow : public Window
	{

		public:
			WindowsWindow(const WindowProps& props);
			virtual ~WindowsWindow();

			void OnUpdate() override;

			unsigned int GetWidth() const override { return m_Data.Width; }
			unsigned int GetHeight() const override { return m_Data.Height; }

			// Window attributes
			void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
			void SetVSync(bool enabled) override;
			bool IsVSync() const override;

			virtual void* GetNativeWindow() const { return m_Window; }

		private:
			virtual void Init(const WindowProps& props);
			virtual void Shutdown();

			GLFWwindow* m_Window;
			Scope<GraphicsContext> m_Context;

			struct WindowData
			{
				std::string Title;
				unsigned int Width, Height;
				bool VSync;

				EventCallbackFn EventCallback;
			};

			WindowData m_Data;

	};

}

#endif // !WINDOWSWINDOW_H