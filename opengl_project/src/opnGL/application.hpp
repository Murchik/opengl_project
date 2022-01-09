#pragma once

#include "core.hpp"
#include "logger.hpp"
#include "window.hpp"

namespace opnGL {

    class OPNGL_API application {
    public:
        application();
        virtual ~application();

        void run();

    private:
        std::unique_ptr<window> m_main_window;
    };

    // to be defined in user app
    application* createApplication();

}
