#include <SFML/Graphics/RectangleShape.hpp>
#include <valarray>
#include "cross.h"
namespace
{
  sf::Vector2i addVector(sf::Vector2i a, sf::Vector2i b)
  {
    return {a.x + b.x, a.y + b.y};
  }
  sf::Vector2i subtractVector(sf::Vector2i a, sf::Vector2i b)
  {
    return {a.x - b.x, a.y - b.y};
  }
  float angle(sf::Vector2i a, sf::Vector2i b)
  {
    int x1 = a.x;
    int y1 = a.y;
    int x2 = b.x;
    int y2 = b.y;
    double ang = acos((x1 * x2 + y1 * y2) /
                      (std::sqrt((double) x1 * x1 + y1 * y1) * std::sqrt((double) x2 * x2 + y2 * y2)));
    return static_cast< float >(ang);
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
void Cross::draw(sf::RenderWindow *window)
{
  for (auto &line: linesArray_)
  {
    sf::Vector2i start = line.first;
    sf::Vector2i end = line.second;
    sf::RectangleShape drawableLine(static_cast< sf::Vector2f >(subtractVector(end, start)));
    drawableLine.rotate(angle(start, end));
    window->draw(drawableLine);
  }
}
