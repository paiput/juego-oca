#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "Player.hpp"

class Board
{
public:
  Board(SDL_Renderer* p_renderer, int p_playersAmount);
  void draw();
  int getAmountOfPlayers();
private:
  SDL_Renderer* renderer;
  std::vector<Player> players;
};
