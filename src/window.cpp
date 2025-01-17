#include <SFML/Graphics.hpp>
#include "window.hpp"
#include<iostream>

sf::View* camera;

Window::Window(const std::string& title, const sf::Vector2u& size): window(sf::VideoMode({size.x, size.y}), title)
{
    std::cout << "Window has been constructed with title: " << title << std::endl;
}

Window::~Window()
{
    window.close();
}

bool Window::isOpen()
{
    return window.isOpen();
}

void Window::beginDraw()
{
    window.clear();
    window.setView(*camera);
}

void Window::draw(sf::Drawable& drawable)
{
    window.draw(drawable);
}

void Window::endDraw()
{
    window.display();
}

void Window::update()
{
    while(const std::optional event = window.pollEvent()){
        if(event->is<sf::Event::Closed>() ||
            (event->is<sf::Event::KeyPressed>() &&
                event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape))
        {
            window.close();
        }

        if (const auto* resized = event->getIf<sf::Event::Resized>())
        {
            camera->setSize(sf::Vector2f(resized->size));
        }
    }
}

void Window::setCamera(sf::View* newCamera)
{
    camera = newCamera;
}