#include <valarray>
#include "mathfuncs.h"
sf::Vector2i math::addVector(sf::Vector2i a, sf::Vector2i b)
{
  return {a.x + b.x, a.y + b.y};
}
float math::angle(sf::Vector2i a, sf::Vector2i b)
{
  int x1 = a.x;
  int y1 = a.y;
  int x2 = b.x;
  int y2 = b.y;
  double ang = acos((x1 * x2 + y1 * y2) /
                    (std::sqrt((double) x1 * x1 + y1 * y1) * std::sqrt((double) x2 * x2 + y2 * y2)));
  return static_cast< float >(ang);
}
