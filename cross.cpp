#include <SFML/Graphics/RectangleShape.hpp>
#include <valarray>
#include <iostream>
#include "cross.h"
Cross::Cross(const std::vector< std::pair< sf::Vector2i, sf::Vector2i >> &linesArray):
  linesArray_(linesArray)
{
  //throw std::runtime_error("Bad size");
}
Cross::Cross(sf::Vector2i pos, size_t size)
{
  int halfSize = static_cast< int >(size / 2);
  pos = {100, 100};
  sf::Vector2i topLeft = addVector({-halfSize, halfSize}, pos);
  sf::Vector2i topRight = addVector({halfSize, halfSize}, pos);
  sf::Vector2i bottomRight = addVector({halfSize, -halfSize}, pos);
  sf::Vector2i bottomLeft = addVector({-halfSize, -halfSize}, pos);
  linesArray_.emplace_back(topLeft, bottomRight);
  linesArray_.emplace_back(bottomLeft, topRight);
}
void Cross::draw(sf::RenderWindow *window)
{
  for (auto &linePair: linesArray_)
  {
    sf::Vector2i start = linePair.first;
    sf::Vector2i end = linePair.second;
    std::cout << start.x << ' ' << start.y << '\n';
    std::cout << end.x << ' ' << end.y << "\n\n";
    float length = static_cast< float >(std::sqrt(2) * (start.x - end.x));
    sf::RectangleShape drawableLine(sf::Vector2f(length, 5.f));
    drawableLine.rotate(angle(start, end));
    drawableLine.setFillColor(sf::Color::Black);
    window->draw(drawableLine);
  }
}
