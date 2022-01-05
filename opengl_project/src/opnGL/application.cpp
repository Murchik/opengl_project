#include "application.h"

namespace opnGL {

    application::application() {}

    application::~application() {}

    void application::run() {
        if(!glfwInit()) {
            OPNGL_CORE_CRITICAL("Failed to init GLFW");
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        const int windowWidth = 1280;
        const int windowHeight = 720;
        const std::string windowTitle = "My Window";

        GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), nullptr, nullptr);
        if(!window) {
            OPNGL_CORE_CRITICAL("Failed to create GLFW window");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(window);

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            OPNGL_CORE_CRITICAL("Failed to init GLAD");
            return;
        }

        glViewport(0, 0, windowWidth, windowHeight);

        while(!glfwWindowShouldClose(window)) {
            glClearColor(2.0f / 255.0f, 119.0f / 255.0f, 110.0f / 255.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwTerminate();
    }

}  // namespace opnGL
