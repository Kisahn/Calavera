#ifndef SCENE_H
#define SCENE_H

#include "Calavera/Core/Timestep.h"
#include "Calavera/Renderer/EditorCamera.h"

#include "entt.hpp"

namespace Calavera {

	class Entity;

	class Scene
	{

		public:
			Scene();
			~Scene();

			Entity CreateEntity(const std::string& name = std::string());
			void DestroyEntity(Entity entity);

			void OnUpdateRuntime(Timestep ts);
			void OnUpdateEditor(Timestep ts, EditorCamera& camera);
			void OnViewportResize(uint32_t width, uint32_t height);

			Entity GetPrimaryCameraEntity();

		private:
			template<typename T>
			void OnComponentAdded(Entity entity, T& component);

			entt::registry m_Registry;
			uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;

			friend class Entity;
			friend class SceneSerializer;
			friend class SceneHierarchyPanel;

	};

}

#endif // !SCENE_H
