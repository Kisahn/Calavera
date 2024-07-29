#ifndef IMGUILAYER_H
#define IMGUIMAYER_H

#include "Calavera/Layer.h"

#include "Calavera/Events/ApplicationEvent.h"
#include "Calavera/Events/KeyEvent.h"
#include "Calavera/Events/MouseEvent.h"

namespace Calavera {

	class CALAVERA_API ImGuiLayer : public Layer
	{
		public:
			ImGuiLayer();
			~ImGuiLayer();

			void OnAttach();
			void OnDetach();
			void OnUpdate();
			void OnEvent(Event& event);

		private:
			bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
			bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
			bool OnMouseButtonMovedEvent(MouseMovedEvent& e);
			bool OnMouseButtonScrolledEvent(MouseScrolledEvent& e);
			bool OnKeyPressedEvent(KeyPressedEvent& e);
			bool OnKeyReleasedEvent(KeyReleasedEvent& e);
			bool OnKeyTypedEvent(KeyTypedEvent& e);
			bool OnWindowResizeEvent(WindowResizeEvent& e);

			float m_Time = 0.0f;
	};

}

#endif // !IMGUILAYER_H
