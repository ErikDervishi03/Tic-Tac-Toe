#include <SFML/Graphics/RectangleShape.hpp>
#include <valarray>
#include <iostream>
#include "cross.h"
namespace
{
  sf::Vector2i addVector(sf::Vector2i a, sf::Vector2i b)
  {
    return {a.x + b.x, a.y + b.y};
  }
  float angle(sf::Vector2i a, sf::Vector2i b)
  {
    int x1 = a.x;
    int y1 = a.y;
    int x2 = b.x;
    int y2 = b.y;
    double ang = acos((x1 * x2 + y1 * y2) /
                      (std::sqrt((double) x1 * x1 + y1 * y1) * std::sqrt((double) x2 * x2 + y2 * y2)));
    return static_cast< float >(ang);
  }
}
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
