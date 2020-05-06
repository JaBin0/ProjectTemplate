// System headers
#include <iostream>
// Own headers
#include <Game.h>

void Game::loadScene() {
    std::cout << "Load scene" << std::endl;
}

int main(int argc, char** argv ) {
    std::cout << "Project Template: 06-OpenGL-Engine"<< std::endl;
    Game game;
    game.run();
}