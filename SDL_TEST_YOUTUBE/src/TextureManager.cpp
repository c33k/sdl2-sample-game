#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
    SDL_Surface* tmpSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(RenderUnity::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    
    return tex;
}

void TextureManager::DrawTexture(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(RenderUnity::renderer, texture, &src, &dest);
}
