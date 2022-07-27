#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Button.hpp"
#include "Mouse.hpp"

Button::Button(SDL_Renderer* p_renderer, const char* p_id, SDL_Texture* p_tex, Vector2i p_pos, Vector2i p_prop)
  :renderer(p_renderer), id(p_id), tex(p_tex)
{
  isSelected = false;

  srcrect.x = 0;
  srcrect.y = 0;
  srcrect.w = p_prop.x;
  srcrect.h = p_prop.y;

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
    if (strcmp(id, "play") == 0)
    {
      if (hasIntersection)
        tex = IMG_LoadTexture(renderer, "res/gfx/play-button-hover.png");
      else 
        tex = IMG_LoadTexture(renderer, "res/gfx/play-button.png");
    }
    else if (strcmp(id, "exit") == 0) 
    {
      if (hasIntersection)
        tex = IMG_LoadTexture(renderer, "res/gfx/exit-button-hover.png");
      else 
        tex = IMG_LoadTexture(renderer, "res/gfx/exit-button.png");
    }
  }
  else if (p_event.type == SDL_MOUSEBUTTONUP)
  {
    if (!hasIntersection) return;

    std::cout << id << " button clicked " << std::endl;
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
