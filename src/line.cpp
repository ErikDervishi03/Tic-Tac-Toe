#include <valarray>
#include <SFML/Graphics/RectangleShape.hpp>
#include "line.h"
#include "mathfuncs.h"
Line::Line(sf::Vector2f start, sf::Vector2f end):
  start_(start),
  end_(end)
{
}
void Line::drawLine(sf::RenderWindow *window, sf::Color color, float thickness) const
{
  if (!window)
  {
    return;
  }
  float squareLengthX = (start_.x - end_.x) * (start_.x - end_.x);
  float squareLengthY = (start_.y - end_.y) * (start_.y - end_.y);
  float length = std::sqrt(squareLengthX + squareLengthY);
  sf::RectangleShape drawableLine(sf::Vector2f(length, thickness));
  drawableLine.rotate(math::angle(start_, end_));
  drawableLine.setPosition(start_.x, start_.y/* - thickness*/); //TODO
  drawableLine.setFillColor(color);
  window->draw(drawableLine);
}
