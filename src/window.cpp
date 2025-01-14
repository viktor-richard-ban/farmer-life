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

        if (event->is<sf::Event::KeyPressed>())
        {
            if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::A)
            {
                camera->move({-8,0});
            }

            if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::D)
            {
                camera->move({8,0});
            }

            if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::W)
            {
                camera->move({0,-8});
            }

            if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::S)
            {
                camera->move({0,8});
            }
        }
    }
}

void Window::setCamera(sf::View* newCamera)
{
    camera = newCamera;
}