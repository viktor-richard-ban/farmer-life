#include "game.hpp"
#include <format>
#include <iostream>

Game::Game(): textureManager(new Texture::TextureManager()), 
mainCamera(new sf::View(sf::FloatRect({-150.f, -150.f}, {800, 800}))), 
map(*textureManager), player(*textureManager)
{
    window = new Window("Farmer life", sf::Vector2u(800,800));
    window->setCamera(mainCamera);
}

Game::~Game()
{
    delete mainCamera;
    delete window;
    delete textureManager;
}

void Game::restartClock()
{
    elapsedTime = clock.restart();
    fps = 1.0f / elapsedTime.asSeconds();
}

Window* Game::getWindow() 
{
    return window;
}

void Game::update()
{
    window->update();
}

void Game::render()
{
    /*      Begin render    */
    window->beginDraw();
    player.handleEvents(elapsedTime);
 
    /*      Start render    */
    map.draw(*window);
    player.draw(*window);
    mainCamera->setCenter({player.position.x - (player.size.x / 2), player.position.y - (player.size.y / 2)});

    renderFPSCounter();

    /*      End render    */
    window->endDraw();
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
    window->draw(text);
}