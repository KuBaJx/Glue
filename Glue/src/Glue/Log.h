#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Glue {
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
// ... in defines means variable count of args
// :: prefix means global scope
#define GLUE_CORE_TRACE(...)	::Glue::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GLUE_CORE_INFO(...)		::Glue::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GLUE_CORE_WARN(...)		::Glue::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GLUE_CORE_ERROR(...)	::Glue::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GLUE_CORE_FATAL(...)	::Glue::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define GLUE_TRACE(...)	::Glue::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GLUE_INFO(...)	::Glue::Log::GetClientLogger()->info(__VA_ARGS__)
#define GLUE_WARN(...)	::Glue::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GLUE_ERROR(...)	::Glue::Log::GetClientLogger()->error(__VA_ARGS__)
#define GLUE_FATAL(...)	::Glue::Log::GetClientLogger()->fatal(__VA_ARGS__)
