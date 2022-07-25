#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
public:
  Entity(float p_x, float p_y, SDL_Texture* p_tex);
  float getX();
  float getY();
  SDL_Texture* getTex();
  SDL_Rect getCurrentFrame();
private:
  double x, y;
  SDL_Rect currentFrame;
  SDL_Texture* tex;
};
