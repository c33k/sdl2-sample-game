#pragma once

#include "RenderUnity/RenderUnity.hpp"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void DrawTexture(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};
