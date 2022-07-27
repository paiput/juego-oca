#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameMath.hpp"

struct Button
{
public:
  Button(SDL_Texture* p_tex, Vector2i p_pos, Vector2i p_prop);
  void update();
  void draw();
  SDL_Texture* tex;
  SDL_Rect srcrect, dstrect;
  bool isSelected;
};
