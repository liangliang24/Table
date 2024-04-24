#pragma once

#include "Table/Core/Core.h"

#include "Table/Core/Window.h"
#include "Table/Core/LayerStack.h"
#include "Table/Events/Event.h"
#include "Table/Events/ApplicationEvent.h"

#include "Table/ImGui/ImGuiLayer.h"

#include "Table/Renderer/Shader.h"
#include "Table/Renderer/Buffer.h"
#include "Table/Renderer/VertexArray.h"

#include "Table/Renderer/OrthographicCamera.h"

int main(int argc, char** argv);

namespace Table 
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImguiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
		
		static Application* s_Instance;

		friend int ::main(int argc, char** argv);
	};

	Application* CreateApplication();
}


