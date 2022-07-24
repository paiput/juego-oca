#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
  :window(nullptr), renderer(nullptr)
{
  window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

  if (window == nullptr)
  {
    std::cout << "Window failed to init. SDL_ERROR: " << SDL_GetError() << std::endl;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
  SDL_Texture* texture = nullptr;
  texture = IMG_LoadTexture(renderer, p_filePath);

  if (texture == nullptr)
    std::cout << "Failed to load texture. SDL_ERROR: " << SDL_GetError() << std::endl;

  return texture;
}

void RenderWindow::cleanUp()
{
  SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
  SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* p_tex)
{
  SDL_RenderCopy(renderer, p_tex, nullptr, nullptr);
}

void RenderWindow::display()
{
  SDL_RenderPresent(renderer);
}
