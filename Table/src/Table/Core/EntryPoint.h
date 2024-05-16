#pragma once
#include "Table/Core/Core.h"

#ifdef TABLE_PLATFORM_WINDOWS

extern Table::Application* Table::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Table::Log::Init();
	TABLE_CORE_WARN("Initialized Table log!");
	TABLE_INFO("Initialized Client log!");

	//printf("Hello Table Engine!")
	TABLE_PROFILE_BEGIN_SESSION("Startup", "TableProfile_Startup.json");
	auto app = Table::CreateApplication({argc, argv});
	TABLE_PROFILE_END_SESSION();

	TABLE_PROFILE_BEGIN_SESSION("Runtime", "TableProfile-Runtime.json");
	app->Run();
	TABLE_PROFILE_END_SESSION();

	TABLE_PROFILE_BEGIN_SESSION("Shutdown", "TableProfile-Shutdown.json");
	delete app;
	TABLE_PROFILE_END_SESSION();
}

#endif // TABLE_PLATFORM_WINDOWS
