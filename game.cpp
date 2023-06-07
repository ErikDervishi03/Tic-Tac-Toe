#include <valarray>
#include "game.h"
#include "cross.h"
#include "line.h"
namespace
{
  sf::Vector2f
  getFigurePos(float squareSize, bool inLeftPart, bool inMidXPart, bool inRightPart, bool inUpPart, bool inMidYPart,
               bool inLowerPart)
  {
    int case_ = 10 * inLeftPart + inUpPart;
    float crossPosX;
    float crossPosY;
    switch (case_)
    {
      case 11:
        return {squareSize / 2, squareSize / 2};
      case 10:
        return {squareSize / 2, inMidYPart ? squareSize * 3 / 2 : squareSize * 5 / 2};
      case 1:
        return {inMidXPart ? squareSize * 3 / 2 : squareSize * 5 / 2, squareSize / 2};
      case 0:
        crossPosX = inMidXPart ? squareSize * 3 / 2 : squareSize * 5 / 2;
        crossPosY = inMidYPart ? squareSize * 3 / 2 : squareSize * 5 / 2;
        return {crossPosX, crossPosY};
      default:
        break;
    }
    return {-1, -1};
  }
}
Game::Game(sf::VideoMode videoMode, const std::string &title):
  videoMode_(videoMode),
  ev_()
{
  window_ = new sf::RenderWindow(videoMode_, title, sf::Style::Titlebar);
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
  //
  //
  //
  //
  //
  sf::Vector2f mousePosWindow = getMousePosition();
  bool inLeftPart = (mousePosWindow.x > 0) && (mousePosWindow.x < squareSize);
  bool inMidXPart = (mousePosWindow.x > squareSize) && (mousePosWindow.x < 2 * squareSize);
  bool inRightPart = (mousePosWindow.x > 2 * squareSize) && (mousePosWindow.x < windowWidth);
  bool inUpPart = (mousePosWindow.y > 0) && (mousePosWindow.y < squareSize);
  bool inMidYPart = (mousePosWindow.y > squareSize) && (mousePosWindow.y < 2 * squareSize);
  bool inLowerPart = (mousePosWindow.y > 2 * squareSize) && (mousePosWindow.y < windowHeight);
  sf::Vector2f crossPos{
    getFigurePos(squareSize, inLeftPart, inMidXPart, inRightPart, inUpPart, inMidYPart, inLowerPart)
  };
  if (inLeftPart && inUpPart)
  {
    crossPos = {squareSize / 2, squareSize / 2};
  }
  else if (inLeftPart && inMidYPart)
  {
    crossPos = {squareSize / 2, squareSize * 3 / 2};
  }
  else if (inLeftPart && inLowerPart)
  {
    crossPos = {squareSize / 2, squareSize * 5 / 2};
  }
  else if (inMidXPart && inUpPart)
  {
    crossPos = {squareSize * 3 / 2, squareSize / 2};
  }
  else if (inMidXPart && inMidYPart)
  {
    crossPos = {squareSize * 3 / 2, squareSize * 3 / 2};
  }
  else if (inMidXPart && inLowerPart)
  {
    crossPos = {squareSize * 3 / 2, squareSize * 5 / 2};
  }
  else if (inRightPart && inUpPart)
  {
    crossPos = {squareSize * 5 / 2, squareSize / 2};
  }
  else if (inRightPart && inMidYPart)
  {
    crossPos = {squareSize * 5 / 2, squareSize * 3 / 2};
  }
  else if (inRightPart && inLowerPart)
  {
    crossPos = {squareSize * 5 / 2, squareSize * 5 / 2};
  }
  else
  {
    crossPos = {-squareSize, -squareSize};
  }
  Cross *pcross = new Cross(crossPos, squareSize / 2.f, sf::Color::Black, 10.f);
  pcross->draw(window_);
/*
  if (crossPos.x != -1 && crossPos.y != -1)
  {
    Cross *pcross = new Cross(crossPos, squareSize / 2.f, sf::Color::Black, 10.f);
    pcross->draw(window_);
  }*/
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
sf::Vector2f Game::getMousePosition()
{
  auto pos = sf::Mouse::getPosition(*window_);
  return {static_cast< float >(pos.x), static_cast< float >(pos.y)};
}
void Game::update()
{
  pollEvents();
}
void Game::render()
{
  window_->clear(sf::Color::Yellow);
  drawField();
  window_->display();
}
