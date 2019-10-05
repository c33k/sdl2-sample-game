#include "Game.hpp"

#include <iostream>
#include "./RenderUnity/RenderUnity.hpp"

// temporary
const int lvl1[Map::MAP_HEIGHT][Map::MAP_WIDTH] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,1,1,0,0,0}
};

void Game::init()
{
    player = std::make_unique<GameObject>("assets/player.png");
    map = std::make_unique<Map>();
    
    map->load(lvl1);
    
    isRunning = true;
    
    std::cout << "Game initialized!" << std::endl;
}

void Game::update()
{
    player->update();
}

void Game::render()
{
    SDL_RenderClear(RenderUnity::renderer);
    map->render();
    player->render();
    SDL_RenderPresent(RenderUnity::renderer);
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
                    player->moveLeft();
                    break;
                case SDLK_RIGHT:                    
                    player->moveRight();
                    break;
                case SDLK_DOWN:
                    player->moveDown();
                    break;
                case SDLK_UP:
                    player->moveUp();
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
    player.reset();
    isRunning = false;
    
    std::cout << "Game cleaned!" << std::endl;
}
