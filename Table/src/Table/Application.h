#pragma once

#include "Core.h"

#include "Window.h"
#include "Table/LayerStack.h"
#include "Events/Event.h"
#include "Table/Events/ApplicationEvent.h"

#include "Table/ImGui/ImGuiLayer.h"

#include "Table/Renderer/Shader.h"
#include "Table/Renderer/Buffer.h"
#include "Renderer/VertexArray.h"

#include "Table/Renderer/OrthographicCamera.h"

namespace Table 
{
	class TABLE_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImguiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
		
		static Application* s_Instance;
	};

	Application* CreateApplication();
}


