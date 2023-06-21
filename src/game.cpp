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
  sf::Vector2f getFigurePos(float squareSize, const std::vector< bool > &figurePosScheme)
  {
    const float halfSize = squareSize / 2.f;
    const float threeHalfSize = squareSize * 3.f / 2.f;
    const float fiveHalfSize = squareSize * 5.f / 2.f;
    bool inLeftPart = figurePosScheme[0];
    bool inMidXPart = figurePosScheme[1];
    bool inRightPart = figurePosScheme[2];
    bool inUpPart = figurePosScheme[3];
    bool inMidYPart = figurePosScheme[4];
    bool inLowerPart = figurePosScheme[5];
    float x = inLeftPart ? halfSize : (inMidXPart ? threeHalfSize : (inRightPart ? fiveHalfSize : -1.f));
    float y = inUpPart ? halfSize : (inMidYPart ? threeHalfSize : (inLowerPart ? fiveHalfSize : -1.f));
    return {x, y};
  }
  void drawLines(sf::RenderWindow *window, const FieldDTO &dto)
  {
    const float squareSize = dto.windowWidth * (1.0f / 3.0f);
    std::vector< Line > verticalLines;
    std::vector< Line > horizontalLines;
    const int numVerticalLines = static_cast< int >(dto.windowWidth / squareSize) - 1;
    const int numHorizontalLines = static_cast< int >(dto.windowHeight / squareSize) - 1;
    for (int i = 1; i <= numVerticalLines; ++i)
    {
      float x = static_cast< float >(i) * squareSize;
      sf::Vector2f startPointX{x - dto.vertThickness / 2.f, 0.f};
      sf::Vector2f endPointX{x - dto.vertThickness / 2.f, dto.windowHeight};
      verticalLines.emplace_back(startPointX, endPointX);
    }
    for (int i = 1; i <= numHorizontalLines; ++i)
    {
      float y = static_cast< float >(i) * squareSize;
      sf::Vector2f startPointY{0.f, y - dto.horizThickness / 2.f};
      sf::Vector2f endPointY{dto.windowWidth, y - dto.horizThickness / 2.f};
      horizontalLines.emplace_back(startPointY, endPointY);
    }
    for (const auto &line: verticalLines)
    {
      line.drawLine(window, dto.lineColor, dto.vertThickness);
    }
    for (const auto &line: horizontalLines)
    {
      line.drawLine(window, dto.lineColor, dto.horizThickness);
    }
  }
  void drawFigures(sf::RenderWindow *window, const FieldDTO &dto, const sf::Vector2f mousePosWindow, double elapsedTime)
  {
    const float squareSize = dto.windowWidth * (1.0f / 3.0f);
    float indent = squareSize / 15.f;
    bool inLeftPart = (mousePosWindow.x > indent) && (mousePosWindow.x < squareSize - indent);
    bool inMidXPart = (mousePosWindow.x > squareSize + indent) && (mousePosWindow.x < 2 * squareSize - indent);
    bool inRightPart = (mousePosWindow.x > 2 * squareSize + indent) && (mousePosWindow.x < dto.windowWidth - indent);
    bool inUpPart = (mousePosWindow.y > indent) && (mousePosWindow.y < squareSize - indent);
    bool inMidYPart = (mousePosWindow.y > squareSize + indent) && (mousePosWindow.y < 2 * squareSize - indent);
    bool inLowerPart = (mousePosWindow.y > 2 * squareSize + indent) && (mousePosWindow.y < dto.windowHeight - indent);
    std::vector< bool > figurePosScheme = {
      inLeftPart, inMidXPart, inRightPart,
      inUpPart, inMidYPart, inLowerPart
    };
    sf::Vector2f crossPos{getFigurePos(squareSize, figurePosScheme)};
    if (crossPos.x != -1.f && crossPos.y != -1.f)
    {
      const float figureSize = calcFigureSize(dto.windowWidth, elapsedTime, 3);
      Cross *pCross = new Cross(crossPos, static_cast< size_t >(figureSize / 2.f), dto.crossColor, 10.f);
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
