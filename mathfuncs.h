#ifndef TICIACTOEGAME_MATHFUNCS_H
#define TICIACTOEGAME_MATHFUNCS_H
#include <SFML/System/Vector2.hpp>
namespace math
{
  sf::Vector2i addVector(sf::Vector2i a, sf::Vector2i b);
  float angle(sf::Vector2i a, sf::Vector2i b);
}
#endif
