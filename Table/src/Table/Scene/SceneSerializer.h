#pragma once

#include "Scene.h"
#include "Entity.h"

namespace Table
{
	class SceneSerializer
	{
	public:
		SceneSerializer(const Ref<Scene>& scene);
		void Serialize(const std::string& filepath);
		void SerializeRuntime(const std::string& filepath);

		static void SerializeEntityToPath(Entity entity, const std::string& filepath);

		bool DeSerialize(const std::string& filepath);
		bool DeSerializeRuntime(const std::string& filepath);

		bool DeSerializeEntityToScene(const std::string& filepath);
	private:
		Ref<Scene> m_Scene;
	};
}

