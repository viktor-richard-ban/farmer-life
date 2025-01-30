#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <unordered_set>

class EventListener
{
public:
    virtual void onKeyPressed(sf::Event& event) = 0;
    virtual void onKeyReleased(sf::Event& event) = 0;
};

class EventManager
{
public:
    sf::Time elapsedTime;

    void subscribe(EventListener* listener);
    void removeSubscription(EventListener* listener);

    void handle(sf::Event& event);

private:
    std::unordered_set<EventListener*> listeners;
};