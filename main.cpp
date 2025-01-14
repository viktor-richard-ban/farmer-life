#include <SFML/Graphics.hpp>
#include "game.hpp"
#include <iostream>
int main()
{
    Game game;
    while (game.getWindow()->isOpen())
    {
        game.update();
        game.render();
        game.restartClock();
    }
}
