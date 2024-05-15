#pragma once

#include "Table/Core/Core.h"
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

		Entity GetSelectedEntity() const { return m_SelectionContext; }
		void SetSelectedEntity(Entity entity);
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);

		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};
}

