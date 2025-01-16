#include <SFML/Graphics.hpp>
#include "map.hpp"
#include <iostream>

Map::Map(Texture::TextureManager* textureManager)
{
    this->textureManager = textureManager;

    map = {
        {0,0,0,0,0,0,0,0,1,0,0},
        {0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1},
        {0,1,0,0,0,0,1,0,0,0,0},
    };
}

void Map::draw(Window* window)
{
    for (int y = 0; y < map.size(); y++) {
        for (int x = 0; x < map[y].size(); x++) {
            Texture::TextureType texture = getTextureById(map[y][x]);

            // store them not to render each time we refresh the screen
            sf::Sprite* tile = textureManager->sprite(texture);  // FIXME: memory leak
            tile->setPosition({(float)x * 16 * 3, (float)y * 16 * 3});
            tile->setScale({3,3});
            window->draw(*tile);
        }
    }
}

Texture::TextureType Map::getTextureById(int id)
{
    switch (id)
    {
        case 0:
        return Texture::GRASS;
        case 1:
        return Texture::GRASS_BUBBLE;
    }

    return Texture::EMPTY;
}