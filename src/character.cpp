#include <SFML/Graphics.hpp>
#include "character.hpp"

Character::Character(Texture::TextureManager& textureManager, EventManager* eventManager) : textureManager(textureManager), eventManager(eventManager)
{
    speed = 200;

    Texture::TileInfo tileInfo = textureManager.tileInfo(Texture::HUMAN);
    tile = new sf::Sprite(*tileInfo.tileset, tileInfo.tileRect);
    tile->setScale({tileInfo.scale, tileInfo.scale});

    rect = sf::FloatRect({0 ,0}, {(float)tileInfo.tileRect.size.x * (float)tileInfo.scale, (float)tileInfo.tileRect.size.y * (float)tileInfo.scale});

    eventManager->subscribe(this);
}

Character::~Character()
{
    eventManager->removeSubscription(this);
    delete tile;
}

void Character::render(Window& window)
{
    move();
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

void Character::onKeyPressed(sf::Event& event)
{
    if (event.getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::W)
    {
        movingDirections.insert(MovingDirection::UP);
    }
    if (event.getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::A)
    {
        movingDirections.insert(MovingDirection::LEFT);
    }
    if (event.getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::S)
    {
        movingDirections.insert(MovingDirection::DOWN);
    }
    if (event.getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::D)
    {
        movingDirections.insert(MovingDirection::RIGHT);
    }
}

void Character::onKeyReleased(sf::Event& event)
{
    if (event.getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::W)
    {
        movingDirections.erase(MovingDirection::UP);
    }
    if (event.getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::A)
    {
        movingDirections.erase(MovingDirection::LEFT);
    }
    if (event.getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::S)
    {
        movingDirections.erase(MovingDirection::DOWN);
    }
    if (event.getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::D)
    {
        movingDirections.erase(MovingDirection::RIGHT);
    }
}

void Character::move()
{
    float diff = speed * eventManager->elapsedTime.asSeconds();

    if (movingDirections.contains(MovingDirection::UP))
    {
        rect.position.y -= diff;
    }
    if (movingDirections.contains(MovingDirection::DOWN))
    {
        rect.position.y += diff;
    }
    if (movingDirections.contains(MovingDirection::RIGHT))
    {
        rect.position.x += diff;
    }
    if (movingDirections.contains(MovingDirection::LEFT))
    {
        rect.position.x -= diff;
    }

    tile->setPosition({rect.position});   
}