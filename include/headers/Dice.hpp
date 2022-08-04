#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameMath.hpp"
#include "Mouse.hpp"

class Dice
{
public:
  Dice(SDL_Renderer* p_renderer, Vector2i p_pos, Vector2i p_prop);
  void update(Mouse& p_mouse, SDL_Event p_event);
  void draw();
  int roll();
  bool isClicked = false;
private:
  SDL_Renderer* renderer;
  SDL_Texture* tex;
  SDL_Rect srcrect, dstrect;
};
