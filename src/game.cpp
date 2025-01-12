#include <SFML/Graphics.hpp>
#include "game.hpp"

Game::Game(): window("Farmer life", sf::Vector2u(800,800)), textureManager() {}

Window* Game::getWindow() 
{
    return &window;
}

void Game::update()
{
    window.update();
}

void Game::render()
{
    window.beginDraw();
    drawMap();
    window.endDraw();
}

void Game::drawMap()
{
    sf::Texture* texture;
    texture = textureManager.getTexture(Texture::EMPTY);

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            sf::Sprite tile(*texture);
            tile.setOrigin({(float)x * 32, (float)y * 32});

            if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1)) {
                tile.setColor(sf::Color(0, 255, 0));
            }

            window.draw(tile);
        }
    }
}