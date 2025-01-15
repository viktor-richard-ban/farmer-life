#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include "window.hpp"
#include "texture.hpp"
#include "map.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game{
public:
    Game();
    ~Game();

    sf::Time getElapsed();
    void restartClock();

    Window* getWindow();
    void handleInput();
    void update();
    void render();
#endif

private:
    sf::Clock clock;
    sf::Time elapsedTime;

    Window* window;
    Texture::TextureManager* textureManager;
    Map map;

    void drawCharacter();
    void renderFPSCounter();
};