#include <algorithm>
#include <iostream>
#include "renderer.h"

Renderable::~Renderable() {}

Renderer::Renderer(Window& window) : window(window) {}

void Renderer::addObject(Renderable* object)
{
    objects.push_back(object);
}

void Renderer::render()
{
    std::sort(objects.begin(), objects.end(), [](Renderable* a, Renderable* b) {
        std::optional<sf::FloatRect> intersection = a->rect.findIntersection(b->rect);
        if (intersection.has_value()) {
            a->opacity = 0.5;
        }
        return (a->rect.position.y + a->rect.size.y) < (b->rect.position.y + b->rect.size.y);
    });

    for (Renderable* object : objects)
    {
        object->render(window);
    }
}