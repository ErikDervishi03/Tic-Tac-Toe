#include "game.h"
//private
void Game::initializeVariables()
{
  this->window = nullptr;
}
void Game::initWindow()
{
  this->videoMode.height = 400;
  this->videoMode.width = 400;
  this->window = new sf::RenderWindow(this->videoMode, "Tic-Tac-Toe", sf::Style::Titlebar);
  this->window->setFramerateLimit(60); // Optionally, set a framerate limit for the window
}
//construtor / destructors
Game::Game()
{
  this->initializeVariables();
  this->initWindow();
}
Game::~Game()
{
  delete this->window;
}

//accessors
const bool Game::running() const
{
  return this->window->isOpen();
}

//functions
void Game::DrawField()
{
  sf::Vector2u windowSize = window->getSize();
  float windowWidth = static_cast< float >(windowSize.x);
  float windowHeight = static_cast< float >(windowSize.y);
  float verticalLineThickness = 5.f;
  float horizontalLineThickness = 5.f;

  //v1
  sf::RectangleShape verticalLine1(sf::Vector2f(verticalLineThickness, windowHeight));
  verticalLine1.setPosition(sf::Vector2f(windowWidth * (1.0f / 3.0f) - verticalLineThickness / 2.f, 0.f));
  verticalLine1.setFillColor(sf::Color::Black);
  window->draw(verticalLine1);
  //v2
  sf::RectangleShape verticalLine2(sf::Vector2f(verticalLineThickness, windowHeight));
  verticalLine2.setPosition(sf::Vector2f(windowWidth * (2.0f / 3.0f) - verticalLineThickness / 2.f, 0.f));
  verticalLine2.setFillColor(sf::Color::Black);
  window->draw(verticalLine2);
  //h1
  sf::RectangleShape horizontalLine1(sf::Vector2f(windowWidth, horizontalLineThickness));
  horizontalLine1.setPosition(sf::Vector2f(0.f, windowHeight / 3.f - horizontalLineThickness / 2.f));
  horizontalLine1.setFillColor(sf::Color::Black);
  window->draw(horizontalLine1);
  //h2
  sf::RectangleShape horizontalLine2(sf::Vector2f(windowWidth, horizontalLineThickness));
  horizontalLine2.setPosition(sf::Vector2f(0.f, windowHeight * (2.0f / 3.0f) - horizontalLineThickness / 2.f));
  horizontalLine2.setFillColor(sf::Color::Black);
  window->draw(horizontalLine2);

  /*
      v1   v2
       |    |
  h1---|----|---
       |    |
  h2---|----|---
       |    |
  */
}
void Game::pollEvents()
{
  // Continuously check for events
  while (this->window->pollEvent(this->ev))
  {
    // Handle different types of events
    switch (this->ev.type)
    {
      // If the user clicks the close button of the window
      case sf::Event::Closed:
        // Close the game window
        this->window->close();
        break;

        // If a key is pressed
      case sf::Event::KeyPressed:
        // Check if the pressed key is the Escape key
        if (this->ev.key.code == sf::Keyboard::Escape)
        {
          // Close the game window
          this->window->close();
        }
        break;
    }
  }
}
void Game::updateMousePositions()
{
  /*
  @return void

  updates the mouse position:
      * Mouse position relative to window (Vector2i)
  */

  this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}
void Game::update()
{
  this->pollEvents();
  this->updateMousePositions();
}
void Game::render()
{
  /*
      @return void

      -clear old frame
      -render objects
      -display frame in window

      Renders the game objects
  */
  //This line of code clears the previous frame by filling the window with a yellow color
  this->window->clear(sf::Color::Yellow);
  this->DrawField();

  //Draw game objects
  this->window->display();
}
