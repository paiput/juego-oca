#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Square.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Entity.hpp"
#include "GameMath.hpp"

extern SDL_Texture* getAreaTexture(SDL_Renderer* renderer, SDL_Rect rect, SDL_Texture* tex);

Board::Board()
{}

Board::Board(SDL_Renderer* p_renderer, int p_playersAmount)
  :renderer(p_renderer), ready(true)
{
  const int SQUARES = 64;
  const int MARGIN_X = 294;
  const int MARGIN_Y = 7;

  int xt = MARGIN_X, y = MARGIN_Y, a = 0;

  for (int i=0; i<SQUARES; i++)
  {
    squares[i] = Square(renderer, i+1, a, Vector2i(xt, y));
    xt += 90;
    if (xt >= 986) { xt = MARGIN_X; y += 90; }
    if (a == 1) a = -1;
    else a += 1;
  }

  SDL_Texture* playersTex = IMG_LoadTexture(renderer, "res/gfx/players.png");
  SDL_Rect imgPartRect;
  imgPartRect.x = 0;
  imgPartRect.y = 0;
  imgPartRect.w = 60;
  imgPartRect.h = 60;
  int x = 287;
  for (int i=0; i<p_playersAmount; i++)
  {
    if (i>0) imgPartRect.x += imgPartRect.w;
    SDL_Texture* singlePlayerTex = getAreaTexture(renderer, imgPartRect, playersTex);
    Entity playerEntity = Entity(renderer, singlePlayerTex, Vector2i(x, 14), Vector2i(60, 60));
    Player player = Player(i+1, playerEntity);
    players.push_back(player);
  }
}

void Board::draw()
{
  for (int i=0; i<64; i++)
  {
    squares[i].draw();
  }
}

void Board::changePlayerTurn()
{
  if (playerTurn+1 > players.size())
    playerTurn = 1;
  else
    playerTurn += 1;
}

bool Board::isReady()
{
  return ready;
}

int Board::getAmountOfPlayers()
{
  return players.size();
}

int Board::getPlayerTurn()
{
  return playerTurn - 1;
}

std::vector<Player>& Board::getPlayers()
{
  return players;
}
