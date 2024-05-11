#pragma once

#include "Table.h"
#include "Panels/SceneHierarchyPanel.h"

namespace Table
{
	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;
	private:
		OrthographicCameraController m_CameraController;

		Ref<VertexArray> m_SquareVA;
		Ref<Shader> m_FlatColorShader;
		Ref<Framebuffer> m_Framebuffer;

		Ref<Scene> m_ActiveScene;
		Entity m_SquareEntity;
		Entity m_CameraEntity;
		Entity m_SecondaryCamera;

		bool m_PrimaryCamera = true;

		Ref<Texture2D> m_CheckerboardTexture;
		Ref<Texture2D> m_FF0Texture;

		bool m_ViewportFocused = false, m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = { 0.0f,0.0f };

		glm::vec4 m_SquareColor = { 0.2f,0.3f,0.8f,1.0f };

		SceneHierarchyPanel m_SceneHierachyPanel;
	};

	class CameraController : public ScriptableEntity
	{
	public:
		virtual void OnCreate() override 
		{
			auto& transform = GetComponent<TransformComponent>().Translation;
			transform.x = rand() % 10 - 5.0f;
		}
		virtual void OnDestroy() override {}
		virtual void OnUpdate(Timestep ts) override
		{
			auto& translation = GetComponent<TransformComponent>().Translation;

			float speed = 5.0f;

			if (Input::IsKeyPressed(Key::A)) translation.x -= speed * ts;
			if (Input::IsKeyPressed(Key::D)) translation.x += speed * ts;
			if (Input::IsKeyPressed(Key::W)) translation.y += speed * ts;
			if (Input::IsKeyPressed(Key::S)) translation.y -= speed * ts;
		}
	};
}

