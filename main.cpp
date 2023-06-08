#include "game.cpp"
int main()
{
  Game game({600, 600}, "Tic-Tac-Toe");
  sf::Clock clock;
  while (game.running())
  {
    game.update(clock);
    game.render();
  }
  return 0;
}
