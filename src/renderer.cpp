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
    std::sort(objects.begin(), objects.end(), [](const Renderable* a, const Renderable* b) {
        return (a->position.y + a->size.y) < (b->position.y + b->size.y);
    });

    for (Renderable* object : objects)
    {
        object->render(window);
    }
}