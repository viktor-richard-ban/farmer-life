#include <SFML/Graphics.hpp>
#include "window.hpp"
#include<iostream>

sf::View* camera;

Window::Window(const std::string& title, const sf::Vector2u& size, EventManager* eventManager): window(sf::VideoMode({size.x, size.y}), title)
{
    this->eventManager = eventManager;
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
    while(std::optional<sf::Event> event = window.pollEvent()){
        // Close
        if (event->is<sf::Event::KeyPressed>())
        {
            if(event->is<sf::Event::Closed>() || event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape)
            {
                window.close();
            }
        }

        // Resize
        if (const auto* resized = event->getIf<sf::Event::Resized>())
        {
            camera->setSize(sf::Vector2f(resized->size));
        }

        if (const auto* scroll = event->getIf<sf::Event::MouseWheelScrolled>()) {
            if (scroll->wheel == sf::Mouse::Wheel::Vertical && scroll->delta != 1 && scroll->delta != 0) {
                if (scroll->delta > 0)
                {
                    camera->zoom(1.2);
                }
                else
                {
                    camera->zoom(0.8);
                }
            }
        }

        if (event.has_value())
        {
            eventManager->handle(event.value());
        }
    }
}

void Window::setCamera(sf::View* newCamera)
{
    camera = newCamera;
}