#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"
#include "Events/Event.h"
#include "Calavera/Events/ApplicationEvent.h"
#include "Calavera/Log.h"

namespace Calavera {

	class CALAVERA_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();

}

#endif // !APPLICATION_H
