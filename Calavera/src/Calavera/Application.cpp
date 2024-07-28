#include "Application.h"
#include <iostream>

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
			CV_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			CV_TRACE(e);
		}

		while (true);
	}

}