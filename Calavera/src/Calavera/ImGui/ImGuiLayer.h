#pragma once

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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}