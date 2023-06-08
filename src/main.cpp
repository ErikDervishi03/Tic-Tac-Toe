#include "game.cpp"
int main()
{
  Game game("Tic-Tac-Toe: Erik Dervishi x FavorIT");
  sf::Clock clock;
  while (game.running())
  {
    game.update(clock);
    game.render();
  }
  return 0;
}
