#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "GameMath.hpp"

Vector2i::Vector2i(int p_x, int p_y)
  :x(p_x), y(p_y)
{}

void Vector2i::print()
{
  std::cout << "x:" << x << " y:" << y << std::endl; 
}
