//#include <iostream>
//#include "SDL2/SDL.h"
//
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//
//int main(int argc, char* argv[])
//{
//    SDL_Init(SDL_INIT_VIDEO);
//    
//    SDL_Window* window = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
//    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//    SDL_RenderClear(renderer);
//    SDL_RenderPresent(renderer);
//    
//    // A basic main loop to prevent blocking
//    bool is_running = true;
//    SDL_Event event;
//    while (is_running) {
//        while (SDL_PollEvent(&event)) {
//            if (event.type == SDL_QUIT) {
//                is_running = false;
//            }
//        }
//        SDL_Delay(16);
//    }
//    
//    
//}
