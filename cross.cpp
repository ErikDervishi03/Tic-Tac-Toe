#include <SFML/Graphics/RectangleShape.hpp>
#include <valarray>
#include "cross.h"
#include "line.h"
#include "mathfuncs.h"
Cross::Cross(sf::Vector2f pos, size_t size, sf::Color color, float thickness):
  color_(color),
  thickness_(thickness)
{
  if (size <= 0)
  {
    throw std::invalid_argument("Invalid size for Cross. Size must be greater than zero.");
  }
  float halfSize = static_cast< float >(std::sqrt(2) * size / 2);
  sf::Vector2f topLeft = math::addVector({-halfSize, halfSize}, pos);
  sf::Vector2f topRight = math::addVector({halfSize, halfSize}, pos);
  sf::Vector2f bottomRight = math::addVector({halfSize, -halfSize}, pos);
  sf::Vector2f bottomLeft = math::addVector({-halfSize, -halfSize}, pos);
  linesArray_.emplace_back(topLeft, bottomRight);
  linesArray_.emplace_back(bottomLeft, topRight);
}
void Cross::draw(sf::RenderWindow *window)
{
  for (const auto &linePair: linesArray_)
  {
    const sf::Vector2f &start = linePair.first;
    const sf::Vector2f &end = linePair.second;
    Line line(start, end);
    line.drawLine(window, color_, thickness_);
  }
}
