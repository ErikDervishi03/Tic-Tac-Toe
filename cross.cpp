#include <stdexcept>
#include "cross.h"
Cross::Cross(const std::vector< std::pair< sf::Vector2i, sf::Vector2i >> &linesArray):
  linesArray_(linesArray)
{
  //throw std::runtime_error("Bad size");
}
Cross::Cross()
{
  sf::Vector2i topLeft{-1, 1};
  sf::Vector2i topRight{1, 1};
  sf::Vector2i bottomRight = {1, -1};
  sf::Vector2i bottomLeft = {-1, -1};
  linesArray_{{topLeft, bottomRight}, {bottomLeft, topRight}};
}
