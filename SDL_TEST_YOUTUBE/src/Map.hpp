#ifndef Map_hpp
#define Map_hpp

#include "./RenderUnity/RenderUnity.hpp"

class Map {
public:
    static const int MAP_WIDTH = 25;
    static const int MAP_HEIGHT = 20;
    
public:
    Map();
    ~Map();
    
    void load(const int lvl[Map::MAP_HEIGHT][Map::MAP_WIDTH]);
    void render();
    
private:
    SDL_Rect src, dest;
    SDL_Texture* tileSprite;
    
    int map[Map::MAP_HEIGHT][Map::MAP_WIDTH];
};

#endif /* Map_hpp */
