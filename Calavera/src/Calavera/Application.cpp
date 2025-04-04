#include "Application.h"

#include "Calavera/Events/ApplicationEvent.h"
#include "Calavera/Log.h"

namespace Calavera {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			CV_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			CV_TRACE(e.ToString());
		}
		
		while (true);
	}

}