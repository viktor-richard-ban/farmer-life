#include "texture.hpp"

namespace Texture
{
    TextureManager::TextureManager()
    {
        tileset = new sf::Texture();
        auto successfull = tileset->loadFromFile("assets/tileset.png");

        character = new sf::Texture();
        successfull = character->loadFromFile("assets/human.png");
    }

    sf::Sprite* TextureManager::sprite(TextureType type)
    {
        sf::IntRect tileRect;

        switch (type) {
            case GRASS:
                tileRect = sf::IntRect({2 * 16, 2 * 16}, {16, 16});
                return new sf::Sprite(*tileset, tileRect);
            case HUMAN:
                tileRect = sf::IntRect({0, 0}, {11, 15});
                return new sf::Sprite(*character, tileRect);
        }
    }
}