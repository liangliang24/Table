#pragma once
#include "entt.hpp"

#include "Table/Core/TimeStep.h"
namespace Table
{
	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());

		void OnUpdate(TimeStep ts);
	private:
		entt::registry m_Registry;

		friend class Entity;
	};
}

