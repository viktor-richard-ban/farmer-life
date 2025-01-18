#include "renderer.h"

Renderable::~Renderable() {}

Renderer::Renderer(Window& window) : window(window) {}

void Renderer::addObject(Renderable* object)
{
    objects.push_back(object);
}

void Renderer::render()
{
    for (Renderable* object : objects)
    {
        object->render(window);
    }
}