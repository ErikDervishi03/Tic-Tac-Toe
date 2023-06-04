#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
/*
    class that acts as the game engine
*/
class Game
{
public:
  //Constructors / Destructors
  Game();
  ~Game() = default;

  //Accessors
  bool running() const;

  //functions
  void drawField();
  void drawLine(sf::Vector2f line, sf::Vector2f pos);
  void pollEvents();
  void updateMousePositions();
  void update();
  void render();
private:
  //variables
  //window
  sf::RenderWindow *window_; // _ usually used in private variables
  sf::Event ev_;
  sf::VideoMode videoMode_;
  sf::Vector2i mousePosWindow_; //mouse position
};
#endif
