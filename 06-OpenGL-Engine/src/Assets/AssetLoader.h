#pragma once
// System headers
#include <string>
#include <vector>
#include <glm-0.9.8.0/gtc/type_ptr.hpp>

/* Brief:
 *   TODO!
*/
class AssetLoader {
public:
    /* Brief:
     *   Load content of the file given in the parameter.
     * param fileName - Name of the file to load
     * return content of the file 
    */ 
    static std::string loadFile(const std::string fileName);

    // Load mesh data from external file based on the meshName and store result in data parameter
    // * param meshName - Name, and eventualy path, to the external file with mesh that should be loaded
    // * param data - Container to store all loaded data
    // * return - Return true if new data was loaded properly
    static bool loadMeshData(const std::string meshName, std::vector<float>& data);

    // Path to the shaders folder
    static const std::string SHADER_PATH;

    // Path to the meshes folder
    static const std::string MESH_PATH;

private: // Methods
    // Get values o point from content and store it in the point. 2D point will ocupy only two first pos
    static void getPointData(const std::string content, const uint8_t& size, glm::vec3& point);
};