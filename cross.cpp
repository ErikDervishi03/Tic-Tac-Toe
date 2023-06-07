#include <SFML/Graphics/RectangleShape.hpp>
#include <valarray>
#include <iostream>
#include "cross.h"
#include "mathfuncs.h"
Cross::Cross(const std::vector< std::pair< sf::Vector2f, sf::Vector2f >> &linesArray):
  linesArray_(linesArray)
{
  //throw std::runtime_error("Bad size");
}
Cross::Cross(sf::Vector2f pos, size_t size)
{
  float halfSize = static_cast< float >(size / 2);
  pos = {100, 100};
  sf::Vector2f topLeft = math::addVector({-halfSize, halfSize}, pos);
  sf::Vector2f topRight = math::addVector({halfSize, halfSize}, pos);
  sf::Vector2f bottomRight = math::addVector({halfSize, -halfSize}, pos);
  sf::Vector2f bottomLeft = math::addVector({-halfSize, -halfSize}, pos);
  linesArray_.emplace_back(topLeft, bottomRight);
  linesArray_.emplace_back(bottomLeft, topRight);
}
void Cross::draw(sf::RenderWindow *window)
{
  for (auto &linePair: linesArray_)
  {
    sf::Vector2f start = linePair.first;
    sf::Vector2f end = linePair.second;
    std::cout << start.x << ' ' << start.y << '\n';
    std::cout << end.x << ' ' << end.y << "\n\n";
    float length = static_cast< float >(std::sqrt(2) * (start.x - end.x));
    sf::RectangleShape drawableLine(sf::Vector2f(length, 5.f));
    drawableLine.rotate(math::angle(start, end));
    drawableLine.setFillColor(sf::Color::Black);
    window->draw(drawableLine);
  }
}
