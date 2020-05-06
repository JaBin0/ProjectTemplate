// System headers
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// Engine headers
#include <OGl.h>
#include <OOPEngine.h>
#include <Settings.h>
#include <AssetLoader.h>

OOPEngine::OOPEngine() 
    : m_renderer{new OGl()}
{
    if(!glfwInit()) {
        std::cout << "ERROR: GLFW was not properly initialized" << std::endl;
        return;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    m_window = glfwCreateWindow(Settings::WIDHT, Settings::HEIGHT, Settings::TITLE.data(), NULL, NULL);
    if(!m_window) {
        std::cout << "ERROR: GLFW window handler was not properly created" << std::endl;
        return;
    }
    glfwMakeContextCurrent(m_window);

    // Initialize renderer
    m_renderer->init((GLADloadproc)glfwGetProcAddress);

    // glfwSetKeyCallback(m_window, key_callBack);
    // glfwSetScrollCallback(m_window, scroll_callBack);
    // glfwSetCursorPosCallback(m_window, cursor_callBack);
    // glfwSetMouseButtonCallback(m_window, mouse_callBack);
    // glfwSetJoystickCallback(joysctick_callBack);
}

OOPEngine::~OOPEngine() {
    std::cout << "OOPEngine::Destructor" << std::endl;
}

void OOPEngine::init() {

}

void OOPEngine::run() {
    std::cout << "Start game based on the OOPEngine " << std::endl;
    // Load scene 
    init();
    loadScene();

    // Start main loop
    while (!glfwWindowShouldClose(m_window)) {
        glfwPollEvents();
        m_renderer->draw();
        glfwSwapBuffers(m_window);
    }
}

bool OOPEngine::createShader(const std::string vertexShaderName, const std::string fragmentShaderName, uint16_t shaderId) {
    std::string vertexShaderSoruce = AssetLoader::loadFile(AssetLoader::SHADER_PATH + vertexShaderName + ".vert");
    std::string fragmentShaderSoruce = AssetLoader::loadFile(AssetLoader::SHADER_PATH + vertexShaderName + ".frag");
    std::cout << vertexShaderSoruce.data();
    std::cout << "/========================" << std::endl;
    std::cout << fragmentShaderSoruce.data();
    return false;

    //bool success = ::loadShaderSources(vertexShaderName, fragmentShaderName, )

}