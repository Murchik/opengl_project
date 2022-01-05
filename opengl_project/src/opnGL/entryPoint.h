#pragma once

extern opnGL::application* opnGL::createApplication();

int main(int argc, char** argv) {
    opnGL::logger::init();

    auto app = opnGL::createApplication();
    app->run();
    delete app;

    return 0;
}
