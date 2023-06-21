#include <SFML/Graphics.hpp>
#ifndef FIELDDTO_H
#define FIELDDTO_H
struct FieldDTO
{
  const sf::Color lineColor;
  const sf::Color crossColor;
  const float windowWidth;
  const float windowHeight;
  const float vertThickness;
  const float horizThickness;
};
#endif
