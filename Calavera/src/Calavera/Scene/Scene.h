#ifndef SCENE_H
#define SCENE_H

#include <entt.hpp>

#include "Calavera/Core/Timestep.h"

namespace Calavera {

	class Scene
	{

		public:
			Scene();
			~Scene();

			entt::entity CreateEntity();

			// TEMP
			entt::registry& Reg() { return m_Registry; }

			void OnUpdate(Timestep ts);

		private:
			entt::registry m_Registry;

	};

}

#endif // !SCENE_H
