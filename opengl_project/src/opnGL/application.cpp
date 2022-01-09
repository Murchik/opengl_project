#include "application.hpp"

namespace opnGL {

    application::application() {}

    application::~application() {}

    void application::run() {
        m_main_window = std::unique_ptr<window>(window::create(window_data("App")));

        OPNGL_CORE_INFO("Successefuly created window App");

        OPNGL_WARN("Client logger test");

        while(true) {
            m_main_window->on_update();
        }
    }

}  // namespace opnGL
