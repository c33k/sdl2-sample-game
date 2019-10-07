#include "Map.hpp"

#include "./TextureManager.hpp"
#include <iostream>

Map::Map()
{
    tileSprite = TextureManager::LoadTexture("assets/tilesprite.png");
    dest.x = dest.y = src.y = src.x = 0;
    dest.w = dest.h = src.w = src.h = 32;
}

Map::~Map()
{
    SDL_DestroyTexture(tileSprite);
}

void Map::load(const int lvl[Map::MAP_HEIGHT][Map::MAP_WIDTH])
{
    for(int row = 0; row < Map::MAP_HEIGHT; ++row) {
        for(int col = 0; col < Map::MAP_WIDTH; ++col) {
            map[row][col] = lvl[row][col];
        }
    }
}

void Map::render()
{
    int type = 0;
    
    for(int row = 0; row < Map::MAP_HEIGHT; ++row) {
        for(int col = 0; col < Map::MAP_WIDTH; ++col) {
            type = map[row][col];
            
            dest.x = 32 * col;
            dest.y = 32 * row;
            
            // water is in position 0, ground in position 32 and "ground shadow" in position 64            
            src.x = 32 * type;
            TextureManager::DrawTexture(tileSprite, src, dest);
        }
    }
}
