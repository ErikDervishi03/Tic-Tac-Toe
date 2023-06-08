#ifndef TICIACTOEGAME_LINE_H
#define TICIACTOEGAME_LINE_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
class Line
{
public:
  Line(sf::Vector2f start, sf::Vector2f end);
  ~Line() = default;
  void drawLine(sf::RenderWindow *window, sf::Color color, float thickness) const;
private:
  sf::Vector2f start_;
  sf::Vector2f end_;
};
#endif
