#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_set>
#include "texture.hpp"
#include "window.hpp"
#include "renderer.h"

#ifndef character_HPP
#define character_HPP

enum MovingDirection {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

class Character: public Renderable, public EventListener {
public:
    Character(Texture::TextureManager& textureManager, EventManager* eventManager);
    ~Character();

    void render(Window& window) override;
    void handleEvents(sf::Time elapsedTime); 

    void onKeyPressed(sf::Event& event) override;
    void onKeyReleased(sf::Event& event) override;

private:
    Texture::TextureManager& textureManager;
    EventManager* eventManager;
    sf::Sprite* tile;

    float speed;
    std::unordered_set<MovingDirection> movingDirections;

    void move();
};

#endif