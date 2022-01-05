#pragma once

#include "core.h"
#include "logger.h"

namespace opnGL {

    class OPNGL_API application {
    public:
        application();
        virtual ~application();

        void run();
    };

    // to be defined in user app
    application* createApplication();

}
