#pragma once

#include <memory>

#include "Table/Core/PlatformDetection.h"

//#ifdef TABLE_PLATFORM_WINDOWS
//#if TABLE_DYNAMIC_LINK
//	#ifdef TABLE_BUILD_DLL
//		#define TABLE_API __declspec(dllexport)
//	#else	
//		#define TABLE_API __declspec(dllimport)
//	#endif // TABLE_BUILD_DLL
//#else
//	#define TABLE_API
//#endif
//#else
//	#error Table only support Windows!
//#endif // TABLE_PLATFORM_WINDOWS



#ifdef TABLE_DEBUG
#ifdef TABLE_PLATFORM_WINDOWS
#define TABLE_DEBUGBREAK() __debugbreak()
#else
#define TABLE_DEBUGBREAK()
#endif // TABLE_PLATFORM_WINDOWS

	#define TABLE_ENABLE_ASSERTS
#endif // TABLE_DEBUG


#define TABLE_EXPAND_MACRO(x) x
#define TABLE_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define  TABLE_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }


namespace Table
{
	template <typename T>
	using Scope = std::unique_ptr<T>;
	template <typename T,typename  ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template <typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}


#include "Table/Core/Log.h"
#include "Table/Core/Assert.h"