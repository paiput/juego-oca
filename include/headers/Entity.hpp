#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameMath.hpp"

class Entity
{
public:
  Entity(Vector2i p_pos, SDL_Texture* p_tex);
  Vector2i& getPos();
  SDL_Texture* getTex();
  SDL_Rect getCurrentFrame();
private:
  Vector2i pos;
  SDL_Rect currentFrame;
  SDL_Texture* tex;
};
