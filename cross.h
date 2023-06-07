#ifndef TICIACTOEGAME_CROSS_H
#define TICIACTOEGAME_CROSS_H
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "figure.h"
class Cross: Figure
{
public:
  Cross(sf::Vector2f pos, size_t size);
  ~Cross() override = default;
  void draw(sf::RenderWindow *window);
  std::vector< std::pair< sf::Vector2f, sf::Vector2f >> linesArray_;
private:
};
#endif
