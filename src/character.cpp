#include <SFML/Graphics.hpp>
#include "character.hpp"

Character::Character(Texture::TextureManager& textureManager) : textureManager(textureManager)
{
    speed = 200;

    Texture::TileInfo tileInfo = textureManager.tileInfo(Texture::HUMAN);
    tile = new sf::Sprite(*tileInfo.tileset, tileInfo.tileRect);
    tile->setScale({tileInfo.scale, tileInfo.scale});

    rect = sf::FloatRect({0 ,0}, {(float)tileInfo.tileRect.size.x * (float)tileInfo.scale, (float)tileInfo.tileRect.size.y * (float)tileInfo.scale});
}

Character::~Character()
{
    delete tile;
}

void Character::render(Window& window)
{
    window.draw(*tile);

    #ifdef DEBUG
    /*           Only for testing purpose           */
    sf::RectangleShape frame;
    frame.setSize({rect.size.x, rect.size.y});
    frame.setPosition({rect.position.x, rect.position.y});
    frame.setOutlineThickness(2);
    frame.setOutlineColor(sf::Color::Blue);
    frame.setFillColor(sf::Color::Transparent);
    window.draw(frame);

    #endif
}

void Character::handleEvents(sf::Time elapsedTime)
{
    float diff = speed * elapsedTime.asSeconds();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        rect.position.y -= diff;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        rect.position.x -= diff;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        rect.position.y += diff;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        rect.position.x += diff;
    }

     tile->setPosition({rect.position});
}