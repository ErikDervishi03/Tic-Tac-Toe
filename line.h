#ifndef TICIACTOEGAME_LINE_H
#define TICIACTOEGAME_LINE_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
class Line
{
  Line(sf::Vector2i start, sf::Vector2i end);
  void drawLine(sf::RenderWindow *window, sf::Vector2i start, sf::Vector2i end, sf::Color color, float thickness);
private:
  sf::Vector2i start_;
  sf::Vector2i end_;
};
#endif
