#include "glfw_window.h"

opnGL::glfw_window::glfw_window() {
    if(!glfwInit()) {
        OPNGL_CORE_CRITICAL("Failed to init GLFW");
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window_handle = glfwCreateWindow(
        data.width,
        data.height,
        data.title.c_str(),
        nullptr,
        nullptr
    );
    if(!m_window_handle) {
        OPNGL_CORE_CRITICAL("Failed to create GLFW window");
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(m_window_handle);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        OPNGL_CORE_CRITICAL("Failed to init GLAD");
        return;
    }

    glViewport(0, 0, data.width, data.height);
}

opnGL::glfw_window::~glfw_window() {
    glfwDestroyWindow(m_window_handle);
}

void opnGL::glfw_window::on_update() {
    glfwSwapBuffers(m_window_handle);
    glfwPollEvents();
}
