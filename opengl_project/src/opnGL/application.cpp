#include "application.h"

namespace opnGL {

    application::application() {}

    application::~application() {}

    void application::run() {
        m_main_window = std::unique_ptr<window>(window::create(window_data("App")));
        
        while(true) {
            m_main_window->on_update();
        }
    }

}  // namespace opnGL
