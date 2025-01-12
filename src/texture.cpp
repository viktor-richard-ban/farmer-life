#include "texture.hpp"

namespace Texture
{
    TextureManager::TextureManager()
    {
        tileset = new sf::Texture();
        auto successfull = tileset->loadFromFile("Assets/tileset.png");
    }

    sf::Sprite* TextureManager::sprite(TextureType type)
    {
        sf::IntRect tileRect;

        switch (type) {
            case GRASS:
                tileRect = sf::IntRect({2 * 16, 2 * 16}, {16, 16});
                break;
        }
        
        return new sf::Sprite(*tileset, tileRect);
    }
}