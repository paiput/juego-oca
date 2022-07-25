#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"
#include "GameMath.hpp"

// Height and width must be the same for all textures
Entity::Entity(Vector2i p_pos, SDL_Texture* p_tex)
  :pos(p_pos), tex(p_tex)
{
  currentFrame.x = 0;
  currentFrame.y = 0;
  currentFrame.w = 308;
  currentFrame.h = 284;
}

Vector2i& Entity::getPos()
{
  return pos;
}

SDL_Texture* Entity::getTex()
{
  return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
  return currentFrame;
}
