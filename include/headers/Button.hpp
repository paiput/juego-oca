#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameMath.hpp"
#include "Mouse.hpp"

class Button
{
public:
  Button(SDL_Renderer* p_renderer, SDL_Texture* p_tex, Vector2i p_pos, Vector2i p_prop);
  void update(Mouse& mouse);
  void draw();
  SDL_Rect srcrect, dstrect;
  bool isSelected = false;
  bool mouseIsOver = false;
private:
  SDL_Renderer* renderer;
  SDL_Texture* tex;
};
