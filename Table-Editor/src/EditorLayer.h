#pragma once

#include "Table.h"
#include "Panels/SceneHierarchyPanel.h"
#include "Panels/ContentBrowserPanel.h"

#include "Table/Renderer/EditorCamera.h"

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
		bool OnKeyPressed(KeyPressedEvent& e);
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);

		void OnOverlayRender();

		void NewProject();
		bool OpenProject();
		void OpenProject(const std::filesystem::path& path);
		void SaveProject();

		void NewScene();
		void OpenScene();
		void OpenScene(AssetHandle handle);
		void SaveScene();
		void SaveSceneAs();

		void SerializeScene(Ref<Scene> scene, const std::filesystem::path& path);

		void OnScenePlay();
		void OnSceneSimulate();
		void OnSceneStop();
		void OnScenePause();

		void OnDuplicateEntity();

		void UI_Toolbar();

		OrthographicCameraController m_CameraController;

		Ref<VertexArray> m_SquareVA;
		Ref<Shader> m_FlatColorShader;
		Ref<Framebuffer> m_Framebuffer;

		Ref<Scene> m_ActiveScene;
		Ref<Scene> m_EditorScene;
		std::filesystem::path m_EditorScenePath;
		Entity m_SquareEntity;
		Entity m_CameraEntity;
		Entity m_SecondaryCamera;

		Entity m_HoveredEntity;

		bool m_PrimaryCamera = true;

		EditorCamera m_EditorCamera;

		Ref<Texture2D> m_CheckerboardTexture;

		bool m_ViewportFocused = false, m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = { 0.0f,0.0f };
		glm::vec2 m_ViewportBounds[2];

		int m_GizmoType = -1;

		bool m_ShowPhysicsColliders = false;

		enum class SceneState
		{
			Edit = 0, Play = 1, Simulate = 2
		};
		SceneState m_SceneState = SceneState::Edit;

		glm::vec4 m_SquareColor = { 0.2f,0.3f,0.8f,1.0f };

		SceneHierarchyPanel m_SceneHierarchyPanel;
		Scope<ContentBrowserPanel> m_ContentBrowserPanel;

		Ref<Texture2D> m_IconPlay, m_IconPause, m_IconStep,  m_IconSimulate, m_IconStop;
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

