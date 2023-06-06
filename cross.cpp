#include "cross.h"
namespace
{
  sf::Vector2i addVector(sf::Vector2i a, sf::Vector2i b)
  {
    return {a.x + b.x, a.y + b.y};
  }
}
Cross::Cross(const std::vector< std::pair< sf::Vector2i, sf::Vector2i >> &linesArray):
  linesArray_(linesArray)
{
  //throw std::runtime_error("Bad size");
}
Cross::Cross(sf::Vector2i pos, size_t size)
{
  int halfSize = static_cast< int >(size / 2);
  sf::Vector2i topLeft = addVector({-halfSize, halfSize}, pos);
  sf::Vector2i topRight = addVector({halfSize, halfSize}, pos);
  sf::Vector2i bottomRight = addVector({halfSize, -halfSize}, pos);
  sf::Vector2i bottomLeft = addVector({-halfSize, -halfSize}, pos);
  linesArray_.emplace_back(topLeft, bottomRight);
  linesArray_.emplace_back(bottomLeft, topRight);
}
void Cross::draw()
{
}
