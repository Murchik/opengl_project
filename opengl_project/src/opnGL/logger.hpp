#pragma once

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#pragma warning(pop)

#include "core.h"

namespace opnGL {

    class OPNGL_API log {
    public:
        static void init();

        static std::shared_ptr<spdlog::logger>& get_core_logger() {
            return s_core_logger;
        };

        static std::shared_ptr<spdlog::logger>& get_client_logger() {
            return s_client_logger;
        };

    private:
        static std::shared_ptr<spdlog::logger> s_core_logger;
        static std::shared_ptr<spdlog::logger> s_client_logger;
    };

}

#define OPNGL_CORE_TRACE(...)       ::opnGL::log::get_core_logger()->trace(__VA_ARGS__)
#define OPNGL_CORE_INFO(...)        ::opnGL::log::get_core_logger()->info(__VA_ARGS__)
#define OPNGL_CORE_WARN(...)        ::opnGL::log::get_core_logger()->warn(__VA_ARGS__)
#define OPNGL_CORE_ERROR(...)       ::opnGL::log::get_core_logger()->error(__VA_ARGS__)
#define OPNGL_CORE_CRITICAL(...)    ::opnGL::log::get_core_logger()->critical(__VA_ARGS__)

#define OPNGL_TRACE(...)       ::opnGL::log::get_client_logger()->trace(__VA_ARGS__)
#define OPNGL_INFO(...)        ::opnGL::log::get_client_logger()->info(__VA_ARGS__)
#define OPNGL_WARN(...)        ::opnGL::log::get_client_logger()->warn(__VA_ARGS__)
#define OPNGL_ERROR(...)       ::opnGL::log::get_client_logger()->error(__VA_ARGS__)
#define OPNGL_CRITICAL(...)    ::opnGL::log::get_client_logger()->critical(__VA_ARGS__)
