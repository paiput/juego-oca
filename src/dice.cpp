#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <time.h>

#include "Dice.hpp"
#include "GameMath.hpp"

Dice::Dice(SDL_Renderer* p_renderer, Vector2i p_pos, Vector2i p_prop)
  :renderer(p_renderer)
{
  tex = IMG_LoadTexture(renderer, "res/gfx/dice.png");

  srcrect.x = 0;
  srcrect.y = 0;
  srcrect.w = 125;
  srcrect.h = 125;

  dstrect.x = p_pos.x;
  dstrect.y = p_pos.y;
  dstrect.h = p_prop.y;
  dstrect.w = p_prop.x;
}

void Dice::draw()
{
  SDL_RenderCopy(renderer, tex, &srcrect, &dstrect);
}

void Dice::update(Mouse& p_mouse, SDL_Event p_event)
{
  bool hasIntersection = SDL_HasIntersection(&p_mouse.point, &dstrect);

  if (p_event.type == SDL_MOUSEBUTTONUP)
  {
    if (hasIntersection) isClicked = true;
    else isClicked = false;
  }
}

int Dice::roll()
{
  int randomResult = rand() % 6 + 1;
  srcrect.x = srcrect.w * randomResult - srcrect.w;
  std::cout << "salio " << randomResult << std::endl;
  return randomResult;
}
