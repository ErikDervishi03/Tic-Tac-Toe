#ifndef TICIACTOEGAME_FIGURE_H
#define TICIACTOEGAME_FIGURE_H
#include <SFML/System/Vector2.hpp>
#include <cstddef>
#include <vector>
class Figure
{
public:
  virtual ~Figure() = default;
  bool isVisible() const;
  void setVisibility(bool status);
  sf::Vector2f getPos() const;
  void setPos(sf::Vector2f rhs);
  size_t getSize() const;
  void setSize(size_t rhs);
private:
  std::vector< std::pair< sf::Vector2f, sf::Vector2f >> linesArray_;
  bool isVisible_;
  sf::Vector2f pos_;
  size_t size_;
};
#endif
