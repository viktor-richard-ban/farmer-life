#include <SFML/Graphics.hpp>
#include <map>

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

namespace Texture
{
    enum TextureType
    {
        EMPTY
    };

    class TextureManager
    {
    public:
        TextureManager();

        sf::Texture* getTexture(TextureType type);

    private:
        std::map<TextureType, sf::Texture*> textures;

        void loadTextures();
    };
}

#endif