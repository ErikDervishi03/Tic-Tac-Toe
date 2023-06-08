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
  Game(const std::string &title);
  ~Game() = default;
  bool running() const;
  void drawField();
  void pollEvents();
  void update(sf::Clock clock);
  void render();
  sf::Vector2f getMousePosition();
private:
  sf::RenderWindow *window_;
  sf::Event ev_;
  sf::VideoMode videoMode_;
  double elapsedTime_;
};
#endif
