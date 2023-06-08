#include <valarray>
#include "mathfuncs.h"
namespace
{
  constexpr double pi()
  {
    return std::atan(1) * 4;
  }
}
sf::Vector2f math::addVector(sf::Vector2f pointA, sf::Vector2f pointB)
{
  return {pointA.x + pointB.x, pointA.y + pointB.y};
}
sf::Vector2f math::subtVector(sf::Vector2f pointA, sf::Vector2f pointB)
{
  return {pointA.x - pointB.x, pointA.y - pointB.y};
}
float math::angle(sf::Vector2f a, sf::Vector2f b)
{
  sf::Vector2f vector = subtVector(b, a);
  float angleRadians = std::atan2(vector.y, vector.x);
  float angleDegrees = angleRadians * 180.f / static_cast< float >(pi());
  return angleDegrees;
}
