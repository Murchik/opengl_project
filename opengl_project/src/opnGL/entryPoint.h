#pragma once

extern opnGL::application* opnGL::createApplication();

int main(int argc, char** argv) {
    opnGL::logger::init();

    OPNGL_CORE_WARN("core init log!");

    int a = 5;
    OPNGL_INFO("client init log! variable={0}", a);

    auto app = opnGL::createApplication();
    app->run();
    delete app;

    return 0;
}
