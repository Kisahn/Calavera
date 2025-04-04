#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Calavera {

	class CALAVERA_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	// To be defined in the client
	Application* CreateApplication();

}

