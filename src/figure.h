#ifndef TICIACTOEGAME_FIGURE_H
#define TICIACTOEGAME_FIGURE_H
#include <SFML/System/Vector2.hpp>
#include <cstddef>
#include <vector>
class Figure
{
public:
  virtual ~Figure() = default;
  virtual bool isVisible() const = 0;
  virtual sf::Vector2f getPos() const = 0;
  virtual size_t getSize() const = 0;
  virtual void setVisibility(bool status) = 0;
  virtual void setPos(sf::Vector2f rhs) = 0;
  virtual void setSize(size_t rhs) = 0;
protected:
  bool isVisible_ = false;
  sf::Vector2f pos_;
  size_t size_ = 0;
};
#endif
