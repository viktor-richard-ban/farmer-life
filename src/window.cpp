#include <SFML/Graphics.hpp>
#include "window.hpp"
#include<iostream>

Window::Window(const std::string& title, const sf::Vector2u& size): window(sf::VideoMode({1360, 800}), "SFML window")
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

sf::View mainView(sf::FloatRect({0.f, 0.f}, {300.f, 300.f}));

void Window::beginDraw()
{
    window.clear();

    window.setView(mainView);
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

        if (event->is<sf::Event::KeyPressed>() &&
            event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::A)
        {
            mainView.move({-5,0});
        }

        if (event->is<sf::Event::KeyPressed>() &&
            event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::D)
        {
            mainView.move({5,0});
        }

        if (event->is<sf::Event::KeyPressed>() &&
            event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::W)
        {
            mainView.move({0,-5});
        }

        if (event->is<sf::Event::KeyPressed>() &&
            event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::S)
        {
            mainView.move({0,5});
        }
    }
}