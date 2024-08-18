#include "cvpch.h"
#include "Entity.h"

namespace Calavera {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}