#include <iostream>
#include <memory>
#include "SDL2/SDL.h"
#include "./Game.hpp"
#include "./RenderUnity/RenderUnity.hpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;
const int FPS = 60;

int main(int argc, char* argv[])
{
    std::unique_ptr<Game> game = std::make_unique<Game>();
    std::unique_ptr<RenderUnity> renderUnity = std::make_unique<RenderUnity>(FPS);
    
    bool renderInitialized = renderUnity->init("Test", SCREEN_WIDTH, SCREEN_HEIGHT, false);
    
    if(!renderInitialized) {
        std::cout << "Failed to initialize render unity!" << std::endl;
        return -1;
    }
    
    game->init();
    
    while(game->running()) {
        renderUnity->startFrame();
        
        game->handleEvents();
        game->update();
        game->render();
        
        renderUnity->endFrame();
    }
    
    renderUnity->clean();
    game->clean();
    
    return 0;
}
