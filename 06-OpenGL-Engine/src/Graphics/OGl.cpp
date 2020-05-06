// System headers
#include <iostream>
// Engine headers
#include <OGl.h>
#include <Settings.h>

OGl::OGl() {

}

OGl::~OGl() {

}

void OGl::init(GLADloadproc procAddress) {
    if(!gladLoadGLLoader(procAddress)) {
        std::cout << "ERROR: OpenGl function pointers was not successfully retrieved" << std::endl;
        return;
    }

    glClearColor(Settings::color.r, Settings::color.g, Settings::color.b, Settings::color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OGl::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}