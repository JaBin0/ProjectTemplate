// System headers
#include <fstream>
#include <iostream>
// Engine headers
#include <AssetLoader.h>

// Constants
const std::string AssetLoader::SHADER_PATH = "assets//Shaders//";

std::string AssetLoader::loadFile(const std::string fileName) {
    std::string content = "";
    std::fstream file;
    file.open((AssetLoader::SHADER_PATH + fileName), std::fstream::in);
    if(file.is_open()) {
        std::getline(file, content, '\0');
    }
    else {
        std::cout << "ERROR: File <" << fileName.data() << "> was not properly loaded" << std::endl;
    }
    file.close();
    return content;
}