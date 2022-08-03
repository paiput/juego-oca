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
    Entity playerEntity = Entity(playerTex, Vector2i(0, 0), Vector2i(100, 100));
    Player player = Player(i+1, playerEntity);
  }
}

void Board::draw()
{
  // SDL_RenderCopy(renderer, tex, NULL, NULL);
}

extern Board* createBoard(SDL_Renderer* p_renderer, int p_playersAmount)
{
  std::cout << p_playersAmount << " players" << std::endl;
  Board *board = new Board(p_renderer, p_playersAmount);
  return board;
}
