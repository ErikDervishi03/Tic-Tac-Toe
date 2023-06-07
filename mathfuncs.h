#ifndef TICIACTOEGAME_MATHFUNCS_H
#define TICIACTOEGAME_MATHFUNCS_H
#include <SFML/System/Vector2.hpp>
namespace math
{
  sf::Vector2f addVector(sf::Vector2f a, sf::Vector2f b);
  float angle(sf::Vector2f a, sf::Vector2f b);
}
#endif
