#pragma once

#include <memory>

#ifdef TABLE_PLATFORM_WINDOWS
#if TABLE_DYNAMIC_LINK
	#ifdef TABLE_BUILD_DLL
		#define TABLE_API __declspec(dllexport)
	#else	
		#define TABLE_API __declspec(dllimport)
	#endif // TABLE_BUILD_DLL
#else
	#define TABLE_API
#endif
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

#ifdef TABLE_DEBUG
	#define TABLE_ENABLE_DEBUG
#endif // TABLE_DEBUG


#define BIT(x) (1 << x)

#define  TABLE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)


namespace Table
{
	template <typename T>
	using Scope = std::unique_ptr<T>;

	template <typename T>
	using Ref = std::shared_ptr<T>;
}