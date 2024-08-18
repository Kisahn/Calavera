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

			void OnUpdate(Timestep ts);

		private:
			entt::registry m_Registry;

			friend class Entity;

	};

}

#endif // !SCENE_H
