#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Button.hpp"
#include "Mouse.hpp"

Button::Button(SDL_Renderer* p_renderer, SDL_Texture* p_tex, Vector2i p_pos, Vector2i p_prop)
  :renderer(p_renderer), tex(p_tex)
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

void Button::update(Mouse& mouse)
{
  bool a = SDL_HasIntersection(&mouse.point, &dstrect);
  std::cout << "Position of mouse is:" << std::endl;
  std::cout << "Has intersection: " <<  a << std::endl;
}

void Button::draw()
{
  SDL_RenderCopy(renderer, tex, &srcrect, &dstrect);
}
