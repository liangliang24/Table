#pragma once

#include "Table/Core/Core.h"
#include "Table/Core/Log.h"
#include "Table/Scene/Scene.h"
#include "Table/Scene/Entity.h"

namespace Table
{
	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& context);

		void SetContext(const Ref<Scene>& context);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);

		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};
}

