#include "tpch.h"
#include "Entity.h"

namespace Table
{
	
	Entity::Entity(entt::entity handle, Scene* scene)
		:m_EntityHandle(handle), m_Scene(scene)
	{

	}

}