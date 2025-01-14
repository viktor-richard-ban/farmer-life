#include <SFML/Graphics.hpp>
#include <vector>
#include "window.hpp"
#include "texture.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game{
public:
    Game();
    ~Game();

    Window* getWindow();
    void handleInput();
    void update();
    void render();
#endif

private:
    Window window;
    Texture::TextureManager textureManager;
    std::vector<sf::Sprite*> tiles;

    void drawMap();
    void drawCharacter();
};