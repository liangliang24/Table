#include "tpch.h"
#include "Table/Core/Input.h"

#ifdef TABLE_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif
namespace Table
{
	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
#ifdef TABLE_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else 
		TABLE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif // TABLE_PLATFORM_WINDOWS
	}

}