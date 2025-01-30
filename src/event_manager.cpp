#include "event_manager.hpp"
#include <iostream>

void EventManager::subscribe(EventListener* listener)
{
    listeners.insert(listener);
}

void EventManager::removeSubscription(EventListener* listener)
{
    listeners.erase(listener);
}

void EventManager::handle(sf::Event& event)
{
    for (EventListener* listener : listeners)
    {
        if (event.is<sf::Event::KeyPressed>())
        {
            listener->onKeyPressed(event);
        }

        if (event.is<sf::Event::KeyReleased>())
        {
            listener->onKeyReleased(event);
        }
    }
}