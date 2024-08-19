#ifndef SCENE_H
#define SCENE_H

#include <entt.hpp>

#include "Calavera/Core/Timestep.h"

namespace Calavera {

	class Entity;

	class Scene
	{

		public:
			Scene();
			~Scene();

			Entity CreateEntity(const std::string& name = std::string());
			void DestroyEntity(Entity entity);

			void OnUpdate(Timestep ts);
			void OnViewportResize(uint32_t width, uint32_t height);

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
