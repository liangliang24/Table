#pragma once

#include "Table.h"

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
	};

	class CameraController : public ScriptableEntity
	{
	public:
		void OnCreate() {}
		void OnDestroy() {}
		void OnUpdate(Timestep ts)
		{
			auto& transform = GetComponent<TransformComponent>().Transform;

			float speed = 5.0f;

			if (Input::IsKeyPressed(Key::A)) transform[3][0] -= speed * ts;
			if (Input::IsKeyPressed(Key::D)) transform[3][0] += speed * ts;
			if (Input::IsKeyPressed(Key::W)) transform[3][1] += speed * ts;
			if (Input::IsKeyPressed(Key::S)) transform[3][1] -= speed * ts;
		}
	};
}

