#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameMath.hpp"
#include "Mouse.hpp"

class Button
{
public:
  Button(SDL_Renderer* p_renderer, const char* p_id, SDL_Texture* p_tex, Vector2i p_pos, Vector2i p_prop);
  void update(Mouse& p_mouse, SDL_Event p_event);
  void draw();
  const char* getId();
  SDL_Rect srcrect, dstrect;
  bool isSelected = false;
  bool mouseIsOver = false;
private:
  SDL_Renderer* renderer;
  SDL_Texture* tex;
  const char* id;
};
