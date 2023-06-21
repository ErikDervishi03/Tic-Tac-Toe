#include <SFML/Graphics.hpp>
#ifndef FIELDDTO_H
#define FIELDDTO_H
struct FieldDTO
{
  const sf::Color lineCol;
  const sf::Color crossCol;
  const float winWidth;
  const float winHeight;
  const float vertThick;
  const float horizThick;
};
#endif
