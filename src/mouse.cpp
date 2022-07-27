#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Mouse.hpp"

Mouse::Mouse(SDL_Renderer* p_renderer)
  :renderer(p_renderer)
{
  tex = IMG_LoadTexture(renderer, "res/gfx/mouse.png");
  rect.w = 25;
  rect.h = 25;
  point.w = 1;
  point.h = 1;      
  SDL_ShowCursor(false);
}

void Mouse::update()
{
  SDL_GetMouseState(&rect.x, &rect.y);
  point.x = rect.x;
  point.y = rect.y;
}

void Mouse::draw()
{
  SDL_RenderCopy(renderer, tex, NULL, &rect);
}
