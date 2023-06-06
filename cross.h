#ifndef TICIACTOEGAME_CROSS_H
#define TICIACTOEGAME_CROSS_H
#include <vector>
#include "figure.h"
class Cross: Figure
{
public:
  Cross();
  explicit Cross(const std::vector< std::pair< sf::Vector2i, sf::Vector2i>> &linesArray);
private:
  std::vector< std::pair< sf::Vector2i, sf::Vector2i >> linesArray_;
};
#endif
