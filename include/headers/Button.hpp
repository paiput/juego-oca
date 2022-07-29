#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameMath.hpp"
#include "Mouse.hpp"

class Button
{
public:
  Button(SDL_Renderer* p_renderer, const char* p_name, Vector2i p_pos, Vector2i p_prop);
  void update(Mouse& p_mouse, SDL_Event p_event);
  void draw();
  void cleanTexture();
  const char* getName();
  SDL_Rect srcrect, dstrect;
  bool isClicked = false;
  bool mouseIsOver = false;
private:
  SDL_Renderer* renderer;
  SDL_Texture* tex;
  const char* name;
};
