#include "game.hpp"
#include "texture.hpp"
#include <format>
#include <iostream>

sf::View* mainCamera = new sf::View(sf::FloatRect({-150.f, -150.f}, {800, 800}));
float scale = 3;
float fps = 0;

Game::Game(): window("Farmer life", sf::Vector2u(800,800))
{
    window.setCamera(mainCamera);
}

Game::~Game()
{
    delete mainCamera;
}

sf::Time Game::getElapsed()
{
    return elapsedTime;
}

void Game::restartClock()
{
    elapsedTime = clock.restart();
    fps = 1.0f / elapsedTime.asSeconds();
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
    renderFPSCounter();

    window.endDraw();
}

void Game::drawMap()
{
   for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            sf::Sprite* tile = textureManager.sprite(Texture::GRASS);
            tile->setPosition({(float)x * 16 * scale, (float)y * 16 * scale});
            tiles.push_back(tile);
            tile->setScale({scale,scale});

            window.draw(*tile);
        }
    }
}

void Game::drawCharacter()
{
    float speed = 200.0;
    float diff = speed * elapsedTime.asSeconds();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        mainCamera->move({0,-diff});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        mainCamera->move({-diff,0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        mainCamera->move({0,diff});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        mainCamera->move({diff,0});
    }

    int width = 11;
    int height = 15;
    float x = mainCamera->getCenter().x - width / 2;
    float y = mainCamera->getCenter().y - height / 2;

    sf::Sprite* tile = textureManager.sprite(Texture::HUMAN);
    tile->setPosition({x, y});
    tile->setScale({scale,scale});

    tiles.push_back(tile);

    window.draw(*tile);
}

void Game::renderFPSCounter()
{
    const sf::Font font("fonts/Micro5-Regular.ttf");
    std::string formattedFPS = std::format("{:.1f}", fps);
    sf::Text text(font, formattedFPS + " FPS");
    text.setCharacterSize(30);

    float x = mainCamera->getCenter().x - (mainCamera->getSize().x / 2) + 5;
    float y = mainCamera->getCenter().y - (mainCamera->getSize().y / 2);


    text.setPosition({ x , y});
    window.draw(text);
}