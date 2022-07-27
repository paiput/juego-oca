#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "GameMath.hpp"
#include "Button.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main(int argc, char* argv[]) 
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    std::cout << "SDL_Init has failed. SDL_ERROR: " << SDL_GetError() << std::endl;

  if (!(IMG_Init(IMG_INIT_PNG)))
    std::cout << "IMG_Init has failed. SDL_ERROR: " << SDL_GetError() << std::endl;

  RenderWindow window("GAME v1.0", WINDOW_WIDTH, WINDOW_HEIGHT);

  SDL_Texture* mainBackgroundTexture = window.loadTexture("res/gfx/main-menu-bg.png");
  SDL_Texture* gooseTexture = window.loadTexture("res/gfx/goose.png");
  SDL_Texture* playButton = window.loadTexture("res/gfx/play-button.png");
  SDL_Texture* exitButton = window.loadTexture("res/gfx/exit-button.png");
  
  Entity currentBackground(mainBackgroundTexture, Vector2i(0, 0), Vector2i(WINDOW_WIDTH, WINDOW_HEIGHT));

  std::vector<Button> mainMenuButtons = {
    Button(playButton, Vector2i(390, 275), Vector2i(500, 120)),
    Button(exitButton, Vector2i(390, 425), Vector2i(500, 120))
  };

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
        // std::cout << "x:" << event.motion.x << " y:" << event.motion.y << std::endl;
        break;
      }
    }

    window.clear();
    window.renderEntity(currentBackground);
    for (Button& b : mainMenuButtons)
    {
      window.render(b.tex, &b.srcrect, &b.dstrect);
    }
    window.display();
  }

  window.cleanUp();
  SDL_Quit();

  return 0;
}
