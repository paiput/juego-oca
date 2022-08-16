#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "Player.hpp"
#include "GameMath.hpp"

class Square
{
public:
  Square();
  Square(SDL_Renderer* p_renderer, int p_n, int p_type, Vector2i p_pos);
  void draw();
  int getN();
  int getType();
private:
  SDL_Renderer* renderer;
  SDL_Texture* tex;
  SDL_Rect srcdst;
  int nSquare;
  int type = 0;
};
