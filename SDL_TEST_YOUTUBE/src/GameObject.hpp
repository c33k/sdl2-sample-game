#pragma once

#include <SDL2/SDL.h>

class GameObject {
public:
    GameObject(const char* texture, SDL_Renderer* renderer, const int xpos = 0, const int ypos = 0);
    ~GameObject();
    
    void update();
    void render();

    void setPosition(const int x, const int y);
    int getHeight();
    int getWidth();
    
private:
    int xpos, ypos, width, height;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
};
