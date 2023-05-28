#include <iostream>
#include "game.cpp"

int main()
{
  //init Game Engine

  Game game;
  //game loop

  while(game.running())
  {
      //update
      game.update();

      //Render
      game.render();

  }

  //end of application
  return 0;  
}
