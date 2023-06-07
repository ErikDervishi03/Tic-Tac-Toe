#include <valarray>
#include "game.h"
#include "cross.h"
#include "line.h"
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
void Game::drawField()
{
  sf::Vector2u windowSize = window_->getSize();
  float windowWidth = static_cast< float >(windowSize.x);
  float windowHeight = static_cast< float >(windowSize.y);
  float vertThickness = 5.f;
  float horizThickness = 5.f;
  float squareSize = windowWidth * (1.0f / 3.0f);
  Line *pLeftVertical = new Line({squareSize - vertThickness / 2.f, 0.f},
                                 {squareSize - vertThickness / 2.f, windowHeight});
  Line *pRightVertical = new Line({2 * squareSize - vertThickness / 2.f, 0.f},
                                  {2 * squareSize - vertThickness / 2.f, windowHeight});
  Line *pUpperVertical = new Line({0.f, squareSize - vertThickness / 2.f},
                                  {windowWidth, squareSize - vertThickness / 2.f});
  Line *pLowerVertical = new Line({0.f, 2 * squareSize - vertThickness / 2.f},
                                  {windowWidth, 2 * squareSize - vertThickness / 2.f});
  pLeftVertical->drawLine(window_, sf::Color::Black, vertThickness);
  pRightVertical->drawLine(window_, sf::Color::Black, vertThickness);
  pUpperVertical->drawLine(window_, sf::Color::Black, horizThickness);
  pLowerVertical->drawLine(window_, sf::Color::Black, horizThickness);
  //
  //
  //
  //
  //
  Cross *pcross = new Cross({100, 100}, 70);
  //pcross->draw(window_);
  for (auto &linePair: pcross->linesArray_)
  {
    sf::Vector2f start = linePair.first;
    sf::Vector2f end = linePair.second;
    std::cout << start.x << ' ' << start.y << '\n';
    std::cout << end.x << ' ' << end.y << "\n\n";
    //
    Line *pline = new Line(start, end);
    pline->drawLine(window_, sf::Color::Black, 5.f);
  }
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
  //std::cout << mousePosWindow_.x << ' ' << mousePosWindow_.y << '\n';
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
