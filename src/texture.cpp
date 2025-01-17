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

    TextureManager::~TextureManager()
    {
        delete tileset;
        delete character;
        delete empty;
    }

    TileInfo TextureManager::tileInfo(TextureType type)
    {
        Texture::TileInfo tileInfo;
        tileInfo.scale = 3;

        switch (type) {
            case GRASS:
                tileInfo.tileset = tileset;
                tileInfo.tileRect = sf::IntRect({2 * 16, 1 * 16}, {16, 16});
                return tileInfo;
            case GRASS_BUBBLE:
                tileInfo.tileset = tileset;
                tileInfo.tileRect = sf::IntRect({2 * 16, 2 * 16}, {16, 16});
                return tileInfo;
            case HUMAN:
                tileInfo.tileset = character;
                tileInfo.tileRect = sf::IntRect({0, 0}, {11, 15});
                return tileInfo;
            default:
                tileInfo.tileset = empty;
                tileInfo.tileRect = sf::IntRect({0, 0}, {16, 16});
                return tileInfo;
        }
    }
}