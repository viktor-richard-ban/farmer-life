#include <SFML/Graphics.hpp>
#include "game.hpp"

int main()
{
    Game game;
    while (game.getWindow()->isOpen())
    {
        game.update();
        game.render();
    }
}
