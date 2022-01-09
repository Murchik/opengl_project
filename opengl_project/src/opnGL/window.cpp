#include "window.hpp"
#include "../platform/winGLFW/glfw_window.hpp"

namespace opnGL {

    window* window::create(const window_data& data) {
        return new glfw_window();
    }

}
