#pragma once

#include "Core.h"
#include "Events/Event.h"
namespace Table 
{
	class TABLE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

