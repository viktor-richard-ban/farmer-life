#include <SFML/Graphics.hpp>
#include "character.hpp"

Character::Character(Texture::TextureManager& textureManager) : textureManager(textureManager)
{
    position = {0,0};
    size = {11,15};
    speed = 200;

    Texture::TileInfo tileInfo = textureManager.tileInfo(Texture::HUMAN);
    tile = new sf::Sprite(*tileInfo.tileset, tileInfo.tileRect);
    tile->setScale({tileInfo.scale, tileInfo.scale});
}

Character::~Character()
{
    delete tile;
}

void Character::render(Window& window)
{
    window.draw(*tile);

    /*           Only for testing purpose           */
    sf::RectangleShape frame;
    frame.setSize({(float)size.x, (float)size.y});
    frame.setPosition({position.x, position.y});
    frame.setScale(tile->getScale());
    frame.setOutlineThickness(0.5);
    frame.setOutlineColor(sf::Color::Blue);
    frame.setFillColor(sf::Color::Transparent);
    window.draw(frame);
}

void Character::handleEvents(sf::Time elapsedTime)
{
    float diff = speed * elapsedTime.asSeconds();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        position.y -= diff;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        position.x -= diff;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        position.y += diff;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        position.x += diff;
    }

     tile->setPosition({position});
}