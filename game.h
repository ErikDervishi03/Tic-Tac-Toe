#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
/*
    class that acts as the game engine
*/
class Game
{
private:
  //variables
  //window
  sf::RenderWindow *window;
  sf::Event ev;
  sf::VideoMode videoMode;
  //mouse position
  sf::Vector2i mousePosWindow;
  //private funtions
  void initWindow();
public:
  //Constructors / Destructors
  Game();
  virtual ~Game();
  //Accessors
  const bool running() const;

  //functions

  void DrawField();
  void pollEvents();
  void updateMousePositions();
  void update();
  void render();
};
