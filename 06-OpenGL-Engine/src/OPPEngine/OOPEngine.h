#pragma once
// System headers
#include <string.h>
// Forward declaration
class OGl;
class GLFWwindow;


/* Brief:
 *   TODO!
*/
class OOPEngine {
public:
    /* Brief:
     *   TODO!
    */
    OOPEngine();
    virtual ~OOPEngine();

    /* Brief:
     *   Define your scene here
    */
    virtual void loadScene() = 0;

    /* Brief:
     *   TODO!
    */
    virtual void run();

    /* Brief:
     *   Setup engine asstets etc.
    */
    virtual void init();
protected:
    /* Brief:
     *   Load from shaders source from dedicated location, create graphic pipline and associate it with the given ID.
     * param vertexShaderName - Name of vertex shader file (name.vert)
     * param fragmentShaderName - Name of fragment shader file (name.frag)
     * param shaderId - ID which should be associated with newly created graphic pipline
     * return - true if graphic pipline was created successfully 
    */
    bool createShader(const std::string vertexShaderName, const std::string fragmentShaderName, uint16_t shaderId);


private:
    // Window handler
    GLFWwindow* m_window;

    // Graphic context handler
    OGl* const m_renderer;
};