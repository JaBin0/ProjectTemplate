// System headers
#include <vector>
#include <fstream>
#include <iostream>
// Engine headers
#include <AssetLoader.h>

// Constants
const std::string AssetLoader::SHADER_PATH = "assets//shaders//";
const std::string AssetLoader::MESH_PATH = "assets//meshes//";

std::string AssetLoader::loadFile(const std::string fileName) {
    std::string content = "";
    std::fstream file;
    file.open(fileName, std::fstream::in);
    if(file.is_open()) {
        std::getline(file, content, '\0');
    }
    else {
        std::cout << "ERROR: File <" << fileName.data() << "> was not properly loaded" << std::endl;
    }
    file.close();
    return content;
}

bool AssetLoader::loadMeshData(const std::string meshName, std::vector<float>& data) {
    data.clear();
    std::fstream meshFile;
    meshFile.open(meshName, std::fstream::in);
    if(!meshFile.is_open()) {
        std::cout << "ERROR: Mesh <" << meshName.data() << "> couldn't be opened" << std::endl;
        return false;
    }

    std::string line;
    std::vector<glm::vec3> verticies;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> textures;

    while(!meshFile.eof()) {
        std::getline(meshFile, line);
        // Get tag
        uint32_t bTagIdx = line.find_first_not_of(" \n"); 
        // Ommit empty line
        if(bTagIdx == 0xFFFFFFFFu) { 
            continue;
        }
        uint32_t eTagIdx = line.find_first_of(" ", bTagIdx);
        std::string tag = line.substr(bTagIdx, eTagIdx - bTagIdx);
        // line.length will be always grater then size of content
        std::string content = line.substr(eTagIdx+1, line.length());
        // Omit comments and object name
        if(tag == "#" || tag == "o" || tag == "s") {
            continue;
        }

        glm::vec3 point;
        if(tag == "v") {
            getPointData(content, 3, point);
            verticies.push_back(point);
        } 
        else if (tag == "vt") {
            getPointData(content, 2, point);
            textures.push_back({point.x, point.y});
        } 
        else if (tag == "vn") {
            getPointData(content, 3, point);
            normals.push_back(point);
        } 
        else if (tag == "f") {
            glm::ivec3 face;
            uint32_t bIdx = 0;
            // Get every vertex of triangle
            for(uint8_t valIdx = 0; valIdx < 3; ++valIdx ) {
                uint32_t eIdx = content.find_first_of(" \n", bIdx);
                uint32_t lenght = eIdx - bIdx;
                std::string vertexContent = content.substr(bIdx, lenght);

                // Get indexes of vertex
                uint32_t bIdxNum = 0;
                for(uint8_t idx = 0; idx < 3; ++idx ) {
                    uint32_t eIdxNum = vertexContent.find_first_of("/\n", bIdxNum);
                    uint32_t length = eIdxNum - bIdxNum;
                    if(length != 0) {
                        uint16_t num = std::stoi(vertexContent.substr(bIdxNum, length));
                        if(idx == 0) {
                            glm::vec3 point = verticies.at(num-1);
                            data.push_back(point.x);
                            data.push_back(point.y);
                            data.push_back(point.z);
                        }
                        else if (idx == 1) {
                            glm::vec2 point = textures.at(num-1);
                            data.push_back(point.x);
                            data.push_back(point.y);
                        }
                        else {
                            glm::vec3 point = normals.at(num-1);
                            data.push_back(point.x);
                            data.push_back(point.y);
                            data.push_back(point.z);
                        }
                    }
                    bIdxNum = eIdxNum + 1;
                }
                bIdx = eIdx + 1;
            }
        }
    }
    meshFile.close();
    return true;
}

 
void AssetLoader::getPointData(const std::string content, const uint8_t& size, glm::vec3& point) {
    uint32_t bIdx = 0;
    for(uint8_t valIdx = 0; valIdx < size; ++valIdx ) {
        uint32_t eIdx = content.find_first_of(" \n", bIdx);
        uint32_t lenght = eIdx - bIdx;
        point[valIdx] = std::stof(content.substr(bIdx, lenght));
        bIdx = eIdx + 1;
    }
}