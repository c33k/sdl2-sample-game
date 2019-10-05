#include "Game.hpp"

#include <iostream>
#include "./RenderUnity/RenderUnity.hpp"

void Game::init()
{
    player = std::make_unique<GameObject>("assets/player.png");
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
                    player->setPosition(player->getX() - player->getWidth(), player->getY());
                    break;
                case SDLK_RIGHT:
                    player->setPosition(player->getX() + player->getWidth(), player->getY());
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
