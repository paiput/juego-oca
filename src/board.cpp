#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Board.hpp"
#include "Player.hpp"
#include "Entity.hpp"
#include "GameMath.hpp"

Board::Board(SDL_Renderer* p_renderer, int p_playersAmount)
  :renderer(p_renderer)
{
  SDL_Texture* playerTex = IMG_LoadTexture(renderer, "res/gfx/goose.png");
  for (int i=0; i<p_playersAmount; i++)
  {
    Entity playerEntity = Entity(renderer, playerTex, Vector2i(0, 0), Vector2i(100, 100));
    Player player = Player(i+1, playerEntity);
    players.push_back(player);
  }
}

void Board::draw()
{
  for (auto &player : players)
  {
    std::cout << "rendering player..." << std::endl;
    player.draw();
  }
}

int Board::getAmountOfPlayers()
{
  return players.size();
}

extern Board* createBoard(SDL_Renderer* p_renderer, int p_playersAmount)
{
  Board *board = new Board(p_renderer, p_playersAmount);
  return board;
}
