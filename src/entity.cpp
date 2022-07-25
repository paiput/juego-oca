#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"

// Height and width must be the same for all textures
Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex)
  :x(p_x), y(p_y), tex(p_tex)
{
  currentFrame.x = 0;
  currentFrame.y = 0;
  currentFrame.w = 308;
  currentFrame.h = 284;
}

float Entity::getX()
{
  return x;
}

float Entity::getY()
{
  return y;
}

SDL_Texture* Entity::getTex()
{
  return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
  return currentFrame;
}
