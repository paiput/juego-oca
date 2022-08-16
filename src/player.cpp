#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Player.hpp"
#include "GameMath.hpp"

Player::Player(int p_nPlayer, Entity p_avatar)
  :nPlayer(p_nPlayer), avatar(p_avatar), pos(0)
{}

void Player::draw()
{
  avatar.draw();
}

void Player::movePositions(int p_amount)
{
  if (p_amount < 0 && abs(p_amount) > pos)
    pos = 0;
  else if (p_amount >= 63)
    pos += p_amount;
  else 
    std::cout << "el jugador " << nPlayer << " llego al final" << std::endl;
  std::cout << "jugador " << nPlayer << " esta en posicion " << pos << std::endl; 
  avatar.updatePos(pos);
}

int Player::getPos()
{
  return pos;
}

int Player::getNPlayer()
{
  return nPlayer;
}

Entity& Player::getAvatar()
{
  return avatar;
}
