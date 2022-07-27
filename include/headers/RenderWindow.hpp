#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include "GameMath.hpp"

class RenderWindow 
{
public:
  RenderWindow(const char* p_title, int p_w, int p_h);
  SDL_Texture* loadTexture(const char* p_filePath);
  void cleanUp();
  void clear();
  void render(SDL_Texture* p_tex, SDL_Rect* p_srcrect, SDL_Rect* p_dstrect);
  void renderEntity(Entity& p_entity);
  void display();
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};