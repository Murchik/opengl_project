#include "window.h"
#include "../platform/winGLFW/glfw_window.h"

namespace opnGL {

    window* window::create(const window_data& data) {
        return new glfw_window();
    }

}
