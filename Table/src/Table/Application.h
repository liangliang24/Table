#pragma once

#include "Core.h"

#include "Window.h"
#include "Table/LayerStack.h"
#include "Events/Event.h"
#include "Table/Events/ApplicationEvent.h"

#include "Table/ImGui/ImGuiLayer.h"


namespace Table 
{
	class TABLE_API Application
	{
	public:
		Application();
		virtual ~Application();

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

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;

		static Application* s_Instance;
	};

	Application* CreateApplication();
}


