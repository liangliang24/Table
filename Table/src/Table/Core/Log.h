#pragma once

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

#include "Table/Core/Core.h"

// This ignores all warnings raised inside External headers
//#pragma warning(push,0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
//#pragma warning(pop)


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
			return s_ClientLogger;
		}

	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
	return os << glm::to_string(quaternion);
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
