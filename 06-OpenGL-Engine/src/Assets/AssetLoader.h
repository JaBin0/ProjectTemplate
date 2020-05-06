#pragma once
// System headers
#include <string>

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

    // Path to the shaders folder
    static const std::string SHADER_PATH;
};