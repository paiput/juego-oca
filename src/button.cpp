#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Button.hpp"
#include "GameMath.hpp"

Button::Button(SDL_Texture* p_tex, Vector2i p_pos, Vector2i p_prop)
  :tex(p_tex)
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
