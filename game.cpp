#include "game.h"
Game::Game():
  videoMode_(600, 600),
  ev_()
{
  window_ = new sf::RenderWindow(videoMode_, "Tic-Tac-Toe", sf::Style::Titlebar);
}
bool Game::running() const
{
  return window_->isOpen();
}
void Game::drawLine(sf::Vector2f line, sf::Vector2f pos)
{
  sf::RectangleShape verticalLine(line);
  verticalLine.setPosition(pos);
  verticalLine.setFillColor(sf::Color::Black);
  window_->draw(verticalLine);
}
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
  while (window_->pollEvent(ev_))
  {
    switch (ev_.type)
    {
      case sf::Event::Closed:
        window_->close();
        break;
      case sf::Event::KeyPressed:
        if (ev_.key.code == sf::Keyboard::Escape)
        {
          window_->close();
        }
        break;
      default:
        break;
    }
  }
}
void Game::updateMousePositions()
{
  mousePosWindow_ = sf::Mouse::getPosition(*window_);
  std::cout << mousePosWindow_.x << ' ' << mousePosWindow_.y << '\n';
}
void Game::update()
{
  pollEvents();
  updateMousePositions();
}
void Game::render()
{
  window_->clear(sf::Color::Yellow);
  drawField();
  window_->display();
}
