#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct Vector2i
{
  Vector2i(int p_x, int p_y);
  void print();
  int x, y;
};
