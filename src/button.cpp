#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Button.hpp"
#include "Mouse.hpp"

Button::Button(SDL_Renderer* p_renderer, const char* p_id, Vector2i p_pos, Vector2i p_prop)
  :renderer(p_renderer), id(p_id)
{
  tex = IMG_LoadTexture(renderer, "res/gfx/buttons.png");

  srcrect.x = 0;
  srcrect.w = 500;
  srcrect.h = 120;

  dstrect.x = p_pos.x;
  dstrect.y = p_pos.y;
  dstrect.h = p_prop.y;
  dstrect.w = p_prop.x;
}

void Button::update(Mouse& p_mouse, SDL_Event p_event)
{
  bool hasIntersection = SDL_HasIntersection(&p_mouse.point, &dstrect);

  if (p_event.type == SDL_MOUSEMOTION)
  {
    if (hasIntersection)
    {
      mouseIsOver = true;
      srcrect.x = 500;
    }
    else
    {
      mouseIsOver = false;
      srcrect.x = 0;
    }
  }
  else if (p_event.type == SDL_MOUSEBUTTONUP)
  {
    if (!hasIntersection) return;

    std::cout << id << " button clicked" << std::endl;
  }
}

void Button::draw()
{
  SDL_RenderCopy(renderer, tex, &srcrect, &dstrect);
}

const char* Button::getId()
{
  return id;
}
