#pragma once
#include "entt.hpp"

#include "Table/Core/TimeStep.h"
namespace Table
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		entt::entity CreateEntity();

		entt::registry& Reg() { return m_Registry; }

		void OnUpdate(TimeStep ts);
	private:
		entt::registry m_Registry;
	};
}

