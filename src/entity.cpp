#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"
#include "GameMath.hpp"

Entity::Entity(SDL_Renderer* p_renderer, SDL_Texture* p_tex, Vector2i p_pos, Vector2i p_prop)
  :renderer(p_renderer), pos(p_pos), prop(p_prop), tex(p_tex)
{
  currentFrame.x = pos.x;
  currentFrame.y = pos.y;
  currentFrame.w = prop.x;
  currentFrame.h = prop.y;
}

void Entity::draw()
{
  SDL_RenderCopy(renderer, tex, NULL, &currentFrame);
}

void Entity::updatePos(int p_pos)
{
  if (p_pos < 8)
  {
    currentFrame.x = 287 + 75 * p_pos + 15 * p_pos;
  }
  else if (p_pos < 15)
  {
    currentFrame.x = 287 + 75 * 7 + 15 * 7; 
    currentFrame.y = 14 + 75 * (p_pos % 8) + 15 * (p_pos % 8);
  }
  else if (p_pos < 22)
  {
    currentFrame.x = (287 + 75 * 7 + 15 * 7) - 75 * (p_pos % 8) - 15 * (p_pos % 8);
    currentFrame.y = 14 + 75 * 7 + 15 * 7;
  }
  else if (p_pos < 29)
  {
    currentFrame.x = 287;
    currentFrame.y = (14 + 75 * 7 + 15 * 7) - 75 * (p_pos % 8) - 15 * (p_pos % 8);
  }
  SDL_RenderCopy(renderer, tex, NULL, &currentFrame);
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

SDL_Rect& Entity::getCurrentFrame()
{
  return currentFrame;
}
