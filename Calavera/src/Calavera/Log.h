#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Calavera {

	class CALAVERA_API Log
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

// Core log macros
#define CV_CORE_TRACE(...)     ::Calavera::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CV_CORE_INFO(...)      ::Calavera::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CV_CORE_WARN(...)      ::Calavera::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CV_CORE_ERROR(...)     ::Calavera::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CV_CORE_FATAL(...)     ::Calavera::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CV_TRACE(...)          ::Calavera::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CV_INFO(...)           ::Calavera::Log::GetClientLogger()->info(__VA_ARGS__)
#define CV_WARN(...)           ::Calavera::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CV_ERROR(...)          ::Calavera::Log::GetClientLogger()->error(__VA_ARGS__)
#define CV_FATAL(...)          ::Calavera::Log::GetClientLogger()->fatal(__VA_ARGS__)
