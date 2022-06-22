#pragma once

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include "../Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Core {

	class PIE_API PieLog {
		public:
		static void init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }
		
		private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};

}

#define logPieTrace(...) SPDLOG_LOGGER_TRACE(::Core::PieLog::GetCoreLogger(), __VA_ARGS__)
#define logPieInfo(...)  SPDLOG_LOGGER_INFO(::Core::PieLog::GetCoreLogger(), __VA_ARGS__)
#define logPieWarn(...)  SPDLOG_LOGGER_WARN(::Core::PieLog::GetCoreLogger(), __VA_ARGS__)
#define logPieError(...) SPDLOG_LOGGER_ERROR(::Core::PieLog::GetCoreLogger(), __VA_ARGS__)

#define logTrace(...) SPDLOG_LOGGER_TRACE(::Core::PieLog::GetClientLogger(), __VA_ARGS__)
#define logInfo(...)  SPDLOG_LOGGER_INFO(::Core::PieLog::GetClientLogger(), __VA_ARGS__)
#define logWarn(...)  SPDLOG_LOGGER_WARN(::Core::PieLog::GetClientLogger(), __VA_ARGS__)
#define logError(...) SPDLOG_LOGGER_ERROR(::Core::PieLog::GetClientLogger(), __VA_ARGS__)
