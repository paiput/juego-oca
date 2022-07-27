#pragma once
#include <SDL2/SDL.h>

class Mouse
{
public:
  SDL_Rect rect;
  SDL_Rect point;
  Mouse(SDL_Renderer* p_renderer);
  void update();
  void draw();
private:
  SDL_Renderer* renderer;
  SDL_Texture* tex;
};
