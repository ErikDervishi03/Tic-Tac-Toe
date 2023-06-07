#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
class Game
{
public:
  Game();
  ~Game() = default;
  bool running() const;
  void drawField();
  void pollEvents();
  void updateMousePositions();
  void update();
  void render();
private:
  sf::RenderWindow *window_;
  sf::Event ev_;
  sf::VideoMode videoMode_;
  sf::Vector2i mousePosWindow_;
};
#endif
