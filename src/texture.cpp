#include "texture.hpp"

namespace Texture
{
    TextureManager::TextureManager()
    {
        tileset = new sf::Texture();
        auto successfull = tileset->loadFromFile("assets/tileset.png");

        character = new sf::Texture();
        successfull = character->loadFromFile("assets/human.png");

        empty = new sf::Texture();
        successfull = empty->loadFromFile("assets/empty.png");
    }

    sf::Sprite* TextureManager::sprite(TextureType type)
    {
        sf::IntRect tileRect;

        switch (type) {
            case GRASS:
                tileRect = sf::IntRect({2 * 16, 1 * 16}, {16, 16});
                return new sf::Sprite(*tileset, tileRect);
            case GRASS_BUBBLE:
                tileRect = sf::IntRect({2 * 16, 2 * 16}, {16, 16});
                return new sf::Sprite(*tileset, tileRect);
            case HUMAN:
                return new sf::Sprite(*character);
            case EMPTY:
                return new sf::Sprite(*empty);
        }
    }
}