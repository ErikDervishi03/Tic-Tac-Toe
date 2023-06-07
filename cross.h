#ifndef TICIACTOEGAME_CROSS_H
#define TICIACTOEGAME_CROSS_H
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "figure.h"
class Cross: Figure
{
public:
  Cross(sf::Vector2f pos, size_t size, sf::Color color, float thickness);
  ~Cross() override = default;
  bool isVisible() const override;
  sf::Vector2f getPos() const override;
  size_t getSize() const override;
  void setVisibility(bool status) override;
  void setPos(sf::Vector2f rhs) override;
  void setSize(size_t rhs) override;
  void draw(sf::RenderWindow *window);
private:
  std::vector< std::pair< sf::Vector2f, sf::Vector2f >> linesArray_;
  sf::Color color_;
  float thickness_;
};
#endif
