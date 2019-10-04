#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

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
    SDL_Window* window;
    SDL_Renderer* renderer;
    int windowWidth;
    int windowHeight;
};

#endif /* Game_hpp */
