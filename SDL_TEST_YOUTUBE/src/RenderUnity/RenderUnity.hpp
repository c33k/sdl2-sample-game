#ifndef RenderUnity_hpp
#define RenderUnity_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class RenderUnity {
public:
    RenderUnity(const int FPS);
    bool init(const char* title, const int screenW, const int screenH, bool fullscreen);
    
    void startFrame();
    void endFrame();
    
    
    void clean();
    
public:
    static SDL_Renderer* renderer; // exposed statically to avoid copy
    
private:
    static SDL_Window* window;
    int windowWidth, windowHeight;
    
    // using this to limit frame rate to 60 frames per second
    const int FPS;
    int frameDelay = 1000 / FPS;
    
    Uint32 frameStart; // how many miliseconds after we initialized SDL
    int frameTime;
};

#endif /* RenderUnity_hpp */
