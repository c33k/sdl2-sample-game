#include "Map.hpp"

#include "./TextureManager.hpp"
#include <iostream>

Map::Map()
{
    water = TextureManager::LoadTexture("assets/water.png");
    ground = TextureManager::LoadTexture("assets/ground.png");
    groundShadow = TextureManager::LoadTexture("assets/ground-shadow.png");
    
    dest.x = dest.y = src.y = src.x = 0;
    dest.w = dest.h = src.w = src.h = 32;
}

Map::~Map()
{
    SDL_DestroyTexture(water);
    SDL_DestroyTexture(ground);
    SDL_DestroyTexture(groundShadow);
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
            
            std::cout << "row: " << row << " col: " << col << std::endl;
            
            dest.x = 32 * col;
            dest.y = 32 * row;
            
            switch (type) {
                case 0:
                    TextureManager::DrawTexture(water, src, dest);
                    break;
                case 1:
                    TextureManager::DrawTexture(ground, src, dest);
                    break;
                case 2:
                    TextureManager::DrawTexture(groundShadow, src, dest);
                    break;
                default:
                    break;
            }
        }
    }
}
