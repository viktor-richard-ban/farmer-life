#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.hpp"

Map::Map(Texture::TextureManager* textureManager)
{
    this->textureManager = textureManager;
}

void Map::draw(Window* window)
{
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            // store them not to render each time we refresh the screen
            sf::Sprite* tile = textureManager->sprite(Texture::GRASS);  // FIXME: memory leak
            tile->setPosition({(float)x * 16 * 3, (float)y * 16 * 3});
            tile->setScale({3,3});
            window->draw(*tile);
        }
    }
}