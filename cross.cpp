#include <SFML/Graphics/RectangleShape.hpp>
#include <valarray>
#include "cross.h"
#include "line.h"
#include "mathfuncs.h"
Cross::Cross(sf::Vector2f pos, size_t size)
{
  float halfSize = static_cast< float >(std::sqrt(2) * size / 2);
  pos = {100, 100};
  sf::Vector2f topLeft = math::addVector({-halfSize, halfSize}, pos);
  sf::Vector2f topRight = math::addVector({halfSize, halfSize}, pos);
  sf::Vector2f bottomRight = math::addVector({halfSize, -halfSize}, pos);
  sf::Vector2f bottomLeft = math::addVector({-halfSize, -halfSize}, pos);
  linesArray_.emplace_back(topLeft, bottomRight);
  linesArray_.emplace_back(bottomLeft, topRight);
}
void Cross::draw(sf::RenderWindow *window)
{
  for (auto &linePair: linesArray_)
  {
    sf::Vector2f start = linePair.first;
    sf::Vector2f end = linePair.second;
    Line *pline = new Line(start, end);
    pline->drawLine(window, sf::Color::Black, 5.f);
  }
}
