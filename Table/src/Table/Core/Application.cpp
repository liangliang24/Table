#include "tpch.h"
#include "Table/Core/Application.h"
#include "Table/Core/Log.h"
#include <glad/glad.h>
#include "Table/Core/Input.h"
#include <GLFW/glfw3.h>
#include "Table/Renderer/Renderer.h"
#include "Table/Utils/PlatformUtils.h"
#include "Table/Scripting/ScriptEngine.h"

namespace Table
{

	Application* Application::s_Instance = nullptr;

	Application::Application(const ApplicationSpecification& specification)
		: m_Specification(specification)
	{
		TABLE_PROFILE_FUNCTION();

		TABLE_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		if (!m_Specification.WorkingDirectory.empty())
			std::filesystem::current_path(m_Specification.WorkingDirectory);

		m_Window = Window::Create(WindowProps(m_Specification.Name));
		m_Window->SetEventCallback(TABLE_BIND_EVENT_FN(Application::OnEvent));

		Renderer::Init();
		ScriptEngine::Init();

		m_ImguiLayer = new ImGuiLayer();
		PushOverLay(m_ImguiLayer);

		
	}


	Application::~Application()
	{
		TABLE_PROFILE_FUNCTION();
		Renderer::Shutdown();
		ScriptEngine::Shutdown();
	}

	void Application::Run()
	{	
		TABLE_PROFILE_FUNCTION();
		WindowResizeEvent e(1280, 720);

		while (m_Running)
		{
			TABLE_PROFILE_SCOPE("RunLoop");
			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			ExecuteMainThreadQueue();

			if (!m_Minimized)
			{
				{
					TABLE_PROFILE_SCOPE("LayerStack OnUpdate");

					for (Layer* layer : m_LayerStack)
					{
						layer->OnUpdate(timestep);
					}
				}
				m_ImguiLayer->Begin();
				{
					TABLE_PROFILE_SCOPE("LayerStack OnImGuiRender");
					for (Layer* layer : m_LayerStack)
					{
						layer->OnImGuiRender();
					}
				}
				m_ImguiLayer->End();
			}
			
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		TABLE_PROFILE_FUNCTION();
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(TABLE_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(TABLE_BIND_EVENT_FN(Application::OnWindowResize));
		
		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend();  ++it)
		{
			if (e.Handled)
			{
				break;
			}
			(*it)->OnEvent(e);
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		TABLE_PROFILE_FUNCTION();
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverLay(Layer* layer)
	{
		TABLE_PROFILE_FUNCTION();
		m_LayerStack.PushOverLay(layer);
		layer->OnAttach();
	}

	void Application::Close()
	{
		m_Running = false;
	}

	void Application::SubmitToMainThread(const std::function<void()>& function)
	{
		std::scoped_lock<std::mutex> lock(m_MainThreadQueueMutex);

		m_MainThreadQueue.emplace_back(function);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		TABLE_PROFILE_FUNCTION();
		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}

	void Application::ExecuteMainThreadQueue()
	{
		std::scoped_lock<std::mutex> lock(m_MainThreadQueueMutex);

		for (auto& func : m_MainThreadQueue)
			func();

		m_MainThreadQueue.clear();
	}

}

