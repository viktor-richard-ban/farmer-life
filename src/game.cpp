#include "game.hpp"
#include <format>
#include <iostream>

#define WIDTH 1024
#define HEIGHT 768 

Game::Game(): textureManager(new Texture::TextureManager()), 
mainCamera(new sf::View(sf::FloatRect({-150.f, -150.f}, {WIDTH, HEIGHT}))),
map(*textureManager), player(*textureManager), window(new Window("Farmer life", sf::Vector2u(WIDTH, HEIGHT))), renderer(*window), barrel(*textureManager), tree(*textureManager)
{
    window->setCamera(mainCamera);
    renderer.addObject(&player);
    renderer.addObject(&barrel);
    renderer.addObject(&tree);
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
    mainCamera->setCenter({player.rect.position.x - (player.rect.size.x / 2), player.rect.position.y - (player.rect.size.y / 2)});
 
    /*      Start render    */
    map.draw(*window);
    renderer.render();

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