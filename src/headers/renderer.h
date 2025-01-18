#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "window.hpp"

class Renderable
{
public:
    virtual ~Renderable();

    sf::Vector2f position;
    sf::Vector2u size;

    virtual void render(Window& window) = 0;
};

class Renderer
{
public:
    Renderer(Window& window);

    void addObject(Renderable* object);
    void render();

private:
    Window& window;
    std::vector<Renderable*> objects;
};