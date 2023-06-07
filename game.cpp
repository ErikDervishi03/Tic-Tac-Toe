#include <valarray>
#include "game.h"
#include "cross.h"
#include "line.h"
namespace
{
  float angle(sf::Vector2i a, sf::Vector2i b)
  {
    int x1 = a.x;
    int y1 = a.y;
    int x2 = b.x;
    int y2 = b.y;
    double ang = acos((x1 * x2 + y1 * y2) /
                      (std::sqrt((double) x1 * x1 + y1 * y1) * std::sqrt((double) x2 * x2 + y2 * y2)));
    return static_cast< float >(ang);
  }
}
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
/*void Game::drawLine(sf::Vector2f line, sf::Vector2f pos)
{
  sf::RectangleShape rect(line);
  rect.setPosition(pos);
  rect.setFillColor(sf::Color::Black);
  window_->draw(rect);
}*/
void Game::drawField()
{
  sf::Vector2u windowSize = window_->getSize();
  float windowWidth = static_cast< float >(windowSize.x);
  float windowHeight = static_cast< float >(windowSize.y);
  float vertThickness = 5.f;
  float horizThickness = 5.f;

  /*
        v1   v2
         |    |
    h1---|----|---
         |    |
    h2---|----|---
         |    |
  */

//  //v1
//  drawLine(
//    sf::Vector2f(verticalLineThickness, windowHeight),
//    sf::Vector2f(windowWidth * (1.0f / 3.0f) - verticalLineThickness / 2.f, 0.f)
//  );
  float squareSize = windowWidth * (1.0f / 3.0f);
  Line *pLeftVertical = new Line({squareSize - vertThickness / 2.f, 0.f},
                                 {squareSize - vertThickness / 2.f, windowHeight});
  pLeftVertical->drawLine(window_, sf::Color::Black, vertThickness);
//  //v2
//  drawLine(
//    sf::Vector2f(verticalLineThickness, windowHeight),
//    sf::Vector2f(windowWidth * (2.0f / 3.0f) - verticalLineThickness / 2.f, 0.f)
//  );
//  //h1
//  drawLine(
//    sf::Vector2f(windowWidth, horizontalLineThickness),
//    sf::Vector2f(0.f, windowHeight / 3.f - horizontalLineThickness / 2.f)
//  );
//  //h2
//  drawLine(
//    sf::Vector2f(windowWidth, horizontalLineThickness),
//    sf::Vector2f(0.f, windowHeight * (2.0f / 3.0f) - horizontalLineThickness / 2.f)
//  );
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
