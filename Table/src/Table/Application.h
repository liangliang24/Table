#pragma once

#include "Core.h"

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


