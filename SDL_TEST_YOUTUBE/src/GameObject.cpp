#include <iostream>
#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* texture, SDL_Renderer* renderer, const int x, const int y)
{
    this->renderer = renderer;
    this->texture = TextureManager::LoadTexture(texture, this->renderer);
    xpos = x;
    ypos = y;
    
    // set width based on the image itself
    SDL_QueryTexture(this->texture, NULL, NULL, &width, &height);
}

GameObject::~GameObject()
{
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);    
}

void GameObject::setPosition(const int x, const int y)
{
    // doesn't allow object to go out of the screen (for now)
    xpos = (x >= 0) ? x : 0;
    ypos = (y >= 0) ? y : 0;
}

void GameObject::update()
{    
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = width;
    srcRect.h = height;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}

void GameObject::render()
{
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}

int GameObject::getHeight()
{
    return height;
}

int GameObject::getWidth()
{
    return width;
}
