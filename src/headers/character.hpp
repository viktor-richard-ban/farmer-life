#include <SFML/Graphics.hpp>

#ifndef character_HPP
#define character_HPP

class Character {
public:
    Character();

    sf::Vector2f position;
    sf::Vector2u size;

    float speed;

    void handleEvents(sf::Time elapsedTime);
};

#endif