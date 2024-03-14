#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"
namespace Table
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_CientLogger;

	void Log::Init()
	{
		//https://github.com/gabime/spdlog/wiki/3.-Custom-formatting
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("Table");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_CientLogger = spdlog::stdout_color_mt("APP");
		s_CientLogger->set_level(spdlog::level::trace);

	}
}


