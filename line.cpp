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
  double squareLengthX = std::pow((start_.x - end_.x), 2);
  double squareLengthY = std::pow((start_.y - end_.y), 2);
  float length = static_cast< float >(std::sqrt(squareLengthX + squareLengthY));
  //
  sf::RectangleShape drawableLine(sf::Vector2f(length, thickness));
  drawableLine.rotate(math::angle(start_, end_));
  drawableLine.setPosition(start_);
  drawableLine.setFillColor(color);
  window->draw(drawableLine);
}
