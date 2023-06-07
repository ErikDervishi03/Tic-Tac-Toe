#include <valarray>
#include <SFML/Graphics/RectangleShape.hpp>
#include "line.h"
#include "mathfuncs.h"
Line::Line(sf::Vector2f start, sf::Vector2f end):
  start_(start),
  end_(end)
{
}
void Line::drawLine(sf::RenderWindow *window, sf::Color color, float thickness)
{
  float length = static_cast< float >(std::sqrt(2) * (start_.x - end_.x));
  sf::RectangleShape drawableLine(sf::Vector2f(length, thickness));
  drawableLine.rotate(math::angle(start_, end_));
  drawableLine.setPosition(500, 500);
  drawableLine.setFillColor(color);
  window->draw(drawableLine);
}
