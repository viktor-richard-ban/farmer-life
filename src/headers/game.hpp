#include "window.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game{
public:
    Game();

    Window* getWindow();
    void handleInput();
    void update();
    void render();
#endif

private:
    Window window;
};