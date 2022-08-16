#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Square.hpp"
#include "GameMath.hpp"

Square::Square()
{}

Square::Square(SDL_Renderer* p_renderer, int p_n, int p_type, Vector2i p_pos)
  :renderer(p_renderer), nSquare(p_n), type(p_type)
{
  srcdst.x = p_pos.x;
  srcdst.y = p_pos.y;
  srcdst.w = 75;
  srcdst.h = 75;
  switch (type)
  {
    case 1:
      tex = IMG_LoadTexture(renderer, "res/gfx/square-good.png");
      break;
    case -1:
      tex = IMG_LoadTexture(renderer, "res/gfx/square-bad.png");
      break;
    default:
      tex = IMG_LoadTexture(renderer, "res/gfx/square-normal.png");
      break;
  }
}

void Square::draw()
{
  SDL_RenderCopy(renderer, tex, NULL, &srcdst);
}

int Square::getN()
{
  return nSquare;
}

int Square::getType()
{
  return type;
}
