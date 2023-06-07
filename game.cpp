#include <valarray>
#include "game.h"
#include "cross.h"
#include "line.h"
namespace
{
  sf::Vector2f getFigurePos(float squareSize, bool left, bool midX, bool right, bool up, bool midY, bool lower)
  {
    if (left)
    {
      if (up)
      {
        return {squareSize / 2.f, squareSize / 2.f};
      }
      if (midY)
      {
        return {squareSize / 2.f, squareSize * 3.f / 2.f};
      }
      if (lower)
      {
        return {squareSize / 2.f, squareSize * 5.f / 2.f};
      }
    }
    else if (midX)
    {
      if (up)
      {
        return {squareSize * 3.f / 2.f, squareSize / 2.f};
      }
      if (midY)
      {
        return {squareSize * 3.f / 2.f, squareSize * 3.f / 2.f};
      }
      if (lower)
      {
        return {squareSize * 3.f / 2.f, squareSize * 5.f / 2.f};
      }
    }
    else if (right)
    {
      if (up)
      {
        return {squareSize * 5.f / 2.f, squareSize / 2.f};
      }
      if (midY)
      {
        return {squareSize * 5.f / 2.f, squareSize * 3.f / 2.f};
      }
      if (lower)
      {
        return {squareSize * 5.f / 2.f, squareSize * 5.f / 2.f};
      }
    }
    return {-1.f, -1.f};
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
  const sf::Color lineColor = sf::Color::Black;
  const sf::Color crossColor = sf::Color::Red;
  const float windowWidth = static_cast< float >(windowSize.x);
  const float windowHeight = static_cast< float >(windowSize.y);
  const float vertThickness = 5.f;
  const float horizThickness = 5.f;
  const float squareSize = windowWidth * (1.0f / 3.0f);
  std::vector< Line > verticalLines;
  std::vector< Line > horizontalLines;
  for (float x = squareSize; x < windowWidth; x += squareSize)
  {
    sf::Vector2f startPointX{x - vertThickness / 2.f, 0.f};
    sf::Vector2f endPointX{x - vertThickness / 2.f, windowHeight};
    sf::Vector2f startPointY{0.f, x - horizThickness / 2.f};
    sf::Vector2f endPointY{windowWidth, x - horizThickness / 2.f};
    verticalLines.emplace_back(startPointX, endPointX);
    horizontalLines.emplace_back(startPointY, endPointY);
  }
  for (const auto &line: verticalLines)
  {
    line.drawLine(window_, lineColor, vertThickness);
  }
  for (const auto &line: horizontalLines)
  {
    line.drawLine(window_, lineColor, horizThickness);
  }
  sf::Vector2f mousePosWindow = getMousePosition();
  bool inLeftPart = (mousePosWindow.x > 0) && (mousePosWindow.x < squareSize);
  bool inMidXPart = (mousePosWindow.x > squareSize) && (mousePosWindow.x < 2 * squareSize);
  bool inRightPart = (mousePosWindow.x > 2 * squareSize) && (mousePosWindow.x < windowWidth);
  bool inUpPart = (mousePosWindow.y > 0) && (mousePosWindow.y < squareSize);
  bool inMidYPart = (mousePosWindow.y > squareSize) && (mousePosWindow.y < 2 * squareSize);
  bool inLowerPart = (mousePosWindow.y > 2 * squareSize) && (mousePosWindow.y < windowHeight);
  sf::Vector2f crossPos{
    getFigurePos(squareSize,
                 inLeftPart, inMidXPart, inRightPart,
                 inUpPart, inMidYPart, inLowerPart)
  };
  if (crossPos.x != -1.f && crossPos.y != -1.f)
  {
    Cross *pcross = new Cross(crossPos, squareSize / 2.f, crossColor, 10.f);
    pcross->draw(window_);
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
