// System headers
#include <iostream>
// Engine headers
#include <OOPEngine.h>

OOPEngine::OOPEngine() {

}

OOPEngine::~OOPEngine() {
    std::cout << "OOPEngine::Destructor" << std::endl;
}

void OOPEngine::run() {
    std::cout << "Start game based on the OOPEngine " << std::endl;
    // Load scene 
    loadScene();

    // Start main loop
    
}