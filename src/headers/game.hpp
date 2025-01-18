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
        position = {50, 50};
        tile->setPosition(position);
        size = {tileInfo.tileRect.size.x * (uint)tileInfo.scale, tileInfo.tileRect.size.y * (uint)tileInfo.scale};
    }

    void render(Window& window) {
        window.draw(*tile);

        /*           Only for testing purpose           */
        sf::RectangleShape frame;
        frame.setSize({(float)size.x, (float)size.y});
        frame.setPosition({position.x, position.y});
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
        position = {200,73};
        tile->setPosition(position);
        size = {tileInfo.tileRect.size.x * (uint)tileInfo.scale, tileInfo.tileRect.size.y * (uint)tileInfo.scale};
    }

    void render(Window& window) {
        window.draw(*tile);

        /*           Only for testing purpose           */
        sf::RectangleShape frame;
        frame.setSize({(float)size.x, (float)size.y});
        frame.setPosition({position.x, position.y});
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