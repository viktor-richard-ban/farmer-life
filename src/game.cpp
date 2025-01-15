#include "game.hpp"
#include <format>
#include <iostream>

sf::View* mainCamera = new sf::View(sf::FloatRect({-150.f, -150.f}, {800, 800}));
float scale = 3;
float fps = 0;

Game::Game(): textureManager(new Texture::TextureManager()), map(textureManager)
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
    return window;
}

void Game::update()
{
    window->update();
}

void Game::render()
{
    window->beginDraw();
 
    map.draw(window);
 
    drawCharacter();
    renderFPSCounter();

    window->endDraw();
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

    // create character object once not to create it each time we refresh the screen
    sf::Sprite* tile = textureManager->sprite(Texture::HUMAN);  // FIXME: memory leak
    tile->setPosition({x, y});
    tile->setScale({scale,scale});

    window->draw(*tile);
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