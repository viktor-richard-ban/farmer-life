#include <SFML/Graphics.hpp>
#include <map>

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

namespace Texture
{
    enum TextureType
    {
        GRASS
    };

    class TextureManager
    {
    public:
        TextureManager();

        sf::Sprite* sprite(TextureType type);

    private:
        sf::Texture* tileset;
    };
}

#endif