#pragma once

#include "Scene.h"
#include "Entity.h"

namespace Table
{
	class SceneSerializer
	{
	public:
		SceneSerializer(const Ref<Scene>& scene);
		void Serialize(const std::filesystem::path& filepath);
		void SerializeRuntime(const std::filesystem::path& filepath);

		static void SerializeEntityToPath(Entity entity, const std::string& filepath);

		bool DeSerialize(const std::filesystem::path& filepath);
		bool DeSerializeRuntime(const std::filesystem::path& filepath);

		bool DeSerializeEntityToScene(const std::filesystem::path& filepath);
	private:
		Ref<Scene> m_Scene;
	};
}

