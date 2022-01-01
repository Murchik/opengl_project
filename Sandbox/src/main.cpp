#include <opnGL.h>

class sandbox : public opnGL::application {
public:
    sandbox() {

    }
    ~sandbox() {

    }
};

opnGL::application* opnGL::createApplication() {
    return new sandbox();
}
