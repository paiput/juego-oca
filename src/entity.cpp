#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"
#include "GameMath.hpp"

// Height and width must be the same for all textures
Entity::Entity(Vector2i p_pos, Vector2i p_prop, SDL_Texture* p_tex)
  :pos(p_pos), prop(p_prop), tex(p_tex)
{
  currentFrame.x = 0;
  currentFrame.y = 0;
  currentFrame.w = prop.x;
  currentFrame.h = prop.y;
}

Vector2i& Entity::getPos()
{
  return pos;
}

Vector2i& Entity::getProp()
{
  return prop;
}

SDL_Texture* Entity::getTex()
{
  return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
  return currentFrame;
}
