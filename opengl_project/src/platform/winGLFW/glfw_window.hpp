#pragma once

#include <memory>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "../../opnGL/window.hpp"
#include "../../opnGL/logger.hpp"

namespace opnGL {

    class glfw_window : public window {
    public:
        glfw_window();

        ~glfw_window() override;

        void on_update() override;

    private:
        GLFWwindow* m_window_handle{nullptr};
        window_data data;
    };

};
