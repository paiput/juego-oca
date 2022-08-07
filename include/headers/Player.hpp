#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameMath.hpp"
#include "Entity.hpp"

class Player
{
public:
  Player(int p_nPlayer, Entity p_avatar);
  void draw();
  void movePositions(int p_amount);
  int getPos();
  int getNPlayer();
  Entity& getAvatar();
private:
  int nPlayer;
  Entity avatar;
  int pos;
};
