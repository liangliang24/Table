#pragma once

#ifdef TABLE_PLATFORM_WINDOWS

extern Table::Application* Table::CreateApplication();

int main()
{
	Table::Log::Init();
	TABLE_CORE_WARN("Initialized Table log!");
	TABLE_INFO("Initialized Client log!");

	//printf("Hello Table Engine!")
	auto app = Table::CreateApplication();
	app->Run();
	delete app;
}

#endif // TABLE_PLATFORM_WINDOWS
