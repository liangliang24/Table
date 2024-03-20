#pragma once


#ifdef TABLE_PLATFORM_WINDOWS
	#ifdef TABLE_BUILD_DLL
		#define TABLE_API __declspec(dllexport)
	#else	
		#define TABLE_API __declspec(dllimport)
	#endif // TABLE_BUILD_DLL
#else
#error Table only support Windows!
#endif // TABLE_PLATFORM_WINDOWS

#ifdef TABLE_ENABLE_ASSERTS
#define TABLE_ASSERT(x, ...) { if(!(x)) { TABLE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define TABLE_CORE_ASSERT(x, ...) { if(!(x)) { TABLE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define TABLE_ASSERT(x, ...)
#define TABLE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)