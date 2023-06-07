#ifndef TICIACTOEGAME_CROSS_H
#define TICIACTOEGAME_CROSS_H
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "figure.h"
class Cross: Figure
{
public:
  Cross(sf::Vector2f pos, size_t size, sf::Color color, float thickness);
  ~Cross() override = default;
  void draw(sf::RenderWindow *window);
private:
  std::vector< std::pair< sf::Vector2f, sf::Vector2f >> linesArray_;
  sf::Color color_;
  float thickness_;
};
#endif
