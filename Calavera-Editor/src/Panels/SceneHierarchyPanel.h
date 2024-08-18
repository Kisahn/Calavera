#ifndef SCENEHIERARCHYPANEL_H
#define SCENEHIERARCHYPANEL_H

#include "Calavera/Core/Base.h"
#include "Calavera/Core/Log.h"
#include "Calavera/Scene/Scene.h"
#include "Calavera/Scene/Entity.h"

namespace Calavera {

	class SceneHierarchyPanel
	{
		public:
			SceneHierarchyPanel() = default;
			SceneHierarchyPanel(const Ref<Scene>& scene);

			void SetContext(const Ref<Scene>& scene);

			void OnImGuiRender();

		private:
			void DrawEntityNode(Entity entity);

			Ref<Scene> m_Context;
			Entity m_SelectionContext;

	};

}

#endif // !SCENEHIERARCHYPANEL_H
