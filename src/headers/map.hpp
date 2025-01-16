#include "texture.hpp"
#include "window.hpp"
#include <vector>

#ifndef MAP_HPP
#define MAP_HPP

class Map {
public:
    Map(Texture::TextureManager* textureManager);

    void draw(Window* window);
#endif

private:
    Texture::TextureManager* textureManager;
    std::vector<std::vector<int>> map;

    Texture::TextureType getTextureById(int id);
};