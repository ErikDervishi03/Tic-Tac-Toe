#ifndef TICIACTOEGAME_FIGURE_H
#define TICIACTOEGAME_FIGURE_H
#include <SFML/System/Vector2.hpp>
#include <cstddef>
#include <vector>
class Figure
{
public:
  Figure();
  virtual ~Figure() = 0; //TODO
  bool isVisible() const;
  void setVisibility(bool status);
  sf::Vector2i getPos() const;
  void setPos(sf::Vector2i rhs);
  size_t getSize() const;
  void setSize(size_t rhs);
private:
  std::vector< std::pair< sf::Vector2i, sf::Vector2i >> linesArray_;
  bool isVisible_;
  sf::Vector2i pos_;
  size_t size_;
};
#endif
