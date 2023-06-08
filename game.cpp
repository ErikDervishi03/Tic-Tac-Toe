#include <valarray>
#include <random>
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
  void drawLines(sf::RenderWindow *window, const float squareSize,
                 const float windowWidth, const float windowHeight,
                 const float vertThickness, const float horizThickness,
                 sf::Color lineColor)
  {
    std::vector< Line > verticalLines;
    std::vector< Line > horizontalLines;
    const int numVerticalLines = static_cast< int >(windowWidth / squareSize) - 1;
    const int numHorizontalLines = static_cast< int >(windowHeight / squareSize) - 1;
    for (int i = 1; i <= numVerticalLines; ++i)
    {
      float x = static_cast<float>(i) * squareSize;
      sf::Vector2f startPointX{x - vertThickness / 2.f, 0.f};
      sf::Vector2f endPointX{x - vertThickness / 2.f, windowHeight};
      verticalLines.emplace_back(startPointX, endPointX);
    }
    for (int i = 1; i <= numHorizontalLines; ++i)
    {
      float y = static_cast<float>(i) * squareSize;
      sf::Vector2f startPointY{0.f, y - horizThickness / 2.f};
      sf::Vector2f endPointY{windowWidth, y - horizThickness / 2.f};
      horizontalLines.emplace_back(startPointY, endPointY);
    }
    for (const auto &line: verticalLines)
    {
      line.drawLine(window, lineColor, vertThickness);
    }
    for (const auto &line: horizontalLines)
    {
      line.drawLine(window, lineColor, horizThickness);
    }
  }
  void drawFigures(sf::RenderWindow *window_,
                   const float squareSize, const float figureSize, const float windowWidth, const float windowHeight,
                   const sf::Vector2f mousePosWindow,
                   const sf::Color crossColor)
  {
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
      Cross *pCross = new Cross(crossPos, static_cast< size_t >(figureSize / 2.f), crossColor, 10.f);
      pCross->draw(window_);
    }
  }
  sf::Color generateRandomColor()
  {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution< double > dist(100, 255);
    int red = static_cast<int>(dist(mt));
    int blue = static_cast<int>(dist(mt));
    int green = static_cast<int>(dist(mt));
    sf::Color color(red, green, blue);
    return color;
  }
}
Game::Game(sf::VideoMode videoMode, const std::string &title):
  videoMode_(videoMode),
  ev_(),
  elapsedTime_(0)
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
  const sf::Color crossColor = sf::Color::Red/*generateRandomColor()*/;
  const float windowWidth = static_cast<float>(windowSize.x);
  const float windowHeight = static_cast<float>(windowSize.y);
  const float vertThickness = 5.f;
  const float horizThickness = 5.f;
  const float squareSize = windowWidth * (1.0f / 3.0f);
  sf::Vector2f mousePosWindow = getMousePosition();
  drawLines(window_, squareSize, windowWidth, windowHeight, vertThickness, horizThickness, lineColor);
  float period = 3;
  const float figureSize = squareSize - static_cast< float >(0.1f * squareSize * sin(elapsedTime_ * period));
  drawFigures(window_, squareSize, figureSize, windowWidth, windowHeight, mousePosWindow, crossColor);
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
void Game::update(sf::Clock clock)
{
  elapsedTime_ = clock.restart().asSeconds();
  pollEvents();
}
void Game::render()
{
  window_->clear(sf::Color::Yellow);
  drawField();
  window_->display();
}
