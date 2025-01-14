#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
#include "window.hpp"
#include "texture.hpp"

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

    Window window;
    Texture::TextureManager textureManager;
    std::vector<sf::Sprite*> tiles;

    void drawMap();
    void drawCharacter();
    void renderFPSCounter();
};