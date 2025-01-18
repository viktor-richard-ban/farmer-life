#pragma once

#include <SFML/Graphics.hpp>

namespace Texture
{
    enum TextureType
    {
        GRASS,
        GRASS_BUBBLE,
        HUMAN,
        WATER_BARREL,
        TREE,
        EMPTY
    };

    struct TileInfo
    {
        sf::Texture* tileset;
        sf::IntRect tileRect;
        float scale;
    };

    class TextureManager
    {
    public:
        TextureManager();
        ~TextureManager();

        TileInfo tileInfo(TextureType type);

    private:
        sf::Texture* tileset;
        sf::Texture* character;
        sf::Texture* empty;
    };
}