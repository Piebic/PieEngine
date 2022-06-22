#include "Pie.h"
#include "PieLog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace Core {

	std::shared_ptr<spdlog::logger> PieLog::coreLogger;
	std::shared_ptr<spdlog::logger> PieLog::clientLogger;

	void PieLog::init() {
		std::vector<spdlog::sink_ptr> coreSinks;
		coreSinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		coreSinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/Engine.txt", true));

		std::vector<spdlog::sink_ptr> appSinks;
		appSinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		appSinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/App.txt", true));

		coreLogger = std::make_shared<spdlog::logger>("Engine", begin(coreSinks), end(coreSinks));
		coreLogger->set_level(spdlog::level::trace);
		coreLogger->set_pattern("%^[%H:%M:%S] %s:[%!: %# line] [%n]: <%L> %v%$");

		clientLogger = std::make_shared<spdlog::logger>("App", begin(appSinks), end(appSinks));
		clientLogger->set_level(spdlog::level::trace);
		clientLogger->set_pattern("%^[%H:%M:%S] %s:[%!: %# line] [%n]: <%L> %v%$");
	}

}
