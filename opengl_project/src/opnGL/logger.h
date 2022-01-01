#pragma once

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "core.h"

namespace opnGL {

    class OPNGL_API logger {
    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger>& get_core_logger() {
            return m_core_logger;
        };

        inline static std::shared_ptr<spdlog::logger>& get_client_logger() {
            return m_client_logger;
        };

    private:
        static std::shared_ptr<spdlog::logger> m_core_logger;
        static std::shared_ptr<spdlog::logger> m_client_logger;
    };

}

#define OPNGL_CORE_TRACE(...)       ::opnGL::logger::get_core_logger()->trace(__VA_ARGS__)
#define OPNGL_CORE_INFO(...)        ::opnGL::logger::get_core_logger()->info(__VA_ARGS__)
#define OPNGL_CORE_WARN(...)        ::opnGL::logger::get_core_logger()->warn(__VA_ARGS__)
#define OPNGL_CORE_ERROR(...)       ::opnGL::logger::get_core_logger()->error(__VA_ARGS__)
#define OPNGL_CORE_CRITICAL(...)    ::opnGL::logger::get_core_logger()->critical(__VA_ARGS__)

#define OPNGL_TRACE(...)       ::opnGL::logger::get_client_logger()->trace(__VA_ARGS__)
#define OPNGL_INFO(...)        ::opnGL::logger::get_client_logger()->info(__VA_ARGS__)
#define OPNGL_WARN(...)        ::opnGL::logger::get_client_logger()->warn(__VA_ARGS__)
#define OPNGL_ERROR(...)       ::opnGL::logger::get_client_logger()->error(__VA_ARGS__)
#define OPNGL_CRITICAL(...)    ::opnGL::logger::get_client_logger()->critical(__VA_ARGS__)
