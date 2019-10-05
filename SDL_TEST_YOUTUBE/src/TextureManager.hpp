#pragma once

#include "RenderUnity/RenderUnity.hpp"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName);
};
