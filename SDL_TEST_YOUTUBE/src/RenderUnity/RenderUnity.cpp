#include "RenderUnity.hpp"

#include <iostream>
#include <memory>

SDL_Renderer* RenderUnity::renderer = nullptr;
SDL_Window* RenderUnity::window = nullptr;

RenderUnity::RenderUnity(const int fps) : FPS(fps), frameStart(0)
{
    frameDelay = 1000 / FPS;
}

bool RenderUnity::init(const char* title, const int screenW, const int screenH, bool fullscreen)
{
    windowWidth = screenW;
    windowHeight = screenH;
    
    int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
    
    if( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return false;
    }
    
    RenderUnity::window = SDL_CreateWindow(title,
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           windowWidth,
                                           windowHeight,
                                           flags
                                           );
    
    if(RenderUnity::window == nullptr) {
        std::cout << "Error creating SDL Window: " << SDL_GetError() << std::endl;
        return false;
    }
    
    RenderUnity::renderer = SDL_CreateRenderer(RenderUnity::window, -1, SDL_RENDERER_ACCELERATED);
    
    if(RenderUnity::renderer == nullptr) {
        std::cout << "Error creating SDL Renderer: " << SDL_GetError() << std::endl;
        return false;
    }
    
    // set canvas' background color as white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        return false;
    }

    std::cout << "Renderer initialized!" << std::endl;
    return true;
}

void RenderUnity::clean()
{
    SDL_DestroyRenderer(renderer);
    RenderUnity::renderer = nullptr;
    
    SDL_DestroyWindow(window);
    RenderUnity::window = nullptr;
    
    IMG_Quit();
    SDL_Quit();
    
    std::cout << "RenderUnity cleaned!" << std::endl;
}

void RenderUnity::startFrame()
{
    frameStart = SDL_GetTicks();
}

void RenderUnity::endFrame()
{
    frameTime = SDL_GetTicks() - frameStart;
    
    if(frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime);
    }
    
    frameStart = 0;
}
