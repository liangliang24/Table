#pragma once

#ifdef TABLE_PLATFORM_WINDOWS

extern Table::Application* Table::CreateApplication();

int main()
{
	//printf("Hello Table Engine!")
	auto app = Table::CreateApplication();
	app->Run();
	delete app;
}

#endif // TABLE_PLATFORM_WINDOWS
