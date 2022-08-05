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
  void changePlayerTurn();
  int getAmountOfPlayers();
  int getPlayerTurn();
  std::vector<Player>& getPlayers();
private:
  int playerTurn = 1;
  SDL_Renderer* renderer;
  std::vector<Player> players;
};
