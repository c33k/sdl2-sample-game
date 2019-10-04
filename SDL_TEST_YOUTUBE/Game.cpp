#include <iostream>
#include "Game.hpp"

SDL_Texture* playerTex;
SDL_Rect srcR, destR;

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
    SDL_Surface* tmpSurface = IMG_Load("assets/player.png");
    playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    
    std::cout << "created render! ..." << std::endl;
}

void Game::update()
{
    destR.w = 172;
    destR.h = 238;
    destR.y = windowHeight - destR.h;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    
    SDL_RenderCopy(renderer, playerTex, NULL, &destR);
    
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
        case SDL_KEYDOWN:
            switch( event.key.keysym.sym ){
                case SDLK_LEFT:
                    destR.x -= 1;
                    break;
                case SDLK_RIGHT:
                    destR.x += 1;
                    break;
                default:
                    break;
            }
            break;
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
