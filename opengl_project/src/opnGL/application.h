#pragma once

#include "core.h"
#include "logger.h"
#include "window.h"

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
