#pragma once


#include "Table/Core/Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Table
{
	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}
		static Ref<spdlog::logger>& GetCientLogger()
		{
			return s_CientLogger;
		}

	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_CientLogger;
	};
}

//Core log macros
#define TABLE_CORE_TRACE(...) ::Table::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TABLE_CORE_INFO(...) ::Table::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TABLE_CORE_WARN(...) ::Table::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TABLE_CORE_ERROR(...) ::Table::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TABLE_CORE_CRITICAL(...) ::Table::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Core log macros
#define TABLE_TRACE(...) ::Table::Log::GetCientLogger()->trace(__VA_ARGS__)
#define TABLE_INFO(...) ::Table::Log::GetCientLogger()->info(__VA_ARGS__)
#define TABLE_WARN(...) ::Table::Log::GetCientLogger()->warn(__VA_ARGS__)
#define TABLE_ERROR(...) ::Table::Log::GetCientLogger()->error(__VA_ARGS__)
#define TABLE_CRITICAL(...) ::Table::Log::GetCientLogger()->critical(__VA_ARGS__)
