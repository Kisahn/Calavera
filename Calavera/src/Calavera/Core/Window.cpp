#include "cvpch.h"
#include "Calavera/Core/Window.h"

#ifdef CV_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Calavera
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
		#ifdef CV_PLATFORM_WINDOWS
			return CreateScope<WindowsWindow>(props);
		#else
			CV_CORE_ASSERT(false, "Unknown platform!");
			return nullptr;
		#endif
	}

}