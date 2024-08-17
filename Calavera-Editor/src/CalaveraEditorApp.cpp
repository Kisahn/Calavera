#include "Calavera.h"
#include <Calavera/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Calavera {

	class CalaveraEditor : public Application
	{
		public:
			CalaveraEditor()
				: Application("Calavera Editor")
			{
				PushLayer(new EditorLayer());
			}

			~CalaveraEditor()
			{

			}
	};

	Application* CreateApplication()
	{
		return new CalaveraEditor();
	}

}