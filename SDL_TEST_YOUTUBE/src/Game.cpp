#include <iostream>
#include "Game.hpp"
#include "TextureManager.hpp"

Game::Game() : window(nullptr), renderer(nullptr)
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
    windowWidth = width;
    windowHeight = height;
    
    int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
    isRunning = true;
    
    if( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }
    
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    
    if(window == nullptr) {
        std::cout << "Error creating SDL Window: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }
    
     renderer = SDL_CreateRenderer(window, -1, 0);
    
    if(renderer == nullptr) {
        std::cout << "Error creating SDL Renderer: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    // create player
    player = std::make_unique<GameObject>("assets/player.png", renderer);    
    std::cout << "created render! ..." << std::endl;
}

void Game::update()
{
    player->update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    player->render();
    SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
//        case SDL_KEYDOWN:
//            switch( event.key.keysym.sym ){
//                case SDLK_LEFT:
//                    destR.x -= 1;
//                    break;
//                case SDLK_RIGHT:
//                    destR.x += 1;
//                    break;
//                default:
//                    break;
//            }
//            break;
        default:
            break;
    }
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}
