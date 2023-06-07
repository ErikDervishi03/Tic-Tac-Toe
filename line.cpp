#include <valarray>
#include <SFML/Graphics/RectangleShape.hpp>
#include "line.h"
Line::Line(sf::Vector2i start, sf::Vector2i end):
  start_(start),
  end_(end)
{
}
void Line::drawLine(sf::RenderWindow *window, sf::Vector2i start, sf::Vector2i end, sf::Color color, float thickness)
{
  float length = static_cast< float >(std::sqrt(2) * (start.x - end.x));
  sf::RectangleShape drawableLine(sf::Vector2f(length, 5.f));
  drawableLine.rotate(angle(start, end));
  drawableLine.setPosition(500, 500);
  drawableLine.setFillColor(sf::Color::Black);
  window_->draw(drawableLine);
}
