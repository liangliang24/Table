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
