#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Board.hpp"
#include "Player.hpp"
#include "Entity.hpp"
#include "GameMath.hpp"

extern SDL_Texture* getAreaTexture(SDL_Renderer* renderer, SDL_Rect rect, SDL_Texture* tex);

Board::Board(SDL_Renderer* p_renderer, int p_playersAmount)
  :renderer(p_renderer)
{
  SDL_Texture* playersTex = IMG_LoadTexture(renderer, "res/gfx/players.png");
  SDL_Rect imgPartRect;
  imgPartRect.x = 0;
  imgPartRect.y = 0;
  imgPartRect.w = 60;
  imgPartRect.h = 60;
  int x = 0;
  for (int i=0; i<p_playersAmount; i++)
  {
    if (i>0) imgPartRect.x += imgPartRect.w;
    SDL_Texture* singlePlayerTex = getAreaTexture(renderer, imgPartRect, playersTex);
    Entity playerEntity = Entity(renderer, singlePlayerTex, Vector2i(x, 0), Vector2i(60, 60));
    Player player = Player(i+1, playerEntity);
    players.push_back(player);
    x += 60;
  }
}

void Board::draw()
{
  for (auto &player : players)
  {
    player.draw();
  }
}

void Board::changePlayerTurn()
{
  if (playerTurn+1 > players.size())
    playerTurn = 1;
  else
    playerTurn += 1;
}

int Board::getAmountOfPlayers()
{
  return players.size();
}

int Board::getPlayerTurn()
{
  return playerTurn - 1;
}

extern Board* createBoard(SDL_Renderer* p_renderer, int p_playersAmount)
{
  Board *board = new Board(p_renderer, p_playersAmount);
  return board;
}

std::vector<Player>& Board::getPlayers()
{
  return players;
}
