#include "texture.hpp"
#include "iostream"

namespace Texture
{
    TextureManager::TextureManager()
    {
        loadTextures();
    }

    sf::Texture* TextureManager::getTexture(Texture::TextureType type)
    {
        if (textures.find(type) != textures.end())
        {
            return textures[type];
        }
        std::cout << "Texture not found with id: " << type << std::endl;
        return nullptr;
    }

    void TextureManager::loadTextures()
    {
        sf::Texture* texture;
        auto successfull =texture->loadFromFile("Assets/empty.png");
        textures[EMPTY] = texture;
    }
}