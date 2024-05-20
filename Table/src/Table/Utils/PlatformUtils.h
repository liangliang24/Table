#pragma once

#include <string>
#include <optional>

namespace Table
{
	class Time
	{
	public:
		static float GetTime();
	};

	class FileDialogs
	{
	public:
		static std::string OpenFile(const char* filter);
		static std::string SaveFile(const char* filter);
	};
}