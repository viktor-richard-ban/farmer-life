#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include "texture.hpp"
#include "window.hpp"

#ifndef character_HPP
#define character_HPP

class Character {
public:
    Character(Texture::TextureManager& textureManager);
    ~Character();

    sf::Vector2f position;
    sf::Vector2u size;

    void draw(Window& window);
    void handleEvents(sf::Time elapsedTime);

private:
    Texture::TextureManager& textureManager;
    sf::Sprite* tile;

    float speed;
};

#endif