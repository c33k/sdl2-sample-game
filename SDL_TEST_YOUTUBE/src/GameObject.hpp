#pragma once

#include "RenderUnity/RenderUnity.hpp"

class GameObject {
public:
    GameObject(const char* texture, const int xpos = 0, const int ypos = 0);
    ~GameObject();
    
    void update();
    void render();

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    
    int getX();
    int getY();
    int getHeight();
    int getWidth();
    
private:
    int xpos, ypos, width, height;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
};
