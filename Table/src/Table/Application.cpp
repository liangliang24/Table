#include "tpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Table/Log.h"


namespace Table
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}


	void Application::Run()
	{
		
		WindowResizeEvent e(1280, 720);
		//TABLE_TRACE(e);
		if (e.IsInCategory(EventCategoryApplication))
		{
			TABLE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			TABLE_TRACE(e);
		}
		while (true)
		{
			
		}
	}
}

