#pragma once
// System headers
#include <glad/glad.h>
#include <unordered_map>
#include <glm-0.9.8.0/gtc/type_ptr.hpp>
#include <glm-0.9.8.0/gtc/matrix_transform.hpp>
// Engine headers
#include <GraphicsTypes.h>

/* Brief:
 *   TODO!
*/
class OGl {
public:
    /* Brief:
     *   Constructors & Destructor
    */
    OGl();
    ~OGl();

    /* Brief:
     *   TODO!
    */
    void init(GLADloadproc procAddress);

    /* Brief:
     *   TODO!
    */
    void draw();

    /* Brief:
     *   Create graphic pipline from the given shaders sources
     * param programID - graphic pipline ID which can be used in the Engine.
     * param vertexShaderSrc - source for vertex shader 
     * param fragmentShaderSrc - source for fragment shader
     * return - Return true if new graphic pipline was created and associated with the given ID properly
    */
    bool createShader(const uint16_t programID, const char* vertexShaderSrc, const char* fragmentShaderSrc);

    // Create vertex array object 
    void createVAO(const uint16_t meshID, MeshDiscription description);

    void setProgram(uint16_t programID);

    void setUniform();

public:
    // Tmp section
    // Perspective matrix
    glm::mat4 m_perspective;
    glm::mat4 m_ortho;

    // Look at matrix of camera
    glm::mat4 m_lookAt;

    uint16_t m_program;

private:
    /* Brief:
     *   Container to hold all shaders loaded to the system
     * param key - graphic pipline ID which can be used in the Engine.
     * param value - graphic pipline ID given from the loading process to the graphic card.
    */
    std::unordered_map<uint16_t, uint16_t> m_programMapper;

    // Container to hold all shaders loaded to the system
    // * param key - mesh ID which can be used in the Engine
    // * param value - pair to store mesh id in the opengl context and number of vertices to load;
    std::unordered_map<uint16_t, VAO> m_meshMapper;
};