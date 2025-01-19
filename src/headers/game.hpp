#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include "window.hpp"
#include "texture.hpp"
#include "map.hpp"
#include "character.hpp"
#include "renderer.h"

#ifndef GAME_HPP
#define GAME_HPP

class Barrel : public Renderable {
public:
    Barrel(Texture::TextureManager& textureManager) : textureManager(textureManager) {
        Texture::TileInfo tileInfo = textureManager.tileInfo(Texture::WATER_BARREL);
        tile = new sf::Sprite(*tileInfo.tileset, tileInfo.tileRect);
        tile->setScale({tileInfo.scale, tileInfo.scale});
        rect = sf::FloatRect({50 ,50}, {tileInfo.tileRect.size.x * (float)tileInfo.scale, tileInfo.tileRect.size.y * (float)tileInfo.scale});
        tile->setPosition({(float)rect.position.x, (float)rect.position.y});
    }

    void render(Window& window) {
        tile->setColor(sf::Color(255, 255, 255, 255 * opacity));
        window.draw(*tile);
        opacity = 1;

        /*           Only for testing purpose           */
        sf::RectangleShape frame;
        frame.setSize({rect.size.x, rect.size.y});
        frame.setPosition({rect.position.x, rect.position.y});
        frame.setOutlineThickness(2);
        frame.setOutlineColor(sf::Color::Red);
        frame.setFillColor(sf::Color::Transparent);
        window.draw(frame);
    }

private:
    Texture::TextureManager& textureManager;
    sf::Sprite* tile;
};

class Tree : public Renderable {
public:
    Tree(Texture::TextureManager& textureManager) : textureManager(textureManager) {
        Texture::TileInfo tileInfo = textureManager.tileInfo(Texture::TREE);
        tile = new sf::Sprite(*tileInfo.tileset, tileInfo.tileRect);
        tile->setScale({tileInfo.scale, tileInfo.scale});
        rect = sf::FloatRect({200,73}, {tileInfo.tileRect.size.x * (float)tileInfo.scale, tileInfo.tileRect.size.y * (float)tileInfo.scale});
        tile->setPosition({rect.position.x, rect.position.y});
    }

    void render(Window& window) {
        tile->setColor(sf::Color(255, 255, 255, 255 * opacity));
        window.draw(*tile);
        opacity = 1;

        /*           Only for testing purpose           */
        sf::RectangleShape frame;
        frame.setSize({rect.size.x, rect.size.y});
        frame.setPosition({rect.position.x, rect.position.y});
        frame.setOutlineThickness(2);
        frame.setOutlineColor(sf::Color::Red);
        frame.setFillColor(sf::Color::Transparent);
        window.draw(frame);
    }

private:
    Texture::TextureManager& textureManager;
    sf::Sprite* tile;
};

class Game{
public:
    Game();
    ~Game();

    Window* getWindow();
    void restartClock();
    void update();
    void render();
#endif

private:
    sf::Clock clock;
    sf::Time elapsedTime;
    float fps;

    Window* window;
    sf::View* mainCamera;

    Texture::TextureManager* textureManager;
    Map map;
    Character player;
    Barrel barrel;
    Tree tree;
    Renderer renderer;

    void renderFPSCounter();
};