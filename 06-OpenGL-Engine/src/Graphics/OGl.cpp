// System headers
#include <iostream>
#include <vector>
// Engine headers
#include <OGl.h>
#include <AssetsID.h>
#include <Settings.h>

OGl::OGl() 
    : m_programMapper{}
    , m_meshMapper{}
    , m_perspective(1)
    , m_ortho(1)
    , m_lookAt(1)
{
}

OGl::~OGl() {

}

void OGl::init(GLADloadproc procAddress) {
    if(!gladLoadGLLoader(procAddress)) {
        std::cout << "ERROR: OpenGl function pointers was not successfully retrieved" << std::endl;
        return;
    }

    glEnable(GL_DEPTH_TEST);

    glClearColor(Settings::color.r, Settings::color.g, Settings::color.b, Settings::color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_perspective = glm::perspective(glm::radians(45.0f), 
                static_cast<float>(Settings::WIDHT)/static_cast<float>(Settings::HEIGHT),
                0.1f, 100.0f);
    m_ortho = glm::ortho(0.0f, 1200.0f, 0.0f, 720.0f, 0.1f, 100.0f);
    m_lookAt = glm::lookAt(glm::vec3(2.0f, 1.0f, 4.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0));
}

void OGl::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glm::mat4 transform(1.0);
    uint16_t program = m_programMapper[SHADER_ID::DEFAULT];
    glUseProgram(program);
    glUniformMatrix4fv(glGetUniformLocation(program, "projection"), 1, GL_FALSE, glm::value_ptr(m_perspective));
    glUniformMatrix4fv(glGetUniformLocation(program, "view"), 1, GL_FALSE, glm::value_ptr(m_lookAt));
    glUniformMatrix4fv(glGetUniformLocation(program, "model"), 1, GL_FALSE, glm::value_ptr(transform));
    VAO& mesh = m_meshMapper[MESH_ID::CUBE];
    glBindVertexArray(mesh.vaoId);
    glDrawArrays(GL_TRIANGLES, 0, mesh.size);
}

bool OGl::createShader(const uint16_t programID, const char* vertexShaderSrc, const char* fragmentShaderSrc) {
    if(m_programMapper.count(programID)) {
        std::cout << "ERROR: Graphic pipline with id" << programID << "is already loaded to the graphic system" << std::endl;
        return false;
    }

    
    int success;
    bool isCreated = true;
    char infoLog[512];

    // Create vertex shader, compile and check for errors
    uint16_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSrc, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR: VERTEX_SHADER::COMPILATION_FAILD" << std::endl << infoLog << std::endl;
        isCreated = false;
    }

    // Crate fragment shader, compile and check for errors
    uint16_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSrc, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR: FRAGMENT_SHADER::COMPILATION_FAILD" << std::endl << infoLog << std::endl;
        isCreated = false;
    }

    // Generate shader program (graphic pipline), Link all shaders and check for error
    uint16_t graphicPipline = glCreateProgram();
    glAttachShader(graphicPipline, vertexShader);
    glAttachShader(graphicPipline, fragmentShader);
    glLinkProgram(graphicPipline);
    glGetProgramiv(graphicPipline, GL_LINK_STATUS, &success);
    if(!success || !isCreated) {
        glGetProgramInfoLog(graphicPipline, 512, NULL, infoLog);
        std::cout << "ERROR: PROGRAM::LINKING_FAILD" << std::endl << infoLog << std::endl;
        glDeleteShader(vertexShader);
	    glDeleteShader(fragmentShader);
        glDeleteProgram(graphicPipline);
        isCreated = false;
    }
    else {
        m_programMapper.insert({programID, graphicPipline});
    }
    return isCreated;
}

void OGl::createVAO(const uint16_t meshID, MeshDiscription description) {
    // Generate and bind buffer
    uint32_t vao, vbo;    
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //Pass data to the buffers
    float* data = NULL;
    uint32_t type = GL_DYNAMIC_DRAW;
    uint32_t bufferSize = description.bufferSize;
    if(description.vertices.size() != 0u) {
        type = GL_STATIC_DRAW;
        data = description.vertices.data();
        bufferSize = description.vertices.size();
    }
    glBufferData(GL_ARRAY_BUFFER, bufferSize * sizeof(float), data, type);

    // Calculate vertex size 
    std::vector<uint32_t>& offsets = description.offsets;
    uint32_t stride = 0u;
    for(auto offset : offsets) {
        stride += offset;
    }

    // Create vertex pointers
    uint32_t offset = 0u;
    for (uint32_t idx = 0u; idx < offsets.size(); ++idx) {
        uint32_t partSize = offsets.at(idx);
        glVertexAttribPointer(idx, partSize, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
        glEnableVertexAttribArray(idx);
    }

    // Cleanup, bind default buffers
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    m_meshMapper.insert({meshID, {vao, vbo, bufferSize/stride}});
}