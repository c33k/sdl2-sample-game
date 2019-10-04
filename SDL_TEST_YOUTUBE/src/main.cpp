#include <iostream>
#include "SDL2/SDL.h"
#include "./Game.hpp"

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

int main(int argc, char* argv[])
{
    // using this to limit frame rate to 60 frames per second
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    
    Uint32 frameStart;
    int frameTime;
    
    Game* game = new Game();
    game->init("Test", SCREEN_WIDTH, SCREEN_HEIGHT, false);
    
    while(game->running()) {
        frameStart = SDL_GetTicks(); // how many miliseconds after we initialized SDL
        
        game->handleEvents();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        
        if(frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    game->clean();
    
    return 0;
}
