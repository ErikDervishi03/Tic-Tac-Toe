#include "game.h"
//construtor / destructors
Game::Game():
  videoMode_(400, 400),
  ev_()
{
  this->window_ = new sf::RenderWindow(videoMode_, "Tic-Tac-Toe", sf::Style::Titlebar);
  this->window_->setFramerateLimit(60); // Optionally, set a framerate limit for the window
}
//accessors
bool Game::running() const
{
  return this->window_->isOpen();
}
void Game::drawLine(sf::Vector2f line, sf::Vector2f pos)
{
  sf::RectangleShape verticalLine(line);
  verticalLine.setPosition(pos);
  verticalLine.setFillColor(sf::Color::Black);
  window_->draw(verticalLine);
}
//functions
void Game::drawField()
{
  sf::Vector2u windowSize = window_->getSize();
  float windowWidth = static_cast< float >(windowSize.x);
  float windowHeight = static_cast< float >(windowSize.y);
  float verticalLineThickness = 5.f;
  float horizontalLineThickness = 5.f;

  /*
        v1   v2
         |    |
    h1---|----|---
         |    |
    h2---|----|---
         |    |
  */

  //v1
  drawLine(
    sf::Vector2f(verticalLineThickness, windowHeight),
    sf::Vector2f(windowWidth * (1.0f / 3.0f) - verticalLineThickness / 2.f, 0.f)
  );
  //v2
  drawLine(
    sf::Vector2f(verticalLineThickness, windowHeight),
    sf::Vector2f(windowWidth * (2.0f / 3.0f) - verticalLineThickness / 2.f, 0.f)
  );
  //h1
  drawLine(
    sf::Vector2f(windowWidth, horizontalLineThickness),
    sf::Vector2f(0.f, windowHeight / 3.f - horizontalLineThickness / 2.f)
  );
  //h2
  drawLine(
    sf::Vector2f(windowWidth, horizontalLineThickness),
    sf::Vector2f(0.f, windowHeight * (2.0f / 3.0f) - horizontalLineThickness / 2.f)
  );
}
void Game::pollEvents()
{
  // Continuously check for events
  while (this->window_->pollEvent(this->ev_))
  {
    // Handle different types of events
    switch (this->ev_.type)
    {
      case sf::Event::Closed: // If the user clicks the close button of the window
        this->window_->close(); // Close the game window
        break;
      case sf::Event::KeyPressed: // If a key is pressed
        if (this->ev_.key.code == sf::Keyboard::Escape) // Check if the pressed key is the Escape key
        {
          this->window_->close(); // Close the game window
        }
        break;
      default:
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

  this->mousePosWindow_ = sf::Mouse::getPosition(*this->window_);
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
  this->window_->clear(sf::Color::Yellow);
  this->drawField();

  //Draw game objects
  this->window_->display();
}
