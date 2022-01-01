#include "logger.h"

namespace opnGL {

    std::shared_ptr<spdlog::logger> logger::m_core_logger;

    std::shared_ptr<spdlog::logger> logger::m_client_logger;

    void logger::init() {
        auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

        m_core_logger = std::make_shared<spdlog::logger>("CORE", sink);
        m_core_logger->set_pattern("%^[%T] %n: %v%$");

        m_client_logger = std::make_shared<spdlog::logger>("CLNT", sink);
        m_client_logger->set_pattern("%^[%T] %n: %v%$");
    }

}
