#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "texture.hpp"
#include <iostream>

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
 
    for (sf::Sprite* sprite : tiles) {
        delete sprite;
        sprite = nullptr;
    }
    tiles.clear();
    drawMap();

    window.endDraw();
}

void Game::drawMap()
{
   for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            sf::Sprite* tile = textureManager.sprite(Texture::GRASS);
            tile->setOrigin({(float)x * 16, (float)y * 16});
            tiles.push_back(tile);

            window.draw(*tile);
        }
    }
}