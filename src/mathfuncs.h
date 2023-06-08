#ifndef TICIACTOEGAME_MATHFUNCS_H
#define TICIACTOEGAME_MATHFUNCS_H
#include <SFML/System/Vector2.hpp>
namespace math
{
  sf::Vector2f addVector(sf::Vector2f pointA, sf::Vector2f pointB);
  sf::Vector2f subtVector(sf::Vector2f pointA, sf::Vector2f pointB);
  float angle(sf::Vector2f a, sf::Vector2f b);
}
#endif
