#include "tpch.h"
#include "Table/Core/Window.h"

#ifdef TABLE_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif // TABLE_PLATFORM_WINDOWS


namespace Table
{

	Scope<Window> Window::Create(const WindowProps& props /*= WindowProps()*/)
	{
#ifdef TABLE_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		TABLE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif // TABLE_PLATFORM_WINDOWS

	}

}