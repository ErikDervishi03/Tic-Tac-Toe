#include "figure.h"
bool Figure::isVisible() const
{
  return isVisible_;
}
void Figure::setVisibility(bool status)
{
  isVisible_ = status;
}
Figure::Figure():
  isVisible_(false),
  pos_(0, 0),
  size_(0)
{
}
sf::Vector2i Figure::getPos() const
{
  return pos_;
}
void Figure::setPos(sf::Vector2i rhs)
{
  pos_ = rhs;
}
size_t Figure::getSize() const
{
  return size_;
}
void Figure::setSize(size_t rhs)
{
  size_ = rhs;
}