#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "texture.hpp"
#include <iostream>

sf::View* mainCamera = new sf::View(sf::FloatRect({-150.f, -150.f}, {200.f, 200.f}));

Game::Game(): window("Farmer life", sf::Vector2u(800,800)), textureManager()
{
    window.setCamera(mainCamera);
}

Game::~Game()
{
    delete mainCamera;
}

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
 
    for (sf::Sprite* sprite : tiles) {
        delete sprite;
        sprite = nullptr;
    }
    tiles.clear();

    drawMap();
    drawCharacter();

    window.endDraw();
}

void Game::drawMap()
{
   for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            sf::Sprite* tile = textureManager.sprite(Texture::GRASS);
            tile->setOrigin({(float)x * 16, (float)y * 16});
            tiles.push_back(tile);

            window.draw(*tile);
        }
    }
}

void Game::drawCharacter()
{
    int width = 11;
    int height = 15;

    float x = mainCamera->getCenter().x - width / 2;
    float y = mainCamera->getCenter().y - height / 2;

    sf::Sprite* tile = textureManager.sprite(Texture::HUMAN);
    tile->setPosition({x, y});

    tiles.push_back(tile);

    window.draw(*tile);
}