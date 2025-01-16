#include "character.hpp"

Character::Character()
{
    position = {0,0};
    size = {11,15};
    speed = 200;
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
}