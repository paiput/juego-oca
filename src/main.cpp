#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "GameMath.hpp"

int main(int argc, char* argv[]) 
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    std::cout << "SDL_Init has failed. SDL_ERROR: " << SDL_GetError() << std::endl;

  if (!(IMG_Init(IMG_INIT_PNG)))
    std::cout << "IMG_Init has failed. SDL_ERROR: " << SDL_GetError() << std::endl;

  RenderWindow window("GAME v1.0", 1280, 720);

  SDL_Texture* currentBackground = window.loadTexture("res/gfx/main-menu-bg.png");
  SDL_Texture* gooseTexture = window.loadTexture("res/gfx/goose.png");

  Entity goose(Vector2i(0, 0), Vector2i(308, 284), gooseTexture);

  bool gameRunning = true;

  SDL_Event event;

  while (gameRunning)
  {
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        gameRunning = false;
        break;
      case SDL_MOUSEMOTION:
        std::cout << "x:" << event.motion.x << " y:" << event.motion.y << std::endl;
        break;
      }
    }

    window.clear();
    window.render(currentBackground);
    window.renderEntity(goose);
    window.display();
  }

  window.cleanUp();
  SDL_Quit();

  return 0;
}
