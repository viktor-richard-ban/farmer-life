#include <SFML/Graphics.hpp>
#include "game.hpp"

Game::Game(): window("Farming life", sf::Vector2u(800,600)) {}

Window* Game::getWindow() 
{
    return &window;
}

void Game::update()
{
    window.update();
}

void Game::render()
{
    window.beginDraw();

    sf::Texture texture;
    auto x = texture.loadFromFile("Assets/empty.png");

    sf::Sprite empty(texture);

    sf::Vector2u size = texture.getSize();
    empty.setOrigin({(float)(size.x / 2), (float)(size.y / 2)});
    window.draw(empty);

    window.endDraw();
}