#include <valarray>
#include "mathfuncs.h"
sf::Vector2f math::addVector(sf::Vector2f a, sf::Vector2f b)
{
  return {a.x + b.x, a.y + b.y};
}
float math::angle(sf::Vector2f a, sf::Vector2f b)
{
  float x1 = a.x;
  float y1 = a.y;
  float x2 = b.x;
  float y2 = b.y;
  double ang = acos((x1 * x2 + y1 * y2) /
                    (std::sqrt((double) x1 * x1 + y1 * y1) * std::sqrt((double) x2 * x2 + y2 * y2)));
  return static_cast< float >(ang);
}
