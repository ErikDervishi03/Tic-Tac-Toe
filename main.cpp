#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Hi Erik!");
  sf::Texture spriteTexture;
  if (!spriteTexture.loadFromFile("img/helllo.jpg"))
  {
    return EXIT_FAILURE;
  }
  sf::Font font;
  if (!font.loadFromFile("font/SketchyTimesBold.ttf"))
  {
    return EXIT_FAILURE;
  }
  sf::Sprite sprite(spriteTexture);
  sf::Text text("TickTacToe Game!", font, 50);
  sf::Music music;
  if (!music.openFromFile("music/fun.ogg"))
  {
    return EXIT_FAILURE;
  }
  music.play();
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }
    window.clear();
    window.draw(sprite);
    window.draw(text);
    window.display();
  }
  return EXIT_SUCCESS;
}
