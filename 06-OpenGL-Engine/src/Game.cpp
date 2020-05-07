// System headers
#include <iostream>
// Own headers
#include <AssetsID.h>
#include <Game.h>

void Game::loadScene() {
    std::cout << "Load scene" << std::endl;
}

void Game::init() {
    OOPEngine::init();
    createShader("Default", "Default", SHADER_ID::DEFAULT);
    loadMesh("cube.obj", MESH_ID::CUBE);
}

int main(int argc, char** argv ) {
    std::cout << "Project Template: 06-OpenGL-Engine"<< std::endl;
    Game game;
    game.run();
}