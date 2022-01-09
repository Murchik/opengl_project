#include "logger.h"

namespace opnGL {

    std::shared_ptr<spdlog::logger> log::s_core_logger;
    std::shared_ptr<spdlog::logger> log::s_client_logger;

    void log::init() {
        spdlog::sink_ptr sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        sink->set_pattern("%^[%T] %n: %v%$");

        s_core_logger = std::make_shared<spdlog::logger>("CORE", sink);
        spdlog::register_logger(s_core_logger);
        s_core_logger->set_level(spdlog::level::trace);
        s_core_logger->flush_on(spdlog::level::trace);

        s_client_logger = std::make_shared<spdlog::logger>("CLNT", sink);
        spdlog::register_logger(s_client_logger);
        s_client_logger->set_level(spdlog::level::trace);
        s_client_logger->flush_on(spdlog::level::trace);
    }

}
