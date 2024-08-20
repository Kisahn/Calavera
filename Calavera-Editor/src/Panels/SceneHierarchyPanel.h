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

			Entity GetSelectedEntity() const { return m_SelectionContext; }
			void SetSelectedEntity(Entity entity);

		private:
			void DrawEntityNode(Entity entity);
			void DrawComponents(Entity entity);

			Ref<Scene> m_Context;
			Entity m_SelectionContext;

	};

}

#endif // !SCENEHIERARCHYPANEL_H
