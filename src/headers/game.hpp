#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include "window.hpp"
#include "texture.hpp"
#include "map.hpp"
#include "character.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game{
public:
    Game();
    ~Game();

    Window* getWindow();
    void restartClock();
    void update();
    void render();
#endif

private:
    sf::Clock clock;
    sf::Time elapsedTime;
    float fps;

    Window* window;
    sf::View* mainCamera;

    Texture::TextureManager* textureManager;
    Map map;
    Character player;

    void renderFPSCounter();
};