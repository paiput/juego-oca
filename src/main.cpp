#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "Entity.hpp"
#include "GameMath.hpp"
#include "Button.hpp"
#include "Mouse.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main(int argc, char* argv[]) 
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    std::cout << "SDL_Init has failed. SDL_ERROR: " << SDL_GetError() << std::endl;

  if (!(IMG_Init(IMG_INIT_PNG)))
    std::cout << "IMG_Init has failed. SDL_ERROR: " << SDL_GetError() << std::endl;

  SDL_Window* window = SDL_CreateWindow(
    "GAME v1.0", 
    SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, 
    WINDOW_WIDTH, 
    WINDOW_HEIGHT, 
    SDL_WINDOW_SHOWN
  );
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  Mouse mouse(renderer);

  SDL_Texture* mainBackgroundTexture = IMG_LoadTexture(renderer, "res/gfx/main-menu-bg.png");
  SDL_Texture* gooseTexture = IMG_LoadTexture(renderer, "res/gfx/goose.png");
  SDL_Texture* playButton = IMG_LoadTexture(renderer, "res/gfx/play-button.png");
  SDL_Texture* exitButton = IMG_LoadTexture(renderer, "res/gfx/exit-button.png");
  
  Entity currentBackground(mainBackgroundTexture, Vector2i(0, 0), Vector2i(WINDOW_WIDTH, WINDOW_HEIGHT));

  std::vector<Button> mainMenuButtons = {
    Button(renderer, playButton, Vector2i(390, 275), Vector2i(500, 120)),
    Button(renderer, exitButton, Vector2i(390, 425), Vector2i(500, 120))
  };

  bool gameRunning = true;

  SDL_Event event;

  while (gameRunning)
  {
    mouse.update();
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        gameRunning = false;
        break;
      case SDL_MOUSEMOTION:
        // std::cout << "x:" << event.motion.x << " y:" << event.motion.y << std::endl;
        break;
      case SDL_MOUSEBUTTONUP:
        std::cout << "click" << std::endl;
        std::cout << "clicked in x:" << event.button.x << " and y:" << event.button.y << std::endl;
        mainMenuButtons[0].update(mouse);
        break;
      }
    }

    SDL_RenderClear(renderer);
    
    SDL_RenderCopy(renderer, currentBackground.getTex(), NULL, &currentBackground.getCurrentFrame());
    for (Button& b : mainMenuButtons)
    {
      b.draw();
    }
    mouse.draw();

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
