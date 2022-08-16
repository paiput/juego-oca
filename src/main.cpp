#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <time.h>

#include "Entity.hpp"
#include "GameMath.hpp"
#include "Button.hpp"
#include "Mouse.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Dice.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

extern SDL_Texture* getAreaTexture(SDL_Renderer* renderer, SDL_Rect rect, SDL_Texture* tex)
{
  SDL_Texture* result = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
  SDL_SetRenderTarget(renderer, result);
  SDL_RenderCopy(renderer, tex, &rect, NULL);
  SDL_SetRenderTarget(renderer, NULL);  
  return result;
}

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

  srand(time(NULL));

  Mouse mouse(renderer);

  SDL_Texture* currentBackgroundTex = IMG_LoadTexture(renderer, "res/gfx/main-menu-bg.png");
  SDL_Texture* playButtonTex = IMG_LoadTexture(renderer, "res/gfx/play-button.png");
  SDL_Texture* exitButtonTex = IMG_LoadTexture(renderer, "res/gfx/exit-button.png");

  bool showMainMenu = true;
  std::vector<Button> mainMenuButtons = {
    Button(renderer, "play", Vector2i(390, 275), Vector2i(500, 120)),
    Button(renderer, "exit", Vector2i(390, 425), Vector2i(500, 120))
  };
  mainMenuButtons[0].srcrect.y = 0;
  mainMenuButtons[1].srcrect.y = 120;
  
  bool showPlayerSelectionMenu = false;
  std::vector<Button> playersSelectionMenuButtons = {
    Button(renderer, "2-players", Vector2i(390, 150), Vector2i(500, 120)),
    Button(renderer, "3-players", Vector2i(390, 300), Vector2i(500, 120)),
    Button(renderer, "4-players", Vector2i(390, 450), Vector2i(500, 120))
  };
  playersSelectionMenuButtons[0].srcrect.y = 240;
  playersSelectionMenuButtons[1].srcrect.y = 360;
  playersSelectionMenuButtons[2].srcrect.y = 480;

  Dice dice(renderer, Vector2i(WINDOW_WIDTH - 135, 10), Vector2i(125, 125));
  Board board;
  std::vector<Player> players;
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
        if (showMainMenu)
        {
          for (Button& b : mainMenuButtons)
          {
            b.update(mouse, event);
          }
        }
        if (showPlayerSelectionMenu)
        {
          for (Button& b : playersSelectionMenuButtons)
          {
            b.update(mouse, event);
          }
        }
        break;
      case SDL_MOUSEBUTTONUP:
        if (showMainMenu)
        {
          for (Button& b : mainMenuButtons)
          {
            b.update(mouse, event);
            if (strcmp(b.getName(), "exit") == 0 && b.isClicked)
              gameRunning = false;
            else if (strcmp(b.getName(), "play") == 0 && b.isClicked)
            {
              currentBackgroundTex = IMG_LoadTexture(renderer, "res/gfx/players-selection-menu-bg.png");
              
              showMainMenu = false;
              showPlayerSelectionMenu = true;
            }
          }
        }
        else if (showPlayerSelectionMenu)
        {
          for (Button& b : playersSelectionMenuButtons)
          {
            b.update(mouse, event);
            if (strcmp(b.getName(), "2-players") == 0 && b.isClicked)
              board = Board(renderer, 2);
            else if (strcmp(b.getName(), "3-players") == 0 && b.isClicked)
              board = Board(renderer, 3);
            else if (strcmp(b.getName(), "4-players") == 0 && b.isClicked)
              board = Board(renderer, 4);
          }
          players = board.getPlayers();
          currentBackgroundTex = IMG_LoadTexture(renderer, "res/gfx/board-3.png");
          showPlayerSelectionMenu = false;
        }
        else if (board.isReady())
        {
          dice.update(mouse, event);
          if (dice.isClicked)
          {
            int diceResult = dice.roll();
            players.at(board.getPlayerTurn()).movePositions(diceResult);
            board.changePlayerTurn();
          }
        }
        break;
      }
    }

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, currentBackgroundTex, NULL, NULL);

    if (showMainMenu)
    {
      for (Button& b : mainMenuButtons)
      {
        b.draw();
      }
    } 
    if (showPlayerSelectionMenu)
    {
      for (Button& b : playersSelectionMenuButtons)
      {
        b.draw();
      }
    }
    if (board.isReady())
    {
      board.draw();
      for (Player& p : players)
      {
        p.draw();
      }
      dice.draw();
    }
    mouse.draw();

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
