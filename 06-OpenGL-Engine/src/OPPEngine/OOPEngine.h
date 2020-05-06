#pragma once

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

private:
    // Window handler
    GLFWwindow* m_window;

    // Graphic context handler
    OGl* const m_renderer;
};