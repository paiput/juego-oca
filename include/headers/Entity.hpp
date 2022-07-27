#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameMath.hpp"

class Entity
{
public:
  Entity(SDL_Texture* p_tex, Vector2i p_pos, Vector2i p_prop);
  Vector2i& getPos();
  Vector2i& getProp();
  SDL_Texture* getTex();
  SDL_Rect getCurrentFrame();
private:
  Vector2i pos;
  Vector2i prop;
  SDL_Texture* tex;
  SDL_Rect currentFrame;
};
