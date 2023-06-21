#include <valarray>
#include <random>
#include "game.h"
#include "dto/fielddto.h"
#include "cross.h"
#include "line.h"
namespace
{
  float calcFigureSize(float windowWidth, double elapsedTime, float period)
  {
    const float squareSize = windowWidth * (1.0f / 3.0f);
    return squareSize - static_cast< float >(0.1f * squareSize * sin(elapsedTime * period));
  }
  sf::Vector2f
  getFigurePos(float squareSize, sf::Vector2< float > mousePosWindow, float indent,
               float windowWidth, float windowHeight)
  {
    const float halfSize = squareSize / 2.f;
    const float threeHalfSize = squareSize * 3.f / 2.f;
    const float fiveHalfSize = squareSize * 5.f / 2.f;
    bool inLeftPart = (mousePosWindow.x > indent) && (mousePosWindow.x < squareSize - indent);
    bool inMidXPart = (mousePosWindow.x > squareSize + indent) && (mousePosWindow.x < 2 * squareSize - indent);
    bool inRightPart = (mousePosWindow.x > 2 * squareSize + indent) && (mousePosWindow.x < windowWidth - indent);
    bool inUpPart = (mousePosWindow.y > indent) && (mousePosWindow.y < squareSize - indent);
    bool inMidYPart = (mousePosWindow.y > squareSize + indent) && (mousePosWindow.y < 2 * squareSize - indent);
    bool inLowerPart = (mousePosWindow.y > 2 * squareSize + indent) && (mousePosWindow.y < windowHeight - indent);
    float x = inLeftPart ? halfSize : (inMidXPart ? threeHalfSize : (inRightPart ? fiveHalfSize : -1.f));
    float y = inUpPart ? halfSize : (inMidYPart ? threeHalfSize : (inLowerPart ? fiveHalfSize : -1.f));
    return {x, y};
  }
  void drawLines(sf::RenderWindow *window, const FieldDTO &dto)
  {
    const float squareSize = dto.winWidth * (1.0f / 3.0f);
    std::vector< Line > verticalLines;
    std::vector< Line > horizontalLines;
    const int numVerticalLines = static_cast< int >(dto.winWidth / squareSize) - 1;
    const int numHorizontalLines = static_cast< int >(dto.winHeight / squareSize) - 1;
    for (int i = 1; i <= numVerticalLines; ++i)
    {
      float x = static_cast< float >(i) * squareSize;
      sf::Vector2f startPointX{x - dto.vertThick / 2.f, 0.f};
      sf::Vector2f endPointX{x - dto.vertThick / 2.f, dto.winHeight};
      verticalLines.emplace_back(startPointX, endPointX);
    }
    for (int i = 1; i <= numHorizontalLines; ++i)
    {
      float y = static_cast< float >(i) * squareSize;
      sf::Vector2f startPointY{0.f, y - dto.horizThick / 2.f};
      sf::Vector2f endPointY{dto.winWidth, y - dto.horizThick / 2.f};
      horizontalLines.emplace_back(startPointY, endPointY);
    }
    for (const auto &line: verticalLines)
    {
      line.drawLine(window, dto.lineCol, dto.vertThick);
    }
    for (const auto &line: horizontalLines)
    {
      line.drawLine(window, dto.lineCol, dto.horizThick);
    }
  }
  void drawFigures(sf::RenderWindow *window, const FieldDTO &dto, const sf::Vector2f mousePosWindow, double elapsedTime)
  {
    const float squareSize = dto.winWidth * (1.0f / 3.0f);
    sf::Vector2f crossPos{getFigurePos(squareSize, mousePosWindow, squareSize / 15.f, dto.winWidth, dto.winHeight)};
    if (crossPos.x != -1.f && crossPos.y != -1.f)
    {
      const float figureSize = calcFigureSize(dto.winWidth, elapsedTime, 3);
      Cross *pCross = new Cross(crossPos, static_cast< size_t >(figureSize / 2.f), dto.crossCol, 10.f);
      pCross->draw(window);
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
  sf::VideoMode calcGameWindowSize()
  {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int dWidth = desktopMode.width;
    unsigned int dHeight = desktopMode.height;
    unsigned int wSize = static_cast<unsigned int>(sqrt(dWidth * dHeight) / 2);
    if (wSize == 0)
    {
      return {600, 600};
    }
    return {wSize, wSize};
  }
}
Game::Game(const std::string &title):
  videoMode_(calcGameWindowSize()),
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
  FieldDTO dto{
    sf::Color::Black, sf::Color::Red,
    static_cast< float >(windowSize.x), static_cast< float >(windowSize.y),
    5.f, 5.f
  };
  sf::Vector2f mousePosWindow = getMousePosition();
  drawLines(window_, dto);
  drawFigures(window_, dto, mousePosWindow, elapsedTime_);
}
void Game::pollEvents()
{
  while (window_->pollEvent(ev_))
  {
    if (ev_.type == sf::Event::Closed || (ev_.type == sf::Event::KeyPressed && ev_.key.code == sf::Keyboard::Escape))
    {
      window_->close();
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
