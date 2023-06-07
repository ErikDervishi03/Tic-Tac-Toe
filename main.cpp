#include "game.cpp"
int main()
{
  Game game({600, 600}, "Tic-Tac-Toe");
  while (game.running())
  {
    game.update();
    game.render();
  }
  return 0;
}
