#ifndef TICIACTOEGAME_CROSS_H
#define TICIACTOEGAME_CROSS_H
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "figure.h"
class Cross: Figure
{
public:
  Cross(sf::Vector2i pos, size_t size);
  explicit Cross(const std::vector< std::pair< sf::Vector2i, sf::Vector2i>> &linesArray);
  ~Cross() override = default;
  void draw(sf::RenderWindow *window);
  std::vector< std::pair< sf::Vector2i, sf::Vector2i >> linesArray_;
private:
};
#endif
