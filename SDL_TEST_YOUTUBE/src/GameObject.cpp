#include "GameObject.hpp"

#include <iostream>
#include "TextureManager.hpp"

GameObject::GameObject(const char* texture, const int x, const int y)
{
    this->texture = TextureManager::LoadTexture(texture);
    xpos = x;
    ypos = y;
    
    // set width based on the image itself
    SDL_QueryTexture(this->texture, NULL, NULL, &width, &height);
}

GameObject::~GameObject()
{
    SDL_DestroyTexture(texture);
    
    std::cout << "deleted object" << std::endl;
}

void GameObject::moveLeft()
{
    xpos -= width;
}

void GameObject::moveRight()
{
    xpos += width;
}

void GameObject::moveUp()
{
    ypos -= width;
}

void GameObject::moveDown()
{
    ypos += width;
}

void GameObject::update()
{
    // uses the whole image
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
    SDL_RenderCopy(RenderUnity::renderer, texture, &srcRect, &destRect);
}

int GameObject::getHeight()
{
    return height;
}

int GameObject::getWidth()
{
    return width;
}

int GameObject::getX()
{
    return xpos;
}

int GameObject::getY()
{
    return ypos;
}
