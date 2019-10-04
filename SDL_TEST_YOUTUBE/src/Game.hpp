#ifndef Game_hpp
#define Game_hpp

#include <memory>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "GameObject.hpp"

class Game {
public:
    Game();
    ~Game();
    
    void init(const char* title, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running() { return isRunning; }
    
private:
    bool isRunning;
    int windowWidth, windowHeight;
    
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    std::unique_ptr<GameObject> player;
};

#endif /* Game_hpp */
