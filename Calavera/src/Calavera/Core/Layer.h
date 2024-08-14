#ifndef LAYER_H
#define LAYER_H

#include "Calavera/Core/Core.h"
#include "Calavera/Core/Timestep.h"
#include "Calavera/Events/Event.h"

namespace Calavera {

	class CALAVERA_API Layer
	{
		public:
			Layer(const std::string& name = "Layer");
			virtual ~Layer() = default;

			virtual void OnAttach() {}
			virtual void OnDetach() {}
			virtual void OnUpdate(Timestep ts) {}
			virtual void OnImGuiRender() {}
			virtual void OnEvent(Event& event) {}

			inline const std::string& GetName() const { return m_DebugName; }
	
		protected:
			std::string m_DebugName;
	};

}

#endif // !LAYER_H


